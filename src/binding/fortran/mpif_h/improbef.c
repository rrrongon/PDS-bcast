/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*  
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 *
 * This file is automatically generated by buildiface 
 * DO NOT EDIT
 */
#include "mpi_fortimpl.h"


/* Begin MPI profiling block */
#if defined(USE_WEAK_SYMBOLS) && !defined(USE_ONLY_MPI_NAMES) 
#if defined(HAVE_MULTIPLE_PRAGMA_WEAK)
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak MPI_IMPROBE = PMPI_IMPROBE
#pragma weak mpi_improbe__ = PMPI_IMPROBE
#pragma weak mpi_improbe_ = PMPI_IMPROBE
#pragma weak mpi_improbe = PMPI_IMPROBE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_IMPROBE = pmpi_improbe__
#pragma weak mpi_improbe__ = pmpi_improbe__
#pragma weak mpi_improbe_ = pmpi_improbe__
#pragma weak mpi_improbe = pmpi_improbe__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_IMPROBE = pmpi_improbe_
#pragma weak mpi_improbe__ = pmpi_improbe_
#pragma weak mpi_improbe_ = pmpi_improbe_
#pragma weak mpi_improbe = pmpi_improbe_
#else
#pragma weak MPI_IMPROBE = pmpi_improbe
#pragma weak mpi_improbe__ = pmpi_improbe
#pragma weak mpi_improbe_ = pmpi_improbe
#pragma weak mpi_improbe = pmpi_improbe
#endif



#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_IMPROBE = PMPI_IMPROBE
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_improbe__ = pmpi_improbe__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_improbe = pmpi_improbe
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_improbe_ = pmpi_improbe_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_IMPROBE  MPI_IMPROBE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_improbe__  mpi_improbe__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_improbe  mpi_improbe
#else
#pragma _HP_SECONDARY_DEF pmpi_improbe_  mpi_improbe_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_IMPROBE as PMPI_IMPROBE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_improbe__ as pmpi_improbe__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_improbe as pmpi_improbe
#else
#pragma _CRI duplicate mpi_improbe_ as pmpi_improbe_
#endif

#elif defined(HAVE_WEAK_ATTRIBUTE)
#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("PMPI_IMPROBE")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("PMPI_IMPROBE")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("PMPI_IMPROBE")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("PMPI_IMPROBE")));

#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe__")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe__")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe__")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe__")));

#elif defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe_")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe_")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe_")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe_")));

#else
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe")));

#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYMBOLS) && defined(USE_ONLY_MPI_NAMES)
#if defined(HAVE_MULTIPLE_PRAGMA_WEAK)
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak mpi_improbe__ = MPI_IMPROBE
#pragma weak mpi_improbe_ = MPI_IMPROBE
#pragma weak mpi_improbe = MPI_IMPROBE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_IMPROBE = mpi_improbe__
#pragma weak mpi_improbe_ = mpi_improbe__
#pragma weak mpi_improbe = mpi_improbe__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_IMPROBE = mpi_improbe_
#pragma weak mpi_improbe__ = mpi_improbe_
#pragma weak mpi_improbe = mpi_improbe_
#else
#pragma weak MPI_IMPROBE = mpi_improbe
#pragma weak mpi_improbe__ = mpi_improbe
#pragma weak mpi_improbe_ = mpi_improbe
#endif
#elif defined(HAVE_WEAK_ATTRIBUTE)
#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("MPI_IMPROBE")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("MPI_IMPROBE")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("MPI_IMPROBE")));

#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("mpi_improbe__")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("mpi_improbe__")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("mpi_improbe__")));

#elif defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("mpi_improbe_")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("mpi_improbe_")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("mpi_improbe_")));

#else
extern FORT_DLL_SPEC void FORT_CALL MPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("mpi_improbe")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("mpi_improbe")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("mpi_improbe")));
extern FORT_DLL_SPEC void FORT_CALL mpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#endif
#endif

#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#if defined(USE_WEAK_SYMBOLS)
#if defined(HAVE_MULTIPLE_PRAGMA_WEAK)
/* Define the weak versions of the PMPI routine*/
#ifndef F77_NAME_UPPER
extern FORT_DLL_SPEC void FORT_CALL PMPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_2USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#endif

#if defined(F77_NAME_UPPER)
#pragma weak pmpi_improbe__ = PMPI_IMPROBE
#pragma weak pmpi_improbe_ = PMPI_IMPROBE
#pragma weak pmpi_improbe = PMPI_IMPROBE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak PMPI_IMPROBE = pmpi_improbe__
#pragma weak pmpi_improbe_ = pmpi_improbe__
#pragma weak pmpi_improbe = pmpi_improbe__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak PMPI_IMPROBE = pmpi_improbe_
#pragma weak pmpi_improbe__ = pmpi_improbe_
#pragma weak pmpi_improbe = pmpi_improbe_
#else
#pragma weak PMPI_IMPROBE = pmpi_improbe
#pragma weak pmpi_improbe__ = pmpi_improbe
#pragma weak pmpi_improbe_ = pmpi_improbe
#endif /* Test on name mapping */

#elif defined(HAVE_WEAK_ATTRIBUTE)
#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("PMPI_IMPROBE")));
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("PMPI_IMPROBE")));
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("PMPI_IMPROBE")));

#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL PMPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe__")));
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe__")));
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe__")));

#elif defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL PMPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe_")));
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe_")));
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe_")));

#else
extern FORT_DLL_SPEC void FORT_CALL PMPI_IMPROBE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe")));
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe")));
extern FORT_DLL_SPEC void FORT_CALL pmpi_improbe_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * ) __attribute__((weak,alias("pmpi_improbe")));

#endif /* Test on name mapping */
#endif /* HAVE_MULTIPLE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */

#ifdef F77_NAME_UPPER
#define mpi_improbe_ PMPI_IMPROBE
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_improbe_ pmpi_improbe__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_improbe_ pmpi_improbe
#else
#define mpi_improbe_ pmpi_improbe_
#endif /* Test on name mapping */

#ifdef F77_USE_PMPI
/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings. */
#undef MPI_Improbe
#define MPI_Improbe PMPI_Improbe 
#endif

#else

#ifdef F77_NAME_UPPER
#define mpi_improbe_ MPI_IMPROBE
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_improbe_ mpi_improbe__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_improbe_ mpi_improbe
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_improbe_ ( MPI_Fint *v1, MPI_Fint *v2, MPI_Fint *v3, MPI_Fint *v4, MPI_Fint *v5, MPI_Fint *v6, MPI_Fint *ierr ){
    int l4;

#ifndef HAVE_MPI_F_INIT_WORKS_WITH_C
    if (MPIR_F_NeedInit){ mpirinitf_(); MPIR_F_NeedInit = 0; }
#endif

    if (v6 == MPI_F_STATUS_IGNORE) { v6 = (MPI_Fint*)MPI_STATUS_IGNORE; }
    *ierr = MPI_Improbe( (int)*v1, (int)*v2, (MPI_Comm)(*v3), &l4, (MPI_Message *)(v5), (MPI_Status *)v6 );
    if (*ierr == MPI_SUCCESS) *v4 = MPIR_TO_FLOG(l4);
}
