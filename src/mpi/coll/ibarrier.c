/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *  (C) 2010 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "mpiimpl.h"
#include "coll_shmem.h"

/* -- Begin Profiling Symbol Block for routine MPI_Ibarrier */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Ibarrier = PMPI_Ibarrier
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Ibarrier  MPI_Ibarrier
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Ibarrier as PMPI_Ibarrier
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request) __attribute__((weak,alias("PMPI_Ibarrier")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Ibarrier
#define MPI_Ibarrier PMPI_Ibarrier

#if (defined(CHANNEL_MRAIL) || defined(CHANNEL_PSM)) && ENABLE_PVAR_MV2
#include "coll_shmem.h"
MPIR_T_PVAR_DOUBLE_TIMER_DECL_EXTERN(MV2, mv2_coll_timer_ibarrier_intra);
MPIR_T_PVAR_DOUBLE_TIMER_DECL_EXTERN(MV2, mv2_coll_timer_ibarrier_inter);

MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_intra);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_inter);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_intra_bytes_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_intra_bytes_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_intra_count_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_intra_count_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_inter_bytes_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_inter_bytes_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_inter_count_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_inter_count_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_bytes_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_bytes_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_count_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ibarrier_count_recv);

#define PVAR_TIME_START(optype, op, algo) \
        MPIR_TIMER_START(optype, op, algo); 

#define PVAR_TIME_STOP(optype, op, algo) \
        MPIR_TIMER_END(optype, op, algo);
    

#define PVAR_INC_1(M, alg, num) \
    MPIR_T_PVAR_COUNTER_INC(M, alg, num);

#define PVAR_INC_MSG(op, algo, sr, count, datatype) \
    MPIR_PVAR_INC(op, algo, sr, count, datatype);

#else
/* Idea of redefining macros to wrap around calls for portability reasons */
#define PVAR_TIME_START(optype, op, algo) 
#define PVAR_TIME_STOP(optype, op, algo) 
#define PVAR_INC_1(M, alg, num)   
#define PVAR_INC_MSG(op, algo, sr, count, datatype)

#endif


/* any non-MPI functions go here, especially non-static ones */

/* This is the default implementation of the barrier operation.  The
   algorithm is:

   Algorithm: MPI_Ibarrier

   We use the dissemination algorithm described in:
   Debra Hensgen, Raphael Finkel, and Udi Manber, "Two Algorithms for
   Barrier Synchronization," International Journal of Parallel
   Programming, 17(1):1-17, 1988.

   It uses ceiling(lgp) steps. In step k, 0 <= k <= (ceiling(lgp)-1),
   process i sends to process (i + 2^k) % p and receives from process
   (i - 2^k + p) % p.

   Possible improvements:

   End Algorithm: MPI_Ibarrier

   This is an intracommunicator barrier only!
*/
/* Provides a generic "flat" barrier that doesn't know anything about hierarchy.
 * It will choose between several different algorithms based on the given
 * parameters. */
