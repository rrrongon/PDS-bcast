/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *  (C) 2010 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "mpiimpl.h"
#include "collutil.h"

/* -- Begin Profiling Symbol Block for routine MPI_Ialltoall */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Ialltoall = PMPI_Ialltoall
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Ialltoall  MPI_Ialltoall
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Ialltoall as PMPI_Ialltoall
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Ialltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
                  __attribute__((weak,alias("PMPI_Ialltoall")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Ialltoall
#define MPI_Ialltoall PMPI_Ialltoall

#if (defined(CHANNEL_MRAIL) || defined(CHANNEL_PSM)) && ENABLE_PVAR_MV2
#include "coll_shmem.h"
MPIR_T_PVAR_DOUBLE_TIMER_DECL_EXTERN(MV2, mv2_coll_timer_ialltoall_inplace);
MPIR_T_PVAR_DOUBLE_TIMER_DECL_EXTERN(MV2, mv2_coll_timer_ialltoall_bruck);
MPIR_T_PVAR_DOUBLE_TIMER_DECL_EXTERN(MV2, mv2_coll_timer_ialltoall_perm_sr);
MPIR_T_PVAR_DOUBLE_TIMER_DECL_EXTERN(MV2, mv2_coll_timer_ialltoall_pairwise);
MPIR_T_PVAR_DOUBLE_TIMER_DECL_EXTERN(MV2, mv2_coll_timer_ialltoall_intra);
MPIR_T_PVAR_DOUBLE_TIMER_DECL_EXTERN(MV2, mv2_coll_timer_ialltoall_inter);

MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_inplace);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_bruck);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_perm_sr);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_pairwise);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_intra);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_inter);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_inplace_bytes_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_inplace_bytes_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_bruck_bytes_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_bruck_bytes_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_intra_bytes_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_intra_bytes_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_inter_bytes_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_inter_bytes_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_perm_sr_bytes_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_perm_sr_bytes_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_pairwise_bytes_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_pairwise_bytes_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_inplace_count_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_inplace_count_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_bruck_count_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_bruck_count_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_intra_count_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_intra_count_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_inter_count_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_inter_count_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_perm_sr_count_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_perm_sr_count_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_pairwise_count_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_pairwise_count_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_bytes_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_bytes_recv);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_count_send);
MPIR_T_PVAR_ULONG2_COUNTER_DECL_EXTERN(MV2, mv2_coll_ialltoall_count_recv);

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


/* Implements nonblocking all-to-all for sendbuf==MPI_IN_PLACE.
 *
 * We use nonblocking equivalent of pair-wise sendrecv_replace in order to
 * conserve memory usage, which is keeping with the spirit of the MPI-2.2
 * Standard.  But because of this approach all processes must agree on the
 * global schedule of "sendrecv_replace" operations to avoid deadlock.
 *
 * Note that this is not an especially efficient algorithm in terms of time.
 * Something like MADRE is probably the best solution for the MPI_IN_PLACE
 * scenario. */
