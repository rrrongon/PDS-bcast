/* -*- Mode: C; c-basic-offset:4 ; -*- */
/* Copyright (c) 2001-2022, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH2 software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH2 directory.
 *
 */
/*
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "mpidimpl.h"

/* FIXME: Correct description of function */
/*@
   MPID_Comm_spawn_multiple - 

   Input Arguments:
+  int count - count
.  char *array_of_commands[] - commands
.  char* *array_of_argv[] - arguments
.  int array_of_maxprocs[] - maxprocs
.  MPI_Info array_of_info[] - infos
.  int root - root
-  MPI_Comm comm - communicator

   Output Arguments:
+  MPI_Comm *intercomm - intercommunicator
-  int array_of_errcodes[] - error codes

   Notes:

.N Errors
.N MPI_SUCCESS
@*/
#undef FUNCNAME
#define FUNCNAME MPID_Comm_spawn_multiple
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPID_Comm_spawn_multiple(int count, char *array_of_commands[],
			     char ** array_of_argv[], const int array_of_maxprocs[],
			     MPID_Info * array_of_info_ptrs[], int root, 
			     MPID_Comm * comm_ptr, MPID_Comm ** intercomm,
			     int array_of_errcodes[]) 
{
    int mpi_errno = MPI_SUCCESS;
    MPIDI_STATE_DECL(MPID_STATE_MPID_COMM_SPAWN_MULTIPLE);

    MPIDI_FUNC_ENTER(MPID_STATE_MPID_COMM_SPAWN_MULTIPLE);

    /* Check to make sure the communicator hasn't already been revoked */
    if (comm_ptr->revoked) {
        MPIR_ERR_SETANDJUMP(mpi_errno,MPIX_ERR_REVOKED,"**revoked");
    }

    /* We allow an empty implementation of this function to 
       simplify building MVAPICH2 on systems that have difficulty
       supporing process creation */
#   ifndef MPIDI_CH3_HAS_NO_DYNAMIC_PROCESS
    mpi_errno = MPIDI_Comm_spawn_multiple(count, array_of_commands, 
					  array_of_argv, array_of_maxprocs,
					  array_of_info_ptrs,
					  root, comm_ptr, intercomm, 
					  array_of_errcodes);
#   else
    MPIR_ERR_SET1(mpi_errno,MPI_ERR_OTHER, "**notimpl",
		  "**notimpl %s", FCNAME);
#   endif

#if CH3_RANK_BITS == 16
    if ((MPIR_Process.comm_world->local_size + count) > 32768 && !MPIR_Process.comm_world->rank) {
        mpi_errno = MPIR_Err_create_code(MPI_SUCCESS,
                MPI_ERR_OTHER, FCNAME, __LINE__, MPI_ERR_OTHER,
                "**nomem", "Job size is larger than 32768 (%d). Reconfigure the library with --with-ch3-rank-bits=32",
                (MPIR_Process.comm_world->local_size + count));
    }
#endif
    
fn_fail:
    MPIDI_FUNC_EXIT(MPID_STATE_MPID_COMM_SPAWN_MULTIPLE);
    return mpi_errno;
}
