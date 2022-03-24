/*
 * Copyright (c) 2001-2022, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH2 software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH2 directory.
 */

#define GEN2__RI__8PPN { \
	{		\
	8,		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Binomial},		\
	{2, &MPIR_Scatter_MV2_Binomial},		\
	{4, &MPIR_Scatter_MV2_Binomial},		\
	{8, &MPIR_Scatter_MV2_Binomial},		\
	{16, &MPIR_Scatter_MV2_Binomial},		\
	{32, &MPIR_Scatter_MV2_Binomial},		\
	{64, &MPIR_Scatter_MV2_Binomial},		\
	{128, &MPIR_Scatter_MV2_Binomial},		\
	{256, &MPIR_Scatter_MV2_Binomial},		\
	{512, &MPIR_Scatter_MV2_Direct},		\
	{1024, &MPIR_Scatter_MV2_Direct},		\
	{2048, &MPIR_Scatter_MV2_Direct},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_two_level_Direct},		\
	{16384, &MPIR_Scatter_MV2_two_level_Direct},		\
	{32768, &MPIR_Scatter_MV2_two_level_Binomial},		\
	{65536, &MPIR_Scatter_MV2_two_level_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_two_level_Binomial},		\
	{1048576, &MPIR_Scatter_MV2_two_level_Direct}		\
	},		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Direct},		\
	{2, &MPIR_Scatter_MV2_Direct},		\
	{4, &MPIR_Scatter_MV2_Direct},		\
	{8, &MPIR_Scatter_MV2_Direct},		\
	{16, &MPIR_Scatter_MV2_Direct},		\
	{32, &MPIR_Scatter_MV2_Direct},		\
	{64, &MPIR_Scatter_MV2_Direct},		\
	{128, &MPIR_Scatter_MV2_Direct},		\
	{256, &MPIR_Scatter_MV2_Direct},		\
	{512, &MPIR_Scatter_MV2_Direct},		\
	{1024, &MPIR_Scatter_MV2_Direct},		\
	{2048, &MPIR_Scatter_MV2_Direct},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Binomial},		\
	{32768, &MPIR_Scatter_MV2_Binomial},		\
	{65536, &MPIR_Scatter_MV2_Binomial},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Binomial},		\
	{1048576, &MPIR_Scatter_MV2_Binomial}		\
	}		\
	},		\
	{		\
	16,		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Binomial},		\
	{2, &MPIR_Scatter_MV2_Binomial},		\
	{4, &MPIR_Scatter_MV2_Binomial},		\
	{8, &MPIR_Scatter_MV2_Binomial},		\
	{16, &MPIR_Scatter_MV2_Binomial},		\
	{32, &MPIR_Scatter_MV2_Binomial},		\
	{64, &MPIR_Scatter_MV2_Binomial},		\
	{128, &MPIR_Scatter_MV2_Binomial},		\
	{256, &MPIR_Scatter_MV2_Binomial},		\
	{512, &MPIR_Scatter_MV2_Direct},		\
	{1024, &MPIR_Scatter_MV2_Direct},		\
	{2048, &MPIR_Scatter_MV2_Direct},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	},		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Direct},		\
	{2, &MPIR_Scatter_MV2_Direct},		\
	{4, &MPIR_Scatter_MV2_Direct},		\
	{8, &MPIR_Scatter_MV2_Direct},		\
	{16, &MPIR_Scatter_MV2_Direct},		\
	{32, &MPIR_Scatter_MV2_Direct},		\
	{64, &MPIR_Scatter_MV2_Direct},		\
	{128, &MPIR_Scatter_MV2_Direct},		\
	{256, &MPIR_Scatter_MV2_Direct},		\
	{512, &MPIR_Scatter_MV2_Direct},		\
	{1024, &MPIR_Scatter_MV2_Direct},		\
	{2048, &MPIR_Scatter_MV2_Direct},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	}		\
	},		\
	{		\
	32,		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_two_level_Binomial},		\
	{2, &MPIR_Scatter_MV2_two_level_Direct},		\
	{4, &MPIR_Scatter_MV2_two_level_Direct},		\
	{8, &MPIR_Scatter_MV2_two_level_Direct},		\
	{16, &MPIR_Scatter_MV2_two_level_Direct},		\
	{32, &MPIR_Scatter_MV2_two_level_Direct},		\
	{64, &MPIR_Scatter_MV2_two_level_Direct},		\
	{128, &MPIR_Scatter_MV2_two_level_Direct},		\
	{256, &MPIR_Scatter_MV2_two_level_Direct},		\
	{512, &MPIR_Scatter_MV2_two_level_Direct},		\
	{1024, &MPIR_Scatter_MV2_Direct},		\
	{2048, &MPIR_Scatter_MV2_Direct},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	},		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Binomial},		\
	{2, &MPIR_Scatter_MV2_Direct},		\
	{4, &MPIR_Scatter_MV2_Direct},		\
	{8, &MPIR_Scatter_MV2_Direct},		\
	{16, &MPIR_Scatter_MV2_Direct},		\
	{32, &MPIR_Scatter_MV2_Direct},		\
	{64, &MPIR_Scatter_MV2_Direct},		\
	{128, &MPIR_Scatter_MV2_Binomial},		\
	{256, &MPIR_Scatter_MV2_Direct},		\
	{512, &MPIR_Scatter_MV2_Direct},		\
	{1024, &MPIR_Scatter_MV2_Direct},		\
	{2048, &MPIR_Scatter_MV2_Direct},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	}		\
	},		\
	{		\
	64,		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Binomial},		\
	{2, &MPIR_Scatter_MV2_two_level_Direct},		\
	{4, &MPIR_Scatter_MV2_two_level_Direct},		\
	{8, &MPIR_Scatter_MV2_two_level_Direct},		\
	{16, &MPIR_Scatter_MV2_two_level_Direct},		\
	{32, &MPIR_Scatter_MV2_two_level_Direct},		\
	{64, &MPIR_Scatter_MV2_two_level_Direct},		\
	{128, &MPIR_Scatter_MV2_two_level_Direct},		\
	{256, &MPIR_Scatter_MV2_two_level_Direct},		\
	{512, &MPIR_Scatter_MV2_two_level_Direct},		\
	{1024, &MPIR_Scatter_MV2_two_level_Direct},		\
	{2048, &MPIR_Scatter_MV2_two_level_Direct},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	},		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Direct},		\
	{2, &MPIR_Scatter_MV2_Binomial},		\
	{4, &MPIR_Scatter_MV2_Direct},		\
	{8, &MPIR_Scatter_MV2_Binomial},		\
	{16, &MPIR_Scatter_MV2_Binomial},		\
	{32, &MPIR_Scatter_MV2_Direct},		\
	{64, &MPIR_Scatter_MV2_Binomial},		\
	{128, &MPIR_Scatter_MV2_Binomial},		\
	{256, &MPIR_Scatter_MV2_Direct},		\
	{512, &MPIR_Scatter_MV2_Direct},		\
	{1024, &MPIR_Scatter_MV2_Direct},		\
	{2048, &MPIR_Scatter_MV2_Direct},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	}		\
	},		\
	{		\
	128,		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Binomial},		\
	{2, &MPIR_Scatter_MV2_Binomial},		\
	{4, &MPIR_Scatter_MV2_two_level_Direct},		\
	{8, &MPIR_Scatter_MV2_two_level_Direct},		\
	{16, &MPIR_Scatter_MV2_two_level_Direct},		\
	{32, &MPIR_Scatter_MV2_two_level_Direct},		\
	{64, &MPIR_Scatter_MV2_two_level_Direct},		\
	{128, &MPIR_Scatter_MV2_two_level_Direct},		\
	{256, &MPIR_Scatter_MV2_two_level_Direct},		\
	{512, &MPIR_Scatter_MV2_two_level_Direct},		\
	{1024, &MPIR_Scatter_MV2_two_level_Direct},		\
	{2048, &MPIR_Scatter_MV2_two_level_Direct},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	},		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Direct},		\
	{2, &MPIR_Scatter_MV2_Direct},		\
	{4, &MPIR_Scatter_MV2_Binomial},		\
	{8, &MPIR_Scatter_MV2_Binomial},		\
	{16, &MPIR_Scatter_MV2_Binomial},		\
	{32, &MPIR_Scatter_MV2_Binomial},		\
	{64, &MPIR_Scatter_MV2_Binomial},		\
	{128, &MPIR_Scatter_MV2_Binomial},		\
	{256, &MPIR_Scatter_MV2_Binomial},		\
	{512, &MPIR_Scatter_MV2_Direct},		\
	{1024, &MPIR_Scatter_MV2_Direct},		\
	{2048, &MPIR_Scatter_MV2_Direct},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	}		\
	},		\
	{		\
	256,		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Binomial},		\
	{2, &MPIR_Scatter_MV2_Binomial},		\
	{4, &MPIR_Scatter_MV2_two_level_Direct},		\
	{8, &MPIR_Scatter_MV2_two_level_Direct},		\
	{16, &MPIR_Scatter_MV2_two_level_Direct},		\
	{32, &MPIR_Scatter_MV2_two_level_Direct},		\
	{64, &MPIR_Scatter_MV2_two_level_Direct},		\
	{128, &MPIR_Scatter_MV2_two_level_Direct},		\
	{256, &MPIR_Scatter_MV2_two_level_Direct},		\
	{512, &MPIR_Scatter_MV2_two_level_Direct},		\
	{1024, &MPIR_Scatter_MV2_two_level_Direct},		\
	{2048, &MPIR_Scatter_MV2_two_level_Direct},		\
	{4096, &MPIR_Scatter_MV2_two_level_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	},		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Direct},		\
	{2, &MPIR_Scatter_MV2_Direct},		\
	{4, &MPIR_Scatter_MV2_Binomial},		\
	{8, &MPIR_Scatter_MV2_Binomial},		\
	{16, &MPIR_Scatter_MV2_Binomial},		\
	{32, &MPIR_Scatter_MV2_Binomial},		\
	{64, &MPIR_Scatter_MV2_Binomial},		\
	{128, &MPIR_Scatter_MV2_Binomial},		\
	{256, &MPIR_Scatter_MV2_Binomial},		\
	{512, &MPIR_Scatter_MV2_Binomial},		\
	{1024, &MPIR_Scatter_MV2_Binomial},		\
	{2048, &MPIR_Scatter_MV2_Direct},		\
	{4096, &MPIR_Scatter_MV2_Binomial},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	}		\
	},		\
	{		\
	512,		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_two_level_Binomial},		\
	{2, &MPIR_Scatter_MV2_Binomial},		\
	{4, &MPIR_Scatter_MV2_two_level_Binomial},		\
	{8, &MPIR_Scatter_MV2_two_level_Binomial},		\
	{16, &MPIR_Scatter_MV2_Binomial},		\
	{32, &MPIR_Scatter_MV2_Binomial},		\
	{64, &MPIR_Scatter_MV2_two_level_Direct},		\
	{128, &MPIR_Scatter_MV2_two_level_Direct},		\
	{256, &MPIR_Scatter_MV2_two_level_Direct},		\
	{512, &MPIR_Scatter_MV2_two_level_Direct},		\
	{1024, &MPIR_Scatter_MV2_two_level_Direct},		\
	{2048, &MPIR_Scatter_MV2_two_level_Direct},		\
	{4096, &MPIR_Scatter_MV2_two_level_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_two_level_Direct},		\
	{131072, &MPIR_Scatter_MV2_two_level_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	},		\
	20,		\
	{		\
	{1, &MPIR_Scatter_MV2_Binomial},		\
	{2, &MPIR_Scatter_MV2_Direct},		\
	{4, &MPIR_Scatter_MV2_Binomial},		\
	{8, &MPIR_Scatter_MV2_Binomial},		\
	{16, &MPIR_Scatter_MV2_Direct},		\
	{32, &MPIR_Scatter_MV2_Direct},		\
	{64, &MPIR_Scatter_MV2_Binomial},		\
	{128, &MPIR_Scatter_MV2_Binomial},		\
	{256, &MPIR_Scatter_MV2_Binomial},		\
	{512, &MPIR_Scatter_MV2_Binomial},		\
	{1024, &MPIR_Scatter_MV2_Binomial},		\
	{2048, &MPIR_Scatter_MV2_Binomial},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct},		\
	{1048576, &MPIR_Scatter_MV2_Direct}		\
	}		\
	},		\
	{		\
	1024,		\
	19,		\
	{		\
	{1, &MPIR_Scatter_MV2_Binomial},		\
	{2, &MPIR_Scatter_MV2_Binomial},		\
	{4, &MPIR_Scatter_MV2_Binomial},		\
	{8, &MPIR_Scatter_MV2_Binomial},		\
	{16, &MPIR_Scatter_MV2_two_level_Binomial},		\
	{32, &MPIR_Scatter_MV2_Binomial},		\
	{64, &MPIR_Scatter_MV2_Binomial},		\
	{128, &MPIR_Scatter_MV2_two_level_Direct},		\
	{256, &MPIR_Scatter_MV2_two_level_Direct},		\
	{512, &MPIR_Scatter_MV2_two_level_Direct},		\
	{1024, &MPIR_Scatter_MV2_two_level_Direct},		\
	{2048, &MPIR_Scatter_MV2_two_level_Direct},		\
	{4096, &MPIR_Scatter_MV2_two_level_Direct},		\
	{8192, &MPIR_Scatter_MV2_two_level_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_two_level_Direct},		\
	{131072, &MPIR_Scatter_MV2_two_level_Direct},		\
	{262144, &MPIR_Scatter_MV2_two_level_Direct},		\
	{524288, &MPIR_Scatter_MV2_two_level_Direct}		\
	},		\
	19,		\
	{		\
	{1, &MPIR_Scatter_MV2_Direct},		\
	{2, &MPIR_Scatter_MV2_Direct},		\
	{4, &MPIR_Scatter_MV2_Direct},		\
	{8, &MPIR_Scatter_MV2_Direct},		\
	{16, &MPIR_Scatter_MV2_Direct},		\
	{32, &MPIR_Scatter_MV2_Direct},		\
	{64, &MPIR_Scatter_MV2_Direct},		\
	{128, &MPIR_Scatter_MV2_Binomial},		\
	{256, &MPIR_Scatter_MV2_Direct},		\
	{512, &MPIR_Scatter_MV2_Binomial},		\
	{1024, &MPIR_Scatter_MV2_Direct},		\
	{2048, &MPIR_Scatter_MV2_Binomial},		\
	{4096, &MPIR_Scatter_MV2_Direct},		\
	{8192, &MPIR_Scatter_MV2_Direct},		\
	{16384, &MPIR_Scatter_MV2_Direct},		\
	{32768, &MPIR_Scatter_MV2_Direct},		\
	{65536, &MPIR_Scatter_MV2_Direct},		\
	{131072, &MPIR_Scatter_MV2_Direct},		\
	{262144, &MPIR_Scatter_MV2_Direct},		\
	{524288, &MPIR_Scatter_MV2_Direct}		\
	}		\
	}		\
};
