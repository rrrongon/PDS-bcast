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

#include <regex.h>
#include "ialltoall_tuning.h"
#include "common_tuning.h"
#include "mv2_arch_hca_detect.h"
/* array used to tune ialltoall */

int mv2_size_ialltoall_tuning_table = 0;
mv2_ialltoall_tuning_table *mv2_ialltoall_thresholds_table = NULL;

int MV2_set_ialltoall_tuning_table(int heterogeneity)
{
#if defined(CHANNEL_MRAIL) && !defined(CHANNEL_PSM)
    if (MV2_IS_ARCH_HCA_TYPE(MV2_get_arch_hca_type(),
		MV2_ARCH_AMD_OPTERON_6136_32, MV2_HCA_MLX_CX_QDR) && !heterogeneity) {
      
	/*Trestles Table*/
	mv2_size_ialltoall_tuning_table = 5;
	mv2_ialltoall_thresholds_table = MPIU_Malloc(mv2_size_ialltoall_tuning_table *
						  sizeof (mv2_ialltoall_tuning_table));
	mv2_ialltoall_tuning_table mv2_tmp_ialltoall_thresholds_table[] = {
	    {8,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_pairwise, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {16,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_pairwise, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {32,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_pairwise, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {64,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_pairwise, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {128,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_pairwise, -1}},
	     1, {{0, -1, NULL, -1}}
	    }
      };
    
      MPIU_Memcpy(mv2_ialltoall_thresholds_table, mv2_tmp_ialltoall_thresholds_table,
		  mv2_size_ialltoall_tuning_table * sizeof (mv2_ialltoall_tuning_table));
    } else if (MV2_IS_ARCH_HCA_TYPE(MV2_get_arch_hca_type(),
		MV2_ARCH_INTEL_XEON_E5_2670_16, MV2_HCA_MLX_CX_FDR) && !heterogeneity) {

	/*Gordon Table*/
	mv2_size_ialltoall_tuning_table = 5;
	mv2_ialltoall_thresholds_table = MPIU_Malloc(mv2_size_ialltoall_tuning_table *
						  sizeof (mv2_ialltoall_tuning_table));
	mv2_ialltoall_tuning_table mv2_tmp_ialltoall_thresholds_table[] = {
	    {8,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_pairwise, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {16,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_pairwise, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {32,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_pairwise, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {64,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_pairwise, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {128,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_pairwise, -1}},
	     1, {{0, -1, NULL, -1}}
	    }
      };
    
      MPIU_Memcpy(mv2_ialltoall_thresholds_table, mv2_tmp_ialltoall_thresholds_table,
		  mv2_size_ialltoall_tuning_table * sizeof (mv2_ialltoall_tuning_table));
    }
    else if (MV2_IS_ARCH_HCA_TYPE(MV2_get_arch_hca_type(),
		MV2_ARCH_INTEL_XEON_E5_2680_16, MV2_HCA_MLX_CX_FDR) && !heterogeneity) {
      
	/*Stampede,*/
	mv2_size_ialltoall_tuning_table = 8;
	mv2_ialltoall_thresholds_table = MPIU_Malloc(mv2_size_ialltoall_tuning_table *
						  sizeof (mv2_ialltoall_tuning_table));
	mv2_ialltoall_tuning_table mv2_tmp_ialltoall_thresholds_table[] = {
	    {8,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {16,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {32,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {64,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {128,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {256,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {512,
	     8192,
	     {0},
	     2, {
	       {0, 64, &MPIR_Ialltoall_bruck, -1},
	       {64, -1, &MPIR_Ialltoall_perm_sr, -1}
	        },
	     1, {{0, -1, NULL, -1}}
	    },
	    {1024,
	     8192,
	     {0},
	     2, {
	       {0, 64, &MPIR_Ialltoall_bruck, -1},
	       {64, -1, &MPIR_Ialltoall_pairwise, -1}
	        },
	     1, {{0, -1, NULL, -1}}
	    }
      };
    
      MPIU_Memcpy(mv2_ialltoall_thresholds_table, mv2_tmp_ialltoall_thresholds_table,
		  mv2_size_ialltoall_tuning_table * sizeof (mv2_ialltoall_tuning_table));
    }
    else if (MV2_IS_ARCH_HCA_TYPE(MV2_get_arch_hca_type(),
                MV2_ARCH_INTEL_XEON_E5_2697A_V4_2S_32, MV2_HCA_MLX_CX_EDR) && !heterogeneity) {

        /*Thor (HPCAC)*/
        mv2_size_ialltoall_tuning_table = 1;
        mv2_ialltoall_thresholds_table = MPIU_Malloc(mv2_size_ialltoall_tuning_table *
                sizeof (mv2_ialltoall_tuning_table));
        mv2_ialltoall_tuning_table mv2_tmp_ialltoall_thresholds_table[] = {
            {8,
                8192,
                {0},
                3, {
                    {0, 256, &MPIR_Ialltoall_bruck, -1},
                    {256, 32768, &MPIR_Ialltoall_perm_sr, -1},
                    {32768, -1, &MPIR_Ialltoall_pairwise, -1}
                },
                1, {{0, -1, NULL, -1}}
            }
        };

        MPIU_Memcpy(mv2_ialltoall_thresholds_table, mv2_tmp_ialltoall_thresholds_table,
                mv2_size_ialltoall_tuning_table * sizeof (mv2_ialltoall_tuning_table));
    }
    else
    {
        
        /*Thor (HPCAC)*/
        mv2_size_ialltoall_tuning_table = 1;
        mv2_ialltoall_thresholds_table = MPIU_Malloc(mv2_size_ialltoall_tuning_table *
                sizeof (mv2_ialltoall_tuning_table));
        mv2_ialltoall_tuning_table mv2_tmp_ialltoall_thresholds_table[] = {
            {8,
                8192,
                {0},
                3, {
                    {0, 256, &MPIR_Ialltoall_bruck, -1},
                    {256, 32768, &MPIR_Ialltoall_perm_sr, -1},
                    {32768, -1, &MPIR_Ialltoall_pairwise, -1}
                },
                1, {{0, -1, NULL, -1}}
            }
        };

        MPIU_Memcpy(mv2_ialltoall_thresholds_table, mv2_tmp_ialltoall_thresholds_table,
                mv2_size_ialltoall_tuning_table * sizeof (mv2_ialltoall_tuning_table));
    }
#else /* defined(CHANNEL_MRAIL) && !defined(CHANNEL_PSM) */
        
	/*RI*/
	mv2_size_ialltoall_tuning_table = 7;
	mv2_ialltoall_thresholds_table = MPIU_Malloc(mv2_size_ialltoall_tuning_table *
						  sizeof (mv2_ialltoall_tuning_table));
	mv2_ialltoall_tuning_table mv2_tmp_ialltoall_thresholds_table[] = {
	    {8,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {16,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {32,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {64,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {128,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {256,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_perm_sr, -1}},
	     1, {{0, -1, NULL, -1}}
	    },
	    {512,
	     8192,
	     {0},
	     1, {{0, -1, &MPIR_Ialltoall_bruck, -1}},
	     1, {{0, -1, NULL, -1}}
	    }
      };
    
      MPIU_Memcpy(mv2_ialltoall_thresholds_table, mv2_tmp_ialltoall_thresholds_table,
		  mv2_size_ialltoall_tuning_table * sizeof (mv2_ialltoall_tuning_table));
#endif
    return MPI_SUCCESS;
}

void MV2_cleanup_ialltoall_tuning_table()
{
    if (mv2_ialltoall_thresholds_table != NULL) {
	MPIU_Free(mv2_ialltoall_thresholds_table);
    }

}

/* Return the number of separator inside a string */
static int count_sep(char *string)
{
    return *string == '\0' ? 0 : (count_sep(string + 1) + (*string == ','));
}

int MV2_internode_Ialltoall_is_define(char *mv2_user_ialltoall_inter, char *mv2_user_ialltoall_intra)
{

    int i;
    int nb_element = count_sep(mv2_user_ialltoall_inter) + 1;

    /* If one ialltoall tuning table is already defined */
    if (mv2_ialltoall_thresholds_table != NULL) {
	MPIU_Free(mv2_ialltoall_thresholds_table);
    }

    mv2_ialltoall_tuning_table mv2_tmp_ialltoall_thresholds_table[1];
    mv2_size_ialltoall_tuning_table = 1;

    /* We realloc the space for the new ialltoall tuning table */
    mv2_ialltoall_thresholds_table = MPIU_Malloc(mv2_size_ialltoall_tuning_table *
					     sizeof (mv2_ialltoall_tuning_table));

    if (nb_element == 1) {
      //consider removing some fields underneath
	mv2_tmp_ialltoall_thresholds_table[0].numproc = 1;
	mv2_tmp_ialltoall_thresholds_table[0].ialltoall_segment_size = ialltoall_segment_size;
	mv2_tmp_ialltoall_thresholds_table[0].is_two_level_ialltoall[0] = 1;
	mv2_tmp_ialltoall_thresholds_table[0].size_inter_table = 1;
	mv2_tmp_ialltoall_thresholds_table[0].inter_leader[0].min = 0;
	mv2_tmp_ialltoall_thresholds_table[0].inter_leader[0].max = -1;
        mv2_tmp_ialltoall_thresholds_table[0].intra_node[0].min = 0;
        mv2_tmp_ialltoall_thresholds_table[0].intra_node[0].max = -1;
	switch (atoi(mv2_user_ialltoall_inter)) {
	case IALLTOALL_BRUCK:
	    mv2_tmp_ialltoall_thresholds_table[0].inter_leader[0].MV2_pt_Ialltoall_function =
		&MPIR_Ialltoall_bruck;
	    mv2_tmp_ialltoall_thresholds_table[0].is_two_level_ialltoall[0] = 0;
	    break;
	case IALLTOALL_PERM_SR:
	    mv2_tmp_ialltoall_thresholds_table[0].inter_leader[0].MV2_pt_Ialltoall_function =
		&MPIR_Ialltoall_perm_sr;
	    mv2_tmp_ialltoall_thresholds_table[0].is_two_level_ialltoall[0] = 0;
	    break;
	case IALLTOALL_PAIRWISE:
	    mv2_tmp_ialltoall_thresholds_table[0].inter_leader[0].MV2_pt_Ialltoall_function =
		&MPIR_Ialltoall_pairwise;
	    mv2_tmp_ialltoall_thresholds_table[0].is_two_level_ialltoall[0] = 0;
	    break;
	default:
	    mv2_tmp_ialltoall_thresholds_table[0].inter_leader[0].MV2_pt_Ialltoall_function =
		&MPIR_Ialltoall_pairwise;
	    mv2_tmp_ialltoall_thresholds_table[0].is_two_level_ialltoall[0] = 0;
	    break;
	}
	if (mv2_user_ialltoall_intra == NULL) {
	    mv2_tmp_ialltoall_thresholds_table[0].intra_node[0].MV2_pt_Ialltoall_function = NULL;
	} else {
	    mv2_tmp_ialltoall_thresholds_table[0].intra_node[0].MV2_pt_Ialltoall_function = NULL;
	}
    } else {
	char *dup, *p, *save_p;
	regmatch_t match[NMATCH];
	regex_t preg;
	const char *regexp = "([0-9]+):([0-9]+)-([0-9]+|\\+)";

	if (!(dup = MPIU_Strdup(mv2_user_ialltoall_inter))) {
	    fprintf(stderr, "failed to duplicate `%s'\n", mv2_user_ialltoall_inter);
	    return MPI_ERR_INTERN;
	}

	if (regcomp(&preg, regexp, REG_EXTENDED)) {
	    fprintf(stderr, "failed to compile regexp `%s'\n", mv2_user_ialltoall_inter);
	    MPIU_Free(dup);
	    return MPI_ERR_INTERN;
	}

	mv2_tmp_ialltoall_thresholds_table[0].numproc = 1;
	mv2_tmp_ialltoall_thresholds_table[0].ialltoall_segment_size = ialltoall_segment_size;
	mv2_tmp_ialltoall_thresholds_table[0].size_inter_table = nb_element;
	i = 0;
	for (p = strtok_r(dup, ",", &save_p); p; p = strtok_r(NULL, ",", &save_p)) {
	    if (regexec(&preg, p, NMATCH, match, 0)) {
		fprintf(stderr, "failed to match on `%s'\n", p);
		regfree(&preg);
		MPIU_Free(dup);
		return 2;
	    }
	    /* given () start at 1 */
	    switch (atoi(p + match[1].rm_so)) {
	    case IALLTOALL_BRUCK:
	        mv2_tmp_ialltoall_thresholds_table[0].inter_leader[0].MV2_pt_Ialltoall_function =
	            &MPIR_Ialltoall_bruck;
	        mv2_tmp_ialltoall_thresholds_table[0].is_two_level_ialltoall[0] = 0;
	        break;
	    case IALLTOALL_PERM_SR:
	        mv2_tmp_ialltoall_thresholds_table[0].inter_leader[0].MV2_pt_Ialltoall_function =
	            &MPIR_Ialltoall_perm_sr;
	        mv2_tmp_ialltoall_thresholds_table[0].is_two_level_ialltoall[0] = 0;
	        break;
	    case IALLTOALL_PAIRWISE:
	        mv2_tmp_ialltoall_thresholds_table[0].inter_leader[0].MV2_pt_Ialltoall_function =
	  	    &MPIR_Ialltoall_pairwise;
	    default:
	        mv2_tmp_ialltoall_thresholds_table[0].inter_leader[0].MV2_pt_Ialltoall_function =
	        	&MPIR_Ialltoall_pairwise;
	        mv2_tmp_ialltoall_thresholds_table[0].is_two_level_ialltoall[0] = 0;
	        break;
	    }
	    mv2_tmp_ialltoall_thresholds_table[0].inter_leader[i].min = atoi(p +
									 match[2].rm_so);
	    if (p[match[3].rm_so] == '+') {
		mv2_tmp_ialltoall_thresholds_table[0].inter_leader[i].max = -1;
	    } else {
		mv2_tmp_ialltoall_thresholds_table[0].inter_leader[i].max =
		    atoi(p + match[3].rm_so);
	    }

	    i++;
	}
	MPIU_Free(dup);
	regfree(&preg);
    }
    mv2_tmp_ialltoall_thresholds_table[0].size_intra_table = 1;
    if (mv2_user_ialltoall_intra == NULL) {
	mv2_tmp_ialltoall_thresholds_table[0].intra_node[0].MV2_pt_Ialltoall_function = NULL;
    } else {
        mv2_tmp_ialltoall_thresholds_table[0].intra_node[0].MV2_pt_Ialltoall_function = NULL;
    }
    MPIU_Memcpy(mv2_ialltoall_thresholds_table, mv2_tmp_ialltoall_thresholds_table, sizeof
		(mv2_ialltoall_tuning_table));
    return MPI_SUCCESS;
}

int MV2_intranode_Ialltoall_is_define(char *mv2_user_ialltoall_intra)
{

    int i, j;
    for (i = 0; i < mv2_size_ialltoall_tuning_table; i++) {
	for (j = 0; j < mv2_ialltoall_thresholds_table[i].size_intra_table; j++) {
	    mv2_ialltoall_thresholds_table[i].intra_node[j].MV2_pt_Ialltoall_function = NULL;
	}
    }
    return MPI_SUCCESS;
}