#undef FUNCNAME
#define FUNCNAME MPIR_Ialltoall_inplace
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Ialltoall_inplace(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPID_Comm *comm_ptr, MPID_Sched_t s)
{
    PVAR_TIME_START(coll, ialltoall, inplace);
    int mpi_errno = MPI_SUCCESS;
    void *tmp_buf = NULL;
    int i, j;
    int rank, comm_size;
    int nbytes, recvtype_size;
    MPI_Aint recvtype_extent;
    int peer;
    MPIR_SCHED_CHKPMEM_DECL(1);
    PVAR_INC_1(MV2, mv2_coll_ialltoall_inplace, 1);
    MPIU_Assert(sendbuf == MPI_IN_PLACE);

    if (recvcount == 0)
        goto fn_exit;

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;
    MPID_Datatype_get_size_macro(recvtype, recvtype_size);
    MPID_Datatype_get_extent_macro(recvtype, recvtype_extent);
    nbytes = recvtype_size * recvcount;

    MPIR_SCHED_CHKPMEM_MALLOC(tmp_buf, void *, nbytes, mpi_errno, "tmp_buf");

    for (i = 0; i < comm_size; ++i) {
        /* start inner loop at i to avoid re-exchanging data */
        for (j = i; j < comm_size; ++j) {
            if (rank == i && rank == j) {
                /* no need to "sendrecv_replace" for ourselves */
            }
            else if (rank == i || rank == j) {
                if (rank == i)
                    peer = j;
                else
                    peer = i;

                /* pack to tmp_buf */
                mpi_errno = MPID_Sched_copy(((char *)recvbuf + peer*recvcount*recvtype_extent),
                                            recvcount, recvtype,
                                            tmp_buf, nbytes, MPI_BYTE, s);
                if (mpi_errno) MPIR_ERR_POP(mpi_errno);
                MPID_SCHED_BARRIER(s);

                /* now simultaneously send from tmp_buf and recv to recvbuf */
                PVAR_INC_MSG(ialltoall, inplace, send, nbytes, MPI_BYTE);
                PVAR_INC_MSG(ialltoall, inplace, recv, recvcount, recvtype);
                PVAR_INC_MSG(ialltoall, intra, send, nbytes, MPI_BYTE);
                PVAR_INC_MSG(ialltoall, intra, recv, recvcount, recvtype);
                mpi_errno = MPID_Sched_send(tmp_buf, nbytes, MPI_BYTE, peer, comm_ptr, s);
                if (mpi_errno) MPIR_ERR_POP(mpi_errno);
                mpi_errno = MPID_Sched_recv(((char *)recvbuf + peer*recvcount*recvtype_extent),
                                            recvcount, recvtype, peer, comm_ptr, s);
                if (mpi_errno) MPIR_ERR_POP(mpi_errno);
                MPID_SCHED_BARRIER(s);
            }
        }
    }

    MPIR_SCHED_CHKPMEM_COMMIT(s);
fn_exit:
    PVAR_TIME_STOP(coll, ialltoall, inplace);
    return mpi_errno;
fn_fail:
    MPIR_SCHED_CHKPMEM_REAP(s);
    goto fn_exit;
}

