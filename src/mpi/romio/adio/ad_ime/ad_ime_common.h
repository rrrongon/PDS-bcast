/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *
 *   Copyright (C) 1997 University of Chicago.
 *   Copyright (C) 2017 DataDirect Networks.
 *   See COPYRIGHT notice in top-level directory.
 */

#ifndef AD_IME_COMMON_H_INCLUDED
#define AD_IME_COMMON_H_INCLUDED
#include "ad_ime.h"

struct ADIOI_IME_fs_s {
    char *ime_filename;
};

typedef struct ADIOI_IME_fs_s ADIOI_IME_fs;

void ADIOI_IME_Init(int rank, int *error_code);
void ADIOI_IME_End(int *error_code);
int ADIOI_IME_End_call(MPI_Comm comm, int keyval, void *attribute_val, void *extra_state);

char *ADIOI_IME_Convert_filename(const char *filename);
#endif /* AD_IME_COMMON_H_INCLUDED */