#undef FUNCNAME
#define FUNCNAME MPIR_Ibarrier_intra
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Ibarrier_intra(MPID_Comm *comm_ptr, MPID_Sched_t s)
{
    PVAR_TIME_START(coll, ibarrier, intra);
    int mpi_errno = MPI_SUCCESS;
    int size, rank, src, dst, mask;

    MPIU_Assert(comm_ptr->comm_kind == MPID_INTRACOMM);
    PVAR_INC_1(MV2, mv2_coll_ibarrier_intra, 1);

    size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    /* Trivial barriers return immediately */
    if (size == 1) goto fn_exit;

    mask = 0x1;
    while (mask < size) {
        dst = (rank + mask) % size;
        src = (rank - mask + size) % size;

        mpi_errno = MPID_Sched_send(NULL, 0, MPI_BYTE, dst, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);

        mpi_errno = MPID_Sched_recv(NULL, 0, MPI_BYTE, src, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        PVAR_INC_MSG(ibarrier, intra, send, 0, MPI_BYTE);
        PVAR_INC_MSG(ibarrier, intra, recv, 0, MPI_BYTE);

        mpi_errno = MPID_Sched_barrier(s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);

        mask <<= 1;
    }

fn_exit:
    PVAR_TIME_STOP(coll, ibarrier, intra);
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

/* Provides a generic "flat" barrier that doesn't know anything about hierarchy.
 * It will choose between several different algorithms based on the given
 * parameters. */
#undef FUNCNAME
#define FUNCNAME MPIR_Ibarrier_inter
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Ibarrier_inter(MPID_Comm *comm_ptr, MPID_Sched_t s)
{
    PVAR_TIME_START(coll, ibarrier, inter);
    int mpi_errno = MPI_SUCCESS;
    int rank, root;
    MPIR_SCHED_CHKPMEM_DECL(1);
    char *buf = NULL;

    MPIU_Assert(comm_ptr->comm_kind == MPID_INTERCOMM);
    PVAR_INC_1(MV2, mv2_coll_ibarrier_inter, 1);

    rank = comm_ptr->rank;

    /* Get the local intracommunicator */
    if (!comm_ptr->local_comm) {
        mpi_errno = MPIR_Setup_intercomm_localcomm(comm_ptr);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    }

    /* do a barrier on the local intracommunicator */
    MPIU_Assert(comm_ptr->local_comm->coll_fns && comm_ptr->local_comm->coll_fns->Ibarrier_sched);
    if(comm_ptr->local_size != 1) {
        mpi_errno = comm_ptr->local_comm->coll_fns->Ibarrier_sched(comm_ptr->local_comm, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        MPID_SCHED_BARRIER(s);
    }
    /* rank 0 on each group does an intercommunicator broadcast to the
       remote group to indicate that all processes in the local group
       have reached the barrier. We do a 1-byte bcast because a 0-byte
       bcast will just return without doing anything. */

    MPIR_SCHED_CHKPMEM_MALLOC(buf, char *, 1, mpi_errno, "bcast buf");
    buf[0] = 'D'; /* avoid valgrind warnings */

    /* first broadcast from left to right group, then from right to
       left group */
    MPIU_Assert(comm_ptr->coll_fns && comm_ptr->coll_fns->Ibcast_sched);
    if (comm_ptr->is_low_group) {
        root = (rank == 0) ? MPI_ROOT : MPI_PROC_NULL;
        mpi_errno = comm_ptr->coll_fns->Ibcast_sched(buf, 1, MPI_BYTE, root, comm_ptr, s);
        PVAR_INC_MSG(ibarrier, inter, send, 1, MPI_BYTE);
        PVAR_INC_MSG(ibarrier, inter, recv, 1, MPI_BYTE);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);

        MPID_SCHED_BARRIER(s);

        /* receive bcast from right */
        root = 0;
        mpi_errno = comm_ptr->coll_fns->Ibcast_sched(buf, 1, MPI_BYTE, root, comm_ptr, s);
        PVAR_INC_MSG(ibarrier, inter, send, 1, MPI_BYTE);
        PVAR_INC_MSG(ibarrier, inter, recv, 1, MPI_BYTE);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    }
    else {
        /* receive bcast from left */
        root = 0;
        mpi_errno = comm_ptr->coll_fns->Ibcast_sched(buf, 1, MPI_BYTE, root, comm_ptr, s);
        PVAR_INC_MSG(ibarrier, inter, send, 1, MPI_BYTE);
        PVAR_INC_MSG(ibarrier, inter, recv, 1, MPI_BYTE);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);

        MPID_SCHED_BARRIER(s);

        /* bcast to left */
        root = (rank == 0) ? MPI_ROOT : MPI_PROC_NULL;
        mpi_errno = comm_ptr->coll_fns->Ibcast_sched(buf, 1, MPI_BYTE, root, comm_ptr, s);
        PVAR_INC_MSG(ibarrier, inter, send, 1, MPI_BYTE);
        PVAR_INC_MSG(ibarrier, inter, recv, 1, MPI_BYTE);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    }

    MPIR_SCHED_CHKPMEM_COMMIT(s);
fn_exit:
    PVAR_TIME_STOP(coll, ibarrier, inter);
    return mpi_errno;
fn_fail:
    MPIR_SCHED_CHKPMEM_REAP(s);
    goto fn_exit;
}

#undef FUNCNAME
#define FUNCNAME MPIR_Ibarrier_impl
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Ibarrier_impl(MPID_Comm *comm_ptr, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPID_Request *reqp = NULL;
    int tag = -1;
    MPID_Sched_t s = MPID_SCHED_NULL;

    *request = MPI_REQUEST_NULL;

#if defined (_SHARP_SUPPORT_)
    if (comm_ptr->dev.ch.is_sharp_ok == 1 && mv2_enable_sharp_coll == 2) {
            mpi_errno = MPIR_Sharp_Ibarrier_MV2(comm_ptr, NULL, &reqp);
            if (mpi_errno == MPI_SUCCESS) {
                if (reqp) {
                    *request = reqp->handle;
                }
                goto fn_exit;
            }
        /* SHArP collective is not supported,
        * continue without using SHArP */
    }
#endif /* end of defined (_SHARP_SUPPORT_) */

    MPIU_Assert(comm_ptr->coll_fns != NULL);
    if (comm_ptr->coll_fns->Ibarrier_req != NULL) {
        /* --BEGIN USEREXTENSION-- */
        mpi_errno = comm_ptr->coll_fns->Ibarrier_req(comm_ptr, &reqp);
        if (reqp) {
            *request = reqp->handle;
            if (mpi_errno) MPIR_ERR_POP(mpi_errno);
            goto fn_exit;
        }
        /* --END USEREXTENSION-- */
    }

    if (comm_ptr->local_size != 1 || comm_ptr->comm_kind == MPID_INTERCOMM) {
        mpi_errno = MPID_Sched_next_tag(comm_ptr, &tag);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        mpi_errno = MPID_Sched_create(&s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);

        MPIU_Assert(comm_ptr->coll_fns->Ibarrier_sched != NULL);
        mpi_errno = comm_ptr->coll_fns->Ibarrier_sched(comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);

        mpi_errno = MPID_Sched_start(&s, comm_ptr, tag, &reqp);
        if (reqp)
            *request = reqp->handle;
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    }

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

#endif /* MPICH_MPI_FROM_PMPI */

#undef FUNCNAME
#define FUNCNAME MPI_Ibarrier
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
/*@
MPI_Ibarrier - Notifies the process that it has reached the barrier and returns
               immediately

Input Parameters:
. comm - communicator (handle)

Output Parameters:
. request - communication request (handle)

Notes:
MPI_Ibarrier is a nonblocking version of MPI_barrier. By calling MPI_Ibarrier,
a process notifies that it has reached the barrier. The call returns
immediately, independent of whether other processes have called MPI_Ibarrier.
The usual barrier semantics are enforced at the corresponding completion
operation (test or wait), which in the intra-communicator case will complete
only after all other processes in the communicator have called MPI_Ibarrier. In
the intercommunicator case, it will complete when all processes in the remote
group have called MPI_Ibarrier.

.N ThreadSafe

.N Fortran

.N Errors
@*/
int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPID_Comm *comm_ptr = NULL;
    MPID_MPI_STATE_DECL(MPID_STATE_MPI_IBARRIER);

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPID_MPI_FUNC_ENTER(MPID_STATE_MPI_IBARRIER);

    /* Validate parameters, especially handles needing to be converted */
#   ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS
        {
            MPIR_ERRTEST_COMM(comm, mpi_errno);

            /* TODO more checks may be appropriate */
        }
        MPID_END_ERROR_CHECKS
    }
#   endif /* HAVE_ERROR_CHECKING */

    /* Convert MPI object handles to object pointers */
    MPID_Comm_get_ptr(comm, comm_ptr);

    /* Validate parameters and objects (post conversion) */
#   ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS
        {
            MPID_Comm_valid_ptr( comm_ptr, mpi_errno, FALSE );
            if (mpi_errno != MPI_SUCCESS) goto fn_fail;
            MPIR_ERRTEST_ARGNULL(request,"request", mpi_errno);
            /* TODO more checks may be appropriate (counts, in_place, buffer aliasing, etc) */
        }
        MPID_END_ERROR_CHECKS
    }
