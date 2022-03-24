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

#ifndef _IGATHER_TUNING_
#define _IGATHER_TUNING_

#include "coll_shmem.h"
#if defined(CHANNEL_MRAIL)
#include "ibv_param.h"
#endif                          /* #if defined(CHANNEL_MRAIL) */

#define NMATCH (3+1)

/* Note: Several members of the structures used are meant to be used
   sometime in the future */

typedef struct {
    int min;
    int max;
    int (*MV2_pt_Igather_function) (const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                             void *recvbuf, int recvcount, MPI_Datatype recvtype,
                             int root, MPID_Comm *comm_ptr, MPID_Sched_t s);
    int zcpy_knomial_factor;
} mv2_igather_tuning_element;

typedef struct {
    int numproc;
    int igather_segment_size;
    int intra_node_knomial_factor;
    int inter_node_knomial_factor;
    int is_two_level_igather[MV2_MAX_NB_THRESHOLDS];
    int size_inter_table;
    mv2_igather_tuning_element inter_leader[MV2_MAX_NB_THRESHOLDS];
    int size_intra_table;
    mv2_igather_tuning_element intra_node[MV2_MAX_NB_THRESHOLDS];
} mv2_igather_tuning_table;

//extern int mv2_use_pipelined_gather;
//extern int mv2_pipelined_knomial_factor; 
//extern int mv2_pipelined_zcpy_knomial_factor; 
//extern int zcpy_knomial_factor;
extern int igather_segment_size;
extern int mv2_size_igather_tuning_table;
extern mv2_igather_tuning_table *mv2_igather_thresholds_table;

/* Architecture detection tuning */
int MV2_set_igather_tuning_table(int heterogeneity);

/* Function to clean free memory allocated by igather tuning table*/
void MV2_cleanup_igather_tuning_table();

// Consider removing
/* Function used inside ch3_shmem_coll.c to tune igather thresholds */
int MV2_internode_Igather_is_define(char *mv2_user_igather_inter, char *mv2_user_igather_intra); 
int MV2_intranode_Igather_is_define(char *mv2_user_igather_intra);

extern int MPIR_Igather_binomial(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                             void *recvbuf, int recvcount, MPI_Datatype recvtype,
                             int root, MPID_Comm *comm_ptr, MPID_Sched_t s);
#endif