#undef FUNCNAME
#define FUNCNAME MPIR_Ialltoall_bruck
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Ialltoall_bruck(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPID_Comm *comm_ptr, MPID_Sched_t s)
{
    PVAR_TIME_START(coll, ialltoall, bruck);
    int mpi_errno = MPI_SUCCESS;
    int i;
    int nbytes, recvtype_size, recvbuf_extent, newtype_size;
    int rank, comm_size;
    void *tmp_buf = NULL;
    MPI_Aint sendtype_extent, recvtype_extent, recvtype_true_lb, recvtype_true_extent;
    int pof2, dst, src;
    int count, block;
    MPI_Datatype newtype;
    int *displs;
    MPIU_CHKLMEM_DECL(1); /* displs */
    MPIR_SCHED_CHKPMEM_DECL(2); /* tmp_buf (2x) */
    PVAR_INC_1(MV2, mv2_coll_ialltoall_bruck, 1);

    MPIU_Assert(sendbuf != MPI_IN_PLACE); /* we do not handle in-place */

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    MPID_Datatype_get_extent_macro(sendtype, sendtype_extent);
    MPID_Datatype_get_size_macro(recvtype, recvtype_size);
    MPID_Datatype_get_extent_macro(recvtype, recvtype_extent);

    /* allocate temporary buffer */
    /* must be same size as entire recvbuf for Phase 3 */
    nbytes = recvtype_size * recvcount * comm_size;
    MPIR_SCHED_CHKPMEM_MALLOC(tmp_buf, void *, nbytes, mpi_errno, "tmp_buf");

    /* Do Phase 1 of the algorithim. Shift the data blocks on process i
     * upwards by a distance of i blocks. Store the result in recvbuf. */
    mpi_errno = MPID_Sched_copy(((char *) sendbuf + rank*sendcount*sendtype_extent),
                                (comm_size - rank)*sendcount, sendtype,
                                recvbuf, (comm_size - rank)*recvcount, recvtype, s);
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    mpi_errno = MPID_Sched_copy(sendbuf, rank*sendcount, sendtype,
                                ((char *) recvbuf + (comm_size-rank)*recvcount*recvtype_extent),
                                rank*recvcount, recvtype, s);
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    MPID_SCHED_BARRIER(s);
    /* Input data is now stored in recvbuf with datatype recvtype */

    /* Now do Phase 2, the communication phase. It takes
       ceiling(lg p) steps. In each step i, each process sends to rank+2^i
       and receives from rank-2^i, and exchanges all data blocks
       whose ith bit is 1. */

    /* allocate displacements array for indexed datatype used in
       communication */

    MPIU_CHKLMEM_MALLOC(displs, int *, comm_size * sizeof(int), mpi_errno, "displs");

    pof2 = 1;
    while (pof2 < comm_size) {
        dst = (rank + pof2) % comm_size;
        src = (rank - pof2 + comm_size) % comm_size;

        /* Exchange all data blocks whose ith bit is 1 */
        /* Create an indexed datatype for the purpose */

        count = 0;
        for (block=1; block<comm_size; block++) {
            if (block & pof2) {
                displs[count] = block * recvcount;
                count++;
            }
        }

        mpi_errno = MPIR_Type_create_indexed_block_impl(count, recvcount,
                                                        displs, recvtype, &newtype);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);

        mpi_errno = MPIR_Type_commit_impl(&newtype);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        MPID_Datatype_get_size_macro(newtype, newtype_size);

        /* we will usually copy much less than nbytes */
        mpi_errno = MPID_Sched_copy(recvbuf, 1, newtype, tmp_buf, newtype_size, MPI_BYTE, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        MPID_SCHED_BARRIER(s);

        /* now send and recv in parallel */
        PVAR_INC_MSG(ialltoall, bruck, send, newtype_size, MPI_BYTE);
        PVAR_INC_MSG(ialltoall, bruck, recv, 1, newtype);
        PVAR_INC_MSG(ialltoall, intra, send, newtype_size, MPI_BYTE);
        PVAR_INC_MSG(ialltoall, intra, recv, 1, newtype);
        mpi_errno = MPID_Sched_send(tmp_buf, newtype_size, MPI_BYTE, dst, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        mpi_errno = MPID_Sched_recv(recvbuf, 1, newtype, src, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        MPID_SCHED_BARRIER(s);

        MPIR_Type_free_impl(&newtype);

        pof2 *= 2;
    }

    /* Phase 3: Rotate blocks in recvbuf upwards by (rank + 1) blocks. Need
     * a temporary buffer of the same size as recvbuf. */

    /* get true extent of recvtype */
    MPIR_Type_get_true_extent_impl(recvtype, &recvtype_true_lb, &recvtype_true_extent);

    recvbuf_extent = recvcount * comm_size * (MPIR_MAX(recvtype_true_extent, recvtype_extent));
    /* not a leak, old tmp_buf value is still tracked by CHKPMEM macros */
    MPIR_SCHED_CHKPMEM_MALLOC(tmp_buf, void *, recvbuf_extent, mpi_errno, "tmp_buf");
    /* adjust for potential negative lower bound in datatype */
    tmp_buf = (void *)((char*)tmp_buf - recvtype_true_lb);

    mpi_errno = MPID_Sched_copy(((char *) recvbuf + (rank+1)*recvcount*recvtype_extent),
                                (comm_size - rank - 1)*recvcount, recvtype,
                                tmp_buf, (comm_size - rank - 1)*recvcount, recvtype, s);
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    mpi_errno = MPID_Sched_copy(recvbuf, (rank+1)*recvcount, recvtype,
                                ((char *) tmp_buf + (comm_size-rank-1)*recvcount*recvtype_extent),
                                (rank+1)*recvcount, recvtype, s);
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    MPID_SCHED_BARRIER(s);

    /* Blocks are in the reverse order now (comm_size-1 to 0).
     * Reorder them to (0 to comm_size-1) and store them in recvbuf. */

    for (i = 0; i < comm_size; i++){
        mpi_errno = MPID_Sched_copy(((char *) tmp_buf + i*recvcount*recvtype_extent),
                                    recvcount, recvtype,
                                    ((char *) recvbuf + (comm_size-i-1)*recvcount*recvtype_extent),
                                    recvcount, recvtype, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    }

    MPIR_SCHED_CHKPMEM_COMMIT(s);
fn_exit:
    MPIU_CHKLMEM_FREEALL();
    PVAR_TIME_STOP(coll, ialltoall, bruck);
    return mpi_errno;
fn_fail:
    MPIR_SCHED_CHKPMEM_REAP(s);
    goto fn_exit;
}

/* Send/recv to permuted destinations/sources, in batches based on Tony Ladd's
 * suggestion.  Permuting the sources helps to avoid overloading a single source
 * or destination all at once.
 *
 * We use this as our default medium-sized-message algorithm. */
#undef FUNCNAME
#define FUNCNAME MPIR_Ialltoall_perm_sr
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Ialltoall_perm_sr(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPID_Comm *comm_ptr, MPID_Sched_t s)
{
    PVAR_TIME_START(coll, ialltoall, perm_sr);
    int mpi_errno = MPI_SUCCESS;
    int i;
    int rank, comm_size;
    int ii, ss, bblock, dst;
    MPI_Aint sendtype_extent, recvtype_extent;
    PVAR_INC_1(MV2, mv2_coll_ialltoall_perm_sr, 1);

    MPIU_Assert(sendbuf != MPI_IN_PLACE); /* we do not handle in-place */

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    MPID_Datatype_get_extent_macro(sendtype, sendtype_extent);
    MPID_Datatype_get_extent_macro(recvtype, recvtype_extent);

    bblock = MPIR_CVAR_ALLTOALL_THROTTLE;
    if (bblock == 0) bblock = comm_size;

    for (ii = 0; ii < comm_size; ii += bblock) {
        ss = comm_size-ii < bblock ? comm_size-ii : bblock;
        /* do the communication -- post ss sends and receives: */
        for (i = 0; i < ss; i++) {
            dst = (rank+i+ii) % comm_size;
            PVAR_INC_MSG(ialltoall, perm_sr, recv, recvcount, recvtype);
            PVAR_INC_MSG(ialltoall, intra, recv, recvcount, recvtype);
            mpi_errno = MPID_Sched_recv(((char *)recvbuf + dst*recvcount*recvtype_extent),
                                        recvcount, recvtype, dst, comm_ptr, s);
            if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        }

        for (i = 0; i < ss; i++) {
            dst = (rank-i-ii+comm_size) % comm_size;
            PVAR_INC_MSG(ialltoall, perm_sr, send, sendcount, sendtype);
            PVAR_INC_MSG(ialltoall, intra, send, sendcount, sendtype);
            mpi_errno = MPID_Sched_send(((char *)sendbuf + dst*sendcount*sendtype_extent),
                                        sendcount, sendtype, dst, comm_ptr, s);
            if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        }

        /* force the (2*ss) sends/recvs above to complete before posting additional ops */
        MPID_SCHED_BARRIER(s);
    }

fn_exit:
    PVAR_TIME_STOP(coll, ialltoall, perm_sr);
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

/* Pairwise exchanges for long messages. If comm_size is a power-of-two, do a
 * pairwise exchange using exclusive-or to create pairs. Else send to rank+i,
 * receive from rank-i. */
#undef FUNCNAME
#define FUNCNAME MPIR_Ialltoall_pairwise
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Ialltoall_pairwise(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPID_Comm *comm_ptr, MPID_Sched_t s)
{
    PVAR_TIME_START(coll, ialltoall, pairwise);
    int mpi_errno = MPI_SUCCESS;
    int i;
    int src, dst, is_pof2;
    int rank, comm_size;
    MPI_Aint sendtype_extent, recvtype_extent;

    MPIU_Assert(sendbuf != MPI_IN_PLACE); /* we do not handle in-place */
    PVAR_INC_1(MV2, mv2_coll_ialltoall_pairwise, 1);

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    MPID_Datatype_get_extent_macro(sendtype, sendtype_extent);
    MPID_Datatype_get_extent_macro(recvtype, recvtype_extent);

    /* Make local copy first */
    mpi_errno = MPID_Sched_copy(((char *)sendbuf + rank*sendcount*sendtype_extent),
                                sendcount, sendtype,
                                ((char *)recvbuf + rank*recvcount*recvtype_extent),
                                recvcount, recvtype, s);
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);

    is_pof2 = MPIU_is_pof2(comm_size, NULL);

    /* Do the pairwise exchanges */
    for (i = 1; i < comm_size; i++) {
        if (is_pof2 == 1) {
            /* use exclusive-or algorithm */
            src = dst = rank ^ i;
        }
        else {
            src = (rank - i + comm_size) % comm_size;
            dst = (rank + i) % comm_size;
        }
        PVAR_INC_MSG(ialltoall, pairwise, send, sendcount, sendtype);
        PVAR_INC_MSG(ialltoall, intra, send, sendcount, sendtype);
        mpi_errno = MPID_Sched_send(((char *)sendbuf + dst*sendcount*sendtype_extent),
                                    sendcount, sendtype, dst, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        PVAR_INC_MSG(ialltoall, pairwise, recv, recvcount, recvtype);
        PVAR_INC_MSG(ialltoall, intra, recv, recvcount, recvtype);
        mpi_errno = MPID_Sched_recv(((char *)recvbuf + src*recvcount*recvtype_extent),
                                    recvcount, recvtype, src, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        MPID_SCHED_BARRIER(s);
    }

fn_exit:
    PVAR_TIME_STOP(coll, ialltoall, pairwise);
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

/* This is the default implementation of alltoall. The algorithm is:

   Algorithm: MPI_Alltoall

   We use four algorithms for alltoall. For short messages and
   (comm_size >= 8), we use the algorithm by Jehoshua Bruck et al,
   IEEE TPDS, Nov. 1997. It is a store-and-forward algorithm that
   takes lgp steps. Because of the extra communication, the bandwidth
   requirement is (n/2).lgp.beta.

   Cost = lgp.alpha + (n/2).lgp.beta

   where n is the total amount of data a process needs to send to all
   other processes.

   For medium size messages and (short messages for comm_size < 8), we
   use an algorithm that posts all irecvs and isends and then does a
   waitall. We scatter the order of sources and destinations among the
   processes, so that all processes don't try to send/recv to/from the
   same process at the same time.

   *** Modification: We post only a small number of isends and irecvs
   at a time and wait on them as suggested by Tony Ladd. ***
   *** See comments below about an additional modification that
   we may want to consider ***

   For long messages and power-of-two number of processes, we use a
   pairwise exchange algorithm, which takes p-1 steps. We
   calculate the pairs by using an exclusive-or algorithm:
           for (i=1; i<comm_size; i++)
               dest = rank ^ i;
   This algorithm doesn't work if the number of processes is not a power of
   two. For a non-power-of-two number of processes, we use an
   algorithm in which, in step i, each process  receives from (rank-i)
   and sends to (rank+i).

   Cost = (p-1).alpha + n.beta

   where n is the total amount of data a process needs to send to all
   other processes.

   Possible improvements:

   End Algorithm: MPI_Alltoall
*/
#undef FUNCNAME
#define FUNCNAME MPIR_Ialltoall_intra
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Ialltoall_intra(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPID_Comm *comm_ptr, MPID_Sched_t s)
{
    PVAR_TIME_START(coll, ialltoall, intra);
    int mpi_errno = MPI_SUCCESS;
    int nbytes, comm_size, sendtype_size;

    comm_size = comm_ptr->local_size;
    PVAR_INC_1(MV2, mv2_coll_ialltoall_intra, 1);

    MPID_Datatype_get_size_macro(sendtype, sendtype_size);
    nbytes = sendtype_size * sendcount;

    if (sendbuf == MPI_IN_PLACE) {
        mpi_errno = MPIR_Ialltoall_inplace(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    }
    else if ((nbytes <= MPIR_CVAR_ALLTOALL_SHORT_MSG_SIZE) && (comm_size >= 8)) {
        /* use the indexing algorithm by Jehoshua Bruck et al,
         * IEEE TPDS, Nov. 97 */
        mpi_errno = MPIR_Ialltoall_bruck(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    }
    else if (nbytes <= MPIR_CVAR_ALLTOALL_MEDIUM_MSG_SIZE) {
        /* Medium-size message. Use isend/irecv with scattered
           destinations. Use Tony Ladd's modification to post only
           a small number of isends/irecvs at a time. */
        mpi_errno = MPIR_Ialltoall_perm_sr(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    }
    else {
        /* Long message. If comm_size is a power-of-two, do a pairwise
           exchange using exclusive-or to create pairs. Else send to
           rank+i, receive from rank-i. */
        mpi_errno = MPIR_Ialltoall_pairwise(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    }

fn_exit:
    PVAR_TIME_STOP(coll, ialltoall, intra);
    return mpi_errno;
fn_fail:
    goto fn_exit;
}


#undef FUNCNAME
#define FUNCNAME MPIR_Ialltoall_inter
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Ialltoall_inter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPID_Comm *comm_ptr, MPID_Sched_t s)
{
    PVAR_TIME_START(coll, ialltoall, inter);
/* Intercommunicator alltoall. We use a pairwise exchange algorithm
   similar to the one used in intracommunicator alltoall for long
   messages. Since the local and remote groups can be of different
   sizes, we first compute the max of local_group_size,
   remote_group_size. At step i, 0 <= i < max_size, each process
   receives from src = (rank - i + max_size) % max_size if src <
   remote_size, and sends to dst = (rank + i) % max_size if dst <
   remote_size.
*/
    PVAR_INC_1(MV2, mv2_coll_ialltoall_inter, 1);
    int mpi_errno = MPI_SUCCESS;
    int local_size, remote_size, max_size, i;
    MPI_Aint sendtype_extent, recvtype_extent;
    int src, dst, rank;
    char *sendaddr, *recvaddr;

    local_size = comm_ptr->local_size;
    remote_size = comm_ptr->remote_size;
    rank = comm_ptr->rank;

    /* Get extent of send and recv types */
    MPID_Datatype_get_extent_macro(sendtype, sendtype_extent);
    MPID_Datatype_get_extent_macro(recvtype, recvtype_extent);

    /* Do the pairwise exchanges */
    max_size = MPIR_MAX(local_size, remote_size);
    MPIU_Ensure_Aint_fits_in_pointer(MPIU_VOID_PTR_CAST_TO_MPI_AINT recvbuf +
                                     max_size*recvcount*recvtype_extent);
    MPIU_Ensure_Aint_fits_in_pointer(MPIU_VOID_PTR_CAST_TO_MPI_AINT sendbuf +
                                     max_size*sendcount*sendtype_extent);
    for (i = 0; i < max_size; i++) {
        src = (rank - i + max_size) % max_size;
        dst = (rank + i) % max_size;
        if (src >= remote_size) {
            src = MPI_PROC_NULL;
            recvaddr = NULL;
        }
        else {
            recvaddr = (char *)recvbuf + src*recvcount*recvtype_extent;
        }
        if (dst >= remote_size) {
            dst = MPI_PROC_NULL;
            sendaddr = NULL;
        }
        else {
            sendaddr = (char *)sendbuf + dst*sendcount*sendtype_extent;
        }
        PVAR_INC_MSG(ialltoall, inter, send, sendcount, sendtype);
        mpi_errno = MPID_Sched_send(sendaddr, sendcount, sendtype, dst, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        PVAR_INC_MSG(ialltoall, inter, recv, recvcount, recvtype);
        mpi_errno = MPID_Sched_recv(recvaddr, recvcount, recvtype, src, comm_ptr, s);
        if (mpi_errno) MPIR_ERR_POP(mpi_errno);
        MPID_SCHED_BARRIER(s);
    }

fn_exit:
    PVAR_TIME_STOP(coll, ialltoall, inter)
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

#undef FUNCNAME
#define FUNCNAME MPIR_Ialltoall_impl
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
int MPIR_Ialltoall_impl(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPID_Comm *comm_ptr, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPID_Request *reqp = NULL;
    int tag = -1;
    MPID_Sched_t s = MPID_SCHED_NULL;

    *request = MPI_REQUEST_NULL;

    MPIU_Assert(comm_ptr->coll_fns != NULL);
    if (comm_ptr->coll_fns->Ialltoall_req != NULL) {
        /* --BEGIN USEREXTENSION-- */
        mpi_errno = comm_ptr->coll_fns->Ialltoall_req(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm_ptr, &reqp);
        if (reqp) {
            *request = reqp->handle;
            if (mpi_errno) MPIR_ERR_POP(mpi_errno);
            goto fn_exit;
        }
        /* --END USEREXTENSION-- */
    }

    mpi_errno = MPID_Sched_next_tag(comm_ptr, &tag);
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);
    mpi_errno = MPID_Sched_create(&s);
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);

    MPIU_Assert(comm_ptr->coll_fns != NULL);
    MPIU_Assert(comm_ptr->coll_fns->Ialltoall_sched != NULL);
    mpi_errno = comm_ptr->coll_fns->Ialltoall_sched(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm_ptr, s);
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);

    mpi_errno = MPID_Sched_start(&s, comm_ptr, tag, &reqp);
    if (reqp)
        *request = reqp->handle;
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

#endif /* MPICH_MPI_FROM_PMPI */

#undef FUNCNAME
#define FUNCNAME MPI_Ialltoall
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
/*@
MPI_Ialltoall - Sends data from all to all processes in a nonblocking way

Input Parameters:
+ sendbuf - starting address of the send buffer (choice)
. sendcount - number of elements in send buffer (non-negative integer)
. sendtype - data type of send buffer elements (handle)
. recvcount - number of elements received from any process (non-negative integer)
. recvtype - data type of receive buffer elements (handle)
- comm - communicator (handle)

Output Parameters:
+ recvbuf - starting address of the receive buffer (choice)
- request - communication request (handle)

.N ThreadSafe

.N Fortran

.N Errors
@*/
int MPI_Ialltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  MPI_Comm comm, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPID_Comm *comm_ptr = NULL;
    MPID_MPI_STATE_DECL(MPID_STATE_MPI_IALLTOALL);

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPID_MPI_FUNC_ENTER(MPID_STATE_MPI_IALLTOALL);

    /* Validate parameters, especially handles needing to be converted */
#   ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS
        {
            if (sendbuf != MPI_IN_PLACE) {
                MPIR_ERRTEST_COUNT(sendcount, mpi_errno);
                MPIR_ERRTEST_DATATYPE(sendtype, "sendtype", mpi_errno);
            }
            MPIR_ERRTEST_COUNT(recvcount, mpi_errno);
            MPIR_ERRTEST_DATATYPE(recvtype, "recvtype", mpi_errno);
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

            if (sendbuf != MPI_IN_PLACE && HANDLE_GET_KIND(sendtype) != HANDLE_KIND_BUILTIN) {
                MPID_Datatype *sendtype_ptr = NULL;
                MPID_Datatype_get_ptr(sendtype, sendtype_ptr);
                MPID_Datatype_valid_ptr(sendtype_ptr, mpi_errno);
                if (mpi_errno != MPI_SUCCESS) goto fn_fail;
                MPID_Datatype_committed_ptr(sendtype_ptr, mpi_errno);
                if (mpi_errno != MPI_SUCCESS) goto fn_fail;
            }

            if (HANDLE_GET_KIND(recvtype) != HANDLE_KIND_BUILTIN) {
                MPID_Datatype *recvtype_ptr = NULL;
                MPID_Datatype_get_ptr(recvtype, recvtype_ptr);
                MPID_Datatype_valid_ptr(recvtype_ptr, mpi_errno);
                if (mpi_errno != MPI_SUCCESS) goto fn_fail;
                MPID_Datatype_committed_ptr(recvtype_ptr, mpi_errno);
                if (mpi_errno != MPI_SUCCESS) goto fn_fail;
            }

            MPIR_ERRTEST_ARGNULL(request,"request", mpi_errno);

            if (comm_ptr->comm_kind == MPID_INTRACOMM &&
                    sendbuf != MPI_IN_PLACE &&
                    sendcount == recvcount &&
                    sendtype == recvtype &&
                    sendcount != 0)
                MPIR_ERRTEST_ALIAS_COLL(sendbuf,recvbuf,mpi_errno);
            /* TODO more checks may be appropriate (counts, in_place, etc) */
        }
        MPID_END_ERROR_CHECKS
    }
#   endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ...  */

    mpi_errno = MPIR_Ialltoall_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm_ptr, request);
    if (mpi_errno) MPIR_ERR_POP(mpi_errno);

    /* ... end of body of routine ... */

fn_exit:
    MPID_MPI_FUNC_EXIT(MPID_STATE_MPI_IALLTOALL);
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

fn_fail:
    /* --BEGIN ERROR HANDLING-- */
#   ifdef HAVE_ERROR_CHECKING
    {
        mpi_errno = MPIR_Err_create_code(
            mpi_errno, MPIR_ERR_RECOVERABLE, FCNAME, __LINE__, MPI_ERR_OTHER,
            "**mpi_ialltoall", "**mpi_ialltoall %p %d %D %p %d %D %C %p", sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);
    }
#   endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, FCNAME, mpi_errno);
    goto fn_exit;
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}
