/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *
 *   Copyright (C) 1997 University of Chicago.
 *   Copyright (C) 2017 DataDirect Networks.
 *   See COPYRIGHT notice in top-level directory.
 */

#include "ad_ime.h"
#include "ad_ime_common.h"
#include <unistd.h>
#include <sys/types.h>

/* keyval hack to both tell us if we've already initialized im and also
 * close it down when mpi exits */
int ADIOI_IME_Initialized = MPI_KEYVAL_INVALID;

void ADIOI_IME_End(int *error_code)
{
    int ret;
    static char myname[] = "ADIOI_IME_END";

    ret = ime_native_finalize();

    /* --BEGIN ERROR HANDLING-- */
    if (ret != 0) {
        *error_code = MPIO_Err_create_code(MPI_SUCCESS,
                                           MPIR_ERR_RECOVERABLE,
                                           myname, __LINE__,
                                           MPI_ERR_FILE, "Error in ime_native_finalize", 0);
        return;
    }
    /* --END ERROR HANDLING-- */

    *error_code = MPI_SUCCESS;
}

int ADIOI_IME_End_call(MPI_Comm comm, int keyval, void *attribute_val, void *extra_state)
{
    int error_code;
    ADIOI_IME_End(&error_code);
    MPI_Keyval_free(&keyval);
    return error_code;
}

void ADIOI_IME_Init(int rank, int *error_code)
{
    /* do nothing if we've already fired up the im interface */
    if (ADIOI_IME_Initialized != MPI_KEYVAL_INVALID) {
        *error_code = MPI_SUCCESS;
        return;
    }

    ime_native_init();

    *error_code = MPI_SUCCESS;

    MPI_Keyval_create(MPI_NULL_COPY_FN, ADIOI_IME_End_call, &ADIOI_IME_Initialized, (void *) 0);
    /* just like romio does, we make a dummy attribute so we
     * get cleaned up */
    MPI_Attr_put(MPI_COMM_SELF, ADIOI_IME_Initialized, (void *) 0);
}

/**
 * Return an IME-compatible filename
 * An absolute BFS path will get added the 'ime:' prefix.
 * A path on ime-fuse will be converted to a relative ime path,
 * with the ime:/ prefix
 * The returned filename must be free'd by the user
 */
char *ADIOI_IME_Convert_filename(const char *filename)
{
    static char myname[] = "ADIOI_IME_CONVERT_FILENAME";

#if (IME_NATIVE_API_VERSION >= 131)
    bool is_fuse = ime_native_is_fuse_path_and_convert(filename, NULL);
    if (is_fuse) {
        return ADIOI_Strdup(filename);
    }
#endif

    size_t f_len = strlen(filename) + 1;
    char *ime_filename = ADIOI_Malloc(f_len + IME_FILE_PREFIX_LEN_NO_FWD_SLASH);
    if (!ime_filename) {
        MPIO_Err_create_code(MPI_SUCCESS,
                             MPIR_ERR_FATAL,
                             myname, __LINE__, MPI_ERR_UNKNOWN,
                             "Error allocating memory", 0);

        return NULL;
    }

    ADIOI_Strncpy(ime_filename, DEFAULT_IME_PREFIX_NO_FWD_SLASH,
                  IME_FILE_PREFIX_LEN_NO_FWD_SLASH);
    ADIOI_Strncpy((ime_filename + IME_FILE_PREFIX_LEN_NO_FWD_SLASH),
                  filename, f_len);
    return ime_filename;
}