#   endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ...  */

    mpi_errno = MPIR_Ibarrier_impl(comm_ptr, request);
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);

#ifdef _OSU_MVAPICH_
    if (mv2_use_osu_collectives) {
        if (comm_ptr->dev.ch.shmem_coll_ok == 0) {
            mpi_errno = mv2_increment_shmem_coll_counter(comm_ptr);
            if (mpi_errno) {
                MPIR_ERR_POP(mpi_errno);
            }
        }
#if defined(_SHARP_SUPPORT_)
        comm_ptr->dev.ch.ibarrier_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_ibarrier &&
            (comm_ptr->dev.ch.is_sharp_ok == 0) &&
            (comm_ptr->dev.ch.shmem_coll_ok == 1) &&
            (comm_ptr->dev.ch.ibarrier_coll_count >= 
                            shmem_coll_count_threshold)) {
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm_ptr->handle,
                                          comm_ptr->local_size, comm_ptr->rank);
            if (mpi_errno) {
               MPIR_ERR_POP(mpi_errno);
            }
            enable_split_comm(pthread_self());
        }
#endif /*(_SHARP_SUPPORT_)*/
    }
#endif /* _OSU_MVAPICH_ */

    /* ... end of body of routine ... */

fn_exit:
    MPID_MPI_FUNC_EXIT(MPID_STATE_MPI_IBARRIER);
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

fn_fail:
    /* --BEGIN ERROR HANDLING-- */
#   ifdef HAVE_ERROR_CHECKING
    {
        mpi_errno = MPIR_Err_create_code(
            mpi_errno, MPIR_ERR_RECOVERABLE, FCNAME, __LINE__, MPI_ERR_OTHER,
            "**mpi_ibarrier", "**mpi_ibarrier %C %p", comm, request);
    }
#   endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, FCNAME, mpi_errno);
    goto fn_exit;
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}
