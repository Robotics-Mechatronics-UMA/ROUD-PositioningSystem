/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DEMAIA.c
 *
 * Code generation for function 'DEMAIA'
 *
 */

/* Include files */
#include "DEMAIA.h"
#include "DEMAIA_data.h"
#include "DEMAIA_emxutil.h"
#include "DEMAIA_types.h"
#include "combineVectorElements.h"
#include "diag.h"
#include "eml_int_forloop_overflow_check.h"
#include "isequal.h"
#include "isequaln.h"
#include "ismember.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Type Definitions */
#ifndef typedef_captured_var
#define typedef_captured_var

typedef struct {
  real_T contents;
} captured_var;

#endif                                 /* typedef_captured_var */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 154,   /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 150, /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 144, /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 138, /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 129, /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 126, /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 125, /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 111, /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 106, /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 104, /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 96,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 91,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 88,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 83,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 81,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 72,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 57,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 55,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 43,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 39,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 35,  /* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 6,   /* lineNo */
  "@(p1,p2)sqrt(sum((p2-p1).^2))",     /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 7,   /* lineNo */
  "ref/ref",                           /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/ref.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 63,  /* lineNo */
  "function_handle/parenReference",    /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/function_handle.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 7,  /* lineNo */
  "@(p1,p2)sqrt((abs(abs(p2(1)-p1(1))-abs(p2(2)-p1(2)))+sqrt(2)*min(abs(p2(1)-p1(1)),abs(p2(2)-p1(2))))^2+(Z(p2(1),p2(2))-Z(p1(1),p"
  "1(2)))^2)",                         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 9,  /* lineNo */
  "@(p1,p2)sqrt((abs(abs(p2(1)-p1(1))-abs(p2(2)-p1(2)))+sqrt(2)*min(abs(p2(1)-p1(1)),abs(p2(2)-p1(2))))^2+(Z(p2(1),p2(2))-Z(p1(1),p"
  "1(2)))^2)",                         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 44, /* lineNo */
  "mpower",                            /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/lib/matlab/matfun/mpower.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 71, /* lineNo */
  "power",                             /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 17, /* lineNo */
  "min",                               /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 40, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 90, /* lineNo */
  "minimum",                           /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 173,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 73, /* lineNo */
  "vectorMinOrMaxInPlace",             /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 65, /* lineNo */
  "vectorMinOrMaxInPlace",             /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 114,/* lineNo */
  "findFirst",                         /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 131,/* lineNo */
  "minOrMaxRealVectorKernel",          /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 190,/* lineNo */
  "DEMAIA/entryExitPoints",            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 188,/* lineNo */
  "DEMAIA/entryExitPoints",            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 183,/* lineNo */
  "DEMAIA/entryExitPoints",            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 181,/* lineNo */
  "DEMAIA/entryExitPoints",            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 38, /* lineNo */
  "ismember",                          /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/lib/matlab/ops/ismember.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 241,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 242,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 243,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 245,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 253,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 254,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 256,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 257,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 258,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 259,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 270,/* lineNo */
  "DEMAIA/intersectionPoints",         /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 207,/* lineNo */
  "@(p,p1,p2)p1(3)+((p2(3)-p1(3))*euclidean(p1(1:2),p)/euclidean(p1(1:2),p2(1:2)))",/* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 296,/* lineNo */
  "DEMAIA/segmentCost",                /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 297,/* lineNo */
  "DEMAIA/segmentCost",                /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 308,/* lineNo */
  "DEMAIA/segmentCost",                /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 311,/* lineNo */
  "DEMAIA/segmentCost",                /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 314,/* lineNo */
  "DEMAIA/segmentCost",                /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 322,/* lineNo */
  "DEMAIA/segmentCost",                /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 323,/* lineNo */
  "DEMAIA/segmentCost",                /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 35, /* lineNo */
  "ismember",                          /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/lib/matlab/ops/ismember.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 15, /* lineNo */
  "sum",                               /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 99, /* lineNo */
  "sumprod",                           /* fcnName */
  "/opt/matlab/R2023b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 13,  /* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/toLogicalCheck.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 36,    /* lineNo */
  3,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  29,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  31,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 39,  /* lineNo */
  45,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  45,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 39,  /* lineNo */
  50,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  50,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  32,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  34,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 43,  /* lineNo */
  48,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  48,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 43,  /* lineNo */
  53,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  53,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  22,                                  /* colNo */
  "OPEN",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  47,                                  /* colNo */
  "OPEN",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  23,                                  /* colNo */
  "OPEN",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 83,  /* lineNo */
  43,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  43,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 83,  /* lineNo */
  48,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  48,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  63,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  42,                                  /* colNo */
  "iop",                               /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  54,                                  /* colNo */
  "iop",                               /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  33,                                  /* colNo */
  "ipGTtemp",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  82,                                  /* colNo */
  "ipGT",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  95,                                  /* colNo */
  "ipGT",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  37,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  75,                                  /* colNo */
  "ipGA",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  87,                                  /* colNo */
  "ipGA",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 113, /* lineNo */
  58,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  58,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 113, /* lineNo */
  63,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  63,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 113, /* lineNo */
  12,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  12,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 113, /* lineNo */
  25,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  25,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 119, /* lineNo */
  12,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  119,                                 /* lineNo */
  12,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 119, /* lineNo */
  25,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  119,                                 /* lineNo */
  25,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  126,                                 /* lineNo */
  48,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  126,                                 /* lineNo */
  65,                                  /* colNo */
  "OPEN",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  25,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 131, /* lineNo */
  10,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  10,                                  /* colNo */
  "OPEN",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 138, /* lineNo */
  45,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  138,                                 /* lineNo */
  45,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 138, /* lineNo */
  50,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  138,                                 /* lineNo */
  50,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 143, /* lineNo */
  48,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 143, /* lineNo */
  53,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 146, /* lineNo */
  14,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 146, /* lineNo */
  19,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  146,                                 /* lineNo */
  25,                                  /* colNo */
  "segments{n(1),n(2)}",               /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  146,                                 /* lineNo */
  32,                                  /* colNo */
  "segments{n(1),n(2)}",               /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 145, /* lineNo */
  42,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 145, /* lineNo */
  47,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  145,                                 /* lineNo */
  14,                                  /* colNo */
  "WAYPOINTS",                         /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  145,                                 /* lineNo */
  60,                                  /* colNo */
  "WAYPOINTS",                         /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  145,                                 /* lineNo */
  4,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtDCInfo w_emlrtDCI = { 147, /* lineNo */
  23,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  147,                                 /* lineNo */
  23,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 147, /* lineNo */
  28,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  147,                                 /* lineNo */
  28,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  13,                                  /* colNo */
  "WAYPOINTS",                         /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  151,                                 /* lineNo */
  3,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  152,                                 /* lineNo */
  25,                                  /* colNo */
  "WAYPOINTS",                         /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  152,                                 /* lineNo */
  42,                                  /* colNo */
  "WAYPOINTS",                         /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  143,                                 /* lineNo */
  48,                                  /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  143,                                 /* lineNo */
  53,                                  /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  146,                                 /* lineNo */
  14,                                  /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  146,                                 /* lineNo */
  19,                                  /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  145,                                 /* lineNo */
  42,                                  /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  145,                                 /* lineNo */
  47,                                  /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  120,                                 /* lineNo */
  14,                                  /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 120, /* lineNo */
  14,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  120,                                 /* lineNo */
  27,                                  /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 120,/* lineNo */
  27,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  14,                                  /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 114,/* lineNo */
  14,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  27,                                  /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 114,/* lineNo */
  27,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  8,                                   /* colNo */
  "H",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  10,                                  /* colNo */
  "H",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  4,                                   /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = { 53, /* lineNo */
  4,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  9,                                   /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = { 53, /* lineNo */
  9,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  8,                                   /* colNo */
  "H",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  10,                                  /* colNo */
  "H",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  22,                                  /* colNo */
  "F",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = { 53, /* lineNo */
  22,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  27,                                  /* colNo */
  "F",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = { 53, /* lineNo */
  27,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  74,                                  /* colNo */
  "F",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo hb_emlrtDCI = { 53, /* lineNo */
  74,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  47,                                  /* colNo */
  "CLOSED",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = { 58, /* lineNo */
  47,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  52,                                  /* colNo */
  "CLOSED",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo jb_emlrtDCI = { 58, /* lineNo */
  52,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  3,                                   /* colNo */
  "Z",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo kb_emlrtDCI = { 151,/* lineNo */
  3,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  15,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  54,                                  /* colNo */
  "CLOSED",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo lb_emlrtDCI = { 72, /* lineNo */
  54,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  64,                                  /* colNo */
  "CLOSED",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo mb_emlrtDCI = { 72, /* lineNo */
  64,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  41,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  13,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo nb_emlrtDCI = { 82, /* lineNo */
  13,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  20,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ob_emlrtDCI = { 82, /* lineNo */
  20,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  25,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo pb_emlrtDCI = { 82, /* lineNo */
  25,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  33,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo qb_emlrtDCI = { 82, /* lineNo */
  33,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  40,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo rb_emlrtDCI = { 82, /* lineNo */
  40,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  45,                                  /* colNo */
  "parent",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo sb_emlrtDCI = { 82, /* lineNo */
  45,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  11,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo tb_emlrtDCI = { 103,/* lineNo */
  11,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  16,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ub_emlrtDCI = { 103,/* lineNo */
  16,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  20,                                  /* colNo */
  "ipGA",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  30,                                  /* colNo */
  "ipGA",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  59,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo vb_emlrtDCI = { 111,/* lineNo */
  59,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  64,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  72,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo wb_emlrtDCI = { 111,/* lineNo */
  72,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  77,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  40,                                  /* colNo */
  "ipGA",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  7,                                   /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo xb_emlrtDCI = { 112,/* lineNo */
  7,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  12,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  20,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo yb_emlrtDCI = { 112,/* lineNo */
  20,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  25,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  50,                                  /* colNo */
  "ipGA",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  24,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ac_emlrtDCI = { 117,/* lineNo */
  24,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  29,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  37,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bc_emlrtDCI = { 117,/* lineNo */
  37,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  42,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  7,                                   /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cc_emlrtDCI = { 118,/* lineNo */
  7,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  12,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  20,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo dc_emlrtDCI = { 118,/* lineNo */
  20,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  25,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  119,                                 /* lineNo */
  17,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  119,                                 /* lineNo */
  30,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  38,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ec_emlrtDCI = { 124,/* lineNo */
  38,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  43,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  51,                                  /* colNo */
  "G",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo fc_emlrtDCI = { 124,/* lineNo */
  51,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  56,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  69,                                  /* colNo */
  "H",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo gc_emlrtDCI = { 124,/* lineNo */
  69,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  74,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  82,                                  /* colNo */
  "H",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo hc_emlrtDCI = { 124,/* lineNo */
  82,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  87,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  7,                                   /* colNo */
  "F",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ic_emlrtDCI = { 124,/* lineNo */
  7,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  12,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  20,                                  /* colNo */
  "F",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo jc_emlrtDCI = { 124,/* lineNo */
  20,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  25,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  17,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  120,                                 /* lineNo */
  19,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  30,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  120,                                 /* lineNo */
  32,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  125,                                 /* lineNo */
  39,                                  /* colNo */
  "CLOSED",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo kc_emlrtDCI = { 125,/* lineNo */
  39,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  125,                                 /* lineNo */
  44,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  125,                                 /* lineNo */
  52,                                  /* colNo */
  "CLOSED",                            /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo lc_emlrtDCI = { 125,/* lineNo */
  52,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  125,                                 /* lineNo */
  57,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  19,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  32,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  33,                                  /* colNo */
  "F",                                 /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo mc_emlrtDCI = { 131,/* lineNo */
  33,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  33,                                  /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  120,                                 /* lineNo */
  5,                                   /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo nc_emlrtDCI = { 120,/* lineNo */
  5,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  120,                                 /* lineNo */
  5,                                   /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  5,                                   /* colNo */
  "segments",                          /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo oc_emlrtDCI = { 114,/* lineNo */
  5,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  5,                                   /* colNo */
  "succ",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  23,                                  /* colNo */
  "ipGT",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo df_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  34,                                  /* colNo */
  "ipGT",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ef_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  45,                                  /* colNo */
  "ipGT",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ff_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  56,                                  /* colNo */
  "ipGT",                              /* aName */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/opt/matlab/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtBCInfo gf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  32,                                  /* colNo */
  "Z",                                 /* aName */
  "@(p1,p2)sqrt((abs(abs(p2(1)-p1(1))-abs(p2(2)-p1(2)))+sqrt(2)*min(abs(p2(1)-p1(1)),abs(p2(2)-p1(2))))^2+(Z(p2(1),p2(2))-Z(p1(1),p"
  "1(2)))^2)",                         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo pc_emlrtDCI = { 9,  /* lineNo */
  32,                                  /* colNo */
  "@(p1,p2)sqrt((abs(abs(p2(1)-p1(1))-abs(p2(2)-p1(2)))+sqrt(2)*min(abs(p2(1)-p1(1)),abs(p2(2)-p1(2))))^2+(Z(p2(1),p2(2))-Z(p1(1),p"
  "1(2)))^2)",                         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo hf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  38,                                  /* colNo */
  "Z",                                 /* aName */
  "@(p1,p2)sqrt((abs(abs(p2(1)-p1(1))-abs(p2(2)-p1(2)))+sqrt(2)*min(abs(p2(1)-p1(1)),abs(p2(2)-p1(2))))^2+(Z(p2(1),p2(2))-Z(p1(1),p"
  "1(2)))^2)",                         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo qc_emlrtDCI = { 9,  /* lineNo */
  38,                                  /* colNo */
  "@(p1,p2)sqrt((abs(abs(p2(1)-p1(1))-abs(p2(2)-p1(2)))+sqrt(2)*min(abs(p2(1)-p1(1)),abs(p2(2)-p1(2))))^2+(Z(p2(1),p2(2))-Z(p1(1),p"
  "1(2)))^2)",                         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo if_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  47,                                  /* colNo */
  "Z",                                 /* aName */
  "@(p1,p2)sqrt((abs(abs(p2(1)-p1(1))-abs(p2(2)-p1(2)))+sqrt(2)*min(abs(p2(1)-p1(1)),abs(p2(2)-p1(2))))^2+(Z(p2(1),p2(2))-Z(p1(1),p"
  "1(2)))^2)",                         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  53,                                  /* colNo */
  "Z",                                 /* aName */
  "@(p1,p2)sqrt((abs(abs(p2(1)-p1(1))-abs(p2(2)-p1(2)))+sqrt(2)*min(abs(p2(1)-p1(1)),abs(p2(2)-p1(2))))^2+(Z(p2(1),p2(2))-Z(p1(1),p"
  "1(2)))^2)",                         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  196,                                 /* lineNo */
  50,                                  /* colNo */
  "POINTS",                            /* aName */
  "DEMAIA/entryExitPoints",            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  196,                                 /* lineNo */
  48,                                  /* colNo */
  "POINTS",                            /* aName */
  "DEMAIA/entryExitPoints",            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  191,                                 /* lineNo */
  14,                                  /* colNo */
  "POINTS",                            /* aName */
  "DEMAIA/entryExitPoints",            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  188,                                 /* lineNo */
  36,                                  /* colNo */
  "POINTS",                            /* aName */
  "DEMAIA/entryExitPoints",            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo of_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  188,                                 /* lineNo */
  34,                                  /* colNo */
  "POINTS",                            /* aName */
  "DEMAIA/entryExitPoints",            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  184,                                 /* lineNo */
  14,                                  /* colNo */
  "POINTS",                            /* aName */
  "DEMAIA/entryExitPoints",            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  36,                                  /* colNo */
  "POINTS",                            /* aName */
  "DEMAIA/entryExitPoints",            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  34,                                  /* colNo */
  "POINTS",                            /* aName */
  "DEMAIA/entryExitPoints",            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo rc_emlrtDCI = { 171,/* lineNo */
  19,                                  /* colNo */
  "DEMAIA/entryExitPoints",            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo sc_emlrtDCI = { 171,/* lineNo */
  19,                                  /* colNo */
  "DEMAIA/entryExitPoints",            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo sf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  56,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  52,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  43,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  37,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  30,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  24,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  17,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo tc_emlrtDCI = { 222,/* lineNo */
  17,                                  /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ag_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  13,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo uc_emlrtDCI = { 222,/* lineNo */
  13,                                  /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  219,                                 /* lineNo */
  56,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  219,                                 /* lineNo */
  52,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  219,                                 /* lineNo */
  43,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  219,                                 /* lineNo */
  37,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  219,                                 /* lineNo */
  30,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  219,                                 /* lineNo */
  24,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  219,                                 /* lineNo */
  17,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo vc_emlrtDCI = { 219,/* lineNo */
  17,                                  /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ig_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  219,                                 /* lineNo */
  13,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo wc_emlrtDCI = { 219,/* lineNo */
  13,                                  /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo jg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  211,                                 /* lineNo */
  8,                                   /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo xc_emlrtDCI = { 211,/* lineNo */
  8,                                   /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo kg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  211,                                 /* lineNo */
  17,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  211,                                 /* lineNo */
  28,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  211,                                 /* lineNo */
  41,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ng_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  215,                                 /* lineNo */
  11,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo yc_emlrtDCI = { 215,/* lineNo */
  11,                                  /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo og_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  215,                                 /* lineNo */
  17,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ad_emlrtDCI = { 215,/* lineNo */
  17,                                  /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo pg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  215,                                 /* lineNo */
  32,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bd_emlrtDCI = { 215,/* lineNo */
  32,                                  /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo qg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  215,                                 /* lineNo */
  38,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cd_emlrtDCI = { 215,/* lineNo */
  38,                                  /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo rg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  246,                                 /* lineNo */
  40,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo dd_emlrtDCI = { 246,/* lineNo */
  40,                                  /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo sg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  247,                                 /* lineNo */
  43,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ed_emlrtDCI = { 247,/* lineNo */
  43,                                  /* colNo */
  "DEMAIA/intersectionPoints",         /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo tg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  277,                                 /* lineNo */
  28,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo fd_emlrtDCI = { 277,/* lineNo */
  28,                                  /* colNo */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ug_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  277,                                 /* lineNo */
  33,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo gd_emlrtDCI = { 277,/* lineNo */
  33,                                  /* colNo */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo vg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  279,                                 /* lineNo */
  16,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo hd_emlrtDCI = { 279,/* lineNo */
  16,                                  /* colNo */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo wg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  279,                                 /* lineNo */
  20,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo id_emlrtDCI = { 279,/* lineNo */
  20,                                  /* colNo */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo xg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  279,                                 /* lineNo */
  41,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  279,                                 /* lineNo */
  47,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ah_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  279,                                 /* lineNo */
  54,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  279,                                 /* lineNo */
  58,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ch_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  278,                                 /* lineNo */
  28,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo jd_emlrtDCI = { 278,/* lineNo */
  28,                                  /* colNo */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo dh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  278,                                 /* lineNo */
  32,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo kd_emlrtDCI = { 278,/* lineNo */
  32,                                  /* colNo */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo eh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  278,                                 /* lineNo */
  53,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  278,                                 /* lineNo */
  57,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  278,                                 /* lineNo */
  66,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  278,                                 /* lineNo */
  70,                                  /* colNo */
  "Z",                                 /* aName */
  "DEMAIA/intersectionPoints/computeZ",/* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ih_emlrtBCI = { 1,  /* iFirst */
  3141,                                /* iLast */
  320,                                 /* lineNo */
  29,                                  /* colNo */
  "LUT_vRef.table",                    /* aName */
  "DEMAIA/segmentCost",                /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ld_emlrtDCI = { 320,/* lineNo */
  29,                                  /* colNo */
  "DEMAIA/segmentCost",                /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo jh_emlrtBCI = { 1,  /* iFirst */
  3141,                                /* iLast */
  320,                                 /* lineNo */
  37,                                  /* colNo */
  "LUT_vRef.table",                    /* aName */
  "DEMAIA/segmentCost",                /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo md_emlrtDCI = { 320,/* lineNo */
  37,                                  /* colNo */
  "DEMAIA/segmentCost",                /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo h_emlrtRTEI = { 6, /* lineNo */
  14,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 32,/* lineNo */
  45,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 33,/* lineNo */
  2,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 33,/* lineNo */
  20,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 33,/* lineNo */
  27,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 33,/* lineNo */
  47,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 47,/* lineNo */
  2,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 50,/* lineNo */
  2,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 52,/* lineNo */
  33,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 140,/* lineNo */
  3,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 150,/* lineNo */
  58,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 144,/* lineNo */
  59,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 4, /* lineNo */
  44,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 152,/* lineNo */
  3,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 88,/* lineNo */
  8,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 92,/* lineNo */
  15,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 92,/* lineNo */
  8,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 120,/* lineNo */
  5,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 114,/* lineNo */
  5,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 129,/* lineNo */
  46,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 126,/* lineNo */
  58,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 83,/* lineNo */
  6,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 171,/* lineNo */
  4,                                   /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 196,/* lineNo */
  21,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 181,/* lineNo */
  27,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 188,/* lineNo */
  27,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 197,/* lineNo */
  26,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 183,/* lineNo */
  53,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 190,/* lineNo */
  53,                                  /* colNo */
  "DEMAIA",                            /* fName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pName */
};

static emlrtRSInfo ad_emlrtRSI = { 146,/* lineNo */
  "DEMAIA",                            /* fcnName */
  "/home/imech_uma/shared/SARFISv2024/Matlab functions/DEMAIA planner/DEMAIA.m"/* pathName */
};

/* Function Declarations */
static real_T DEMAIA_anonFcn2(const emlrtStack *sp, const emxArray_real_T *Z,
  const real_T p1[3], const real_T p2[3]);
static real_T computeZ(const emlrtStack *sp, const c_captured_var *Z, const
  real_T p[2]);
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);
static void entryExitPoints(const emlrtStack *sp, const captured_var
  *sizeShortBlock, const real_T p[2], const real_T q[2], emxArray_real_T
  *pointList);
static void intersectionPoints(const emlrtStack *sp, const c_captured_var *Z,
  const real_T x0[2], const real_T xn[2], real_T listPoints_data[], int32_T
  listPoints_size[2]);
static real_T segmentCost(const emlrtStack *sp, const b_captured_var *LUT_vRef,
  const real_T x0[13], const real_T xn[13], real_T *speedRef, real_T
  *proposalSlope, real_T *slope, real_T *tilt);

/* Function Definitions */
static real_T DEMAIA_anonFcn2(const emlrtStack *sp, const emxArray_real_T *Z,
  const real_T p1[3], const real_T p2[3])
{
  emlrtStack st;
  const real_T *Z_data;
  real_T a_tmp;
  real_T b_a_tmp;
  real_T varargout_1;
  st.prev = sp;
  st.tls = sp->tls;
  Z_data = Z->data;
  a_tmp = muDoubleScalarAbs(p2[0] - p1[0]);
  b_a_tmp = muDoubleScalarAbs(p2[1] - p1[1]);
  a_tmp = muDoubleScalarAbs(a_tmp - b_a_tmp) + 1.4142135623730951 *
    muDoubleScalarMin(a_tmp, b_a_tmp);
  st.site = &bb_emlrtRSI;
  if (p2[0] != (int32_T)muDoubleScalarFloor(p2[0])) {
    emlrtIntegerCheckR2012b(p2[0], &pc_emlrtDCI, &st);
  }

  if (((int32_T)p2[0] < 1) || ((int32_T)p2[0] > Z->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)p2[0], 1, Z->size[0], &gf_emlrtBCI,
      &st);
  }

  if (p2[1] != (int32_T)muDoubleScalarFloor(p2[1])) {
    emlrtIntegerCheckR2012b(p2[1], &qc_emlrtDCI, &st);
  }

  if (((int32_T)p2[1] < 1) || ((int32_T)p2[1] > Z->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)p2[1], 1, Z->size[1], &hf_emlrtBCI,
      &st);
  }

  if (((int32_T)p1[0] < 1) || ((int32_T)p1[0] > Z->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)p1[0], 1, Z->size[0], &if_emlrtBCI,
      &st);
  }

  if (((int32_T)p1[1] < 1) || ((int32_T)p1[1] > Z->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)p1[1], 1, Z->size[1], &jf_emlrtBCI,
      &st);
  }

  b_a_tmp = Z_data[((int32_T)p2[0] + Z->size[0] * ((int32_T)p2[1] - 1)) - 1] -
    Z_data[((int32_T)p1[0] + Z->size[0] * ((int32_T)p1[1] - 1)) - 1];
  st.site = &ab_emlrtRSI;
  varargout_1 = a_tmp * a_tmp + b_a_tmp * b_a_tmp;
  if (varargout_1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  return muDoubleScalarSqrt(varargout_1);
}

static real_T computeZ(const emlrtStack *sp, const c_captured_var *Z, const
  real_T p[2])
{
  real_T cc[2];
  real_T b_cc_tmp;
  real_T cc_tmp;
  real_T z;
  int32_T k;
  boolean_T b_p;
  boolean_T exitg1;

  /* ------------------------------------------------------------------------------------------ */
  /* - computing the 3rd dimension (Z axis) of a cell entry/exit point */
  cc_tmp = muDoubleScalarFloor(p[0]);
  cc[0] = cc_tmp;
  b_cc_tmp = muDoubleScalarFloor(p[1]);
  cc[1] = b_cc_tmp;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(p[k] == cc[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    int32_T i;
    int32_T i1;
    k = Z->contents->size[0];
    if (p[0] != (int32_T)cc_tmp) {
      emlrtIntegerCheckR2012b(p[0], &fd_emlrtDCI, (emlrtConstCTX)sp);
    }

    i = (int32_T)p[0];
    if ((p[0] < 1.0) || (i > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)p[0], 1, k, &tg_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    k = Z->contents->size[1];
    if (p[1] != (int32_T)b_cc_tmp) {
      emlrtIntegerCheckR2012b(p[1], &gd_emlrtDCI, (emlrtConstCTX)sp);
    }

    i1 = (int32_T)p[1];
    if ((p[1] < 1.0) || (i1 > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)p[1], 1, k, &ug_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    z = Z->contents->data[(i + Z->contents->size[0] * (i1 - 1)) - 1];
  } else if (p[0] == cc_tmp) {
    k = Z->contents->size[0];
    if (cc_tmp != (int32_T)cc_tmp) {
      emlrtIntegerCheckR2012b(cc_tmp, &jd_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)cc_tmp < 1) || ((int32_T)cc_tmp > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)cc_tmp, 1, k, &ch_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    k = Z->contents->size[1];
    if (b_cc_tmp != (int32_T)b_cc_tmp) {
      emlrtIntegerCheckR2012b(b_cc_tmp, &kd_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)b_cc_tmp < 1) || ((int32_T)b_cc_tmp > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_cc_tmp, 1, k, &dh_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    k = Z->contents->size[0];
    if (((int32_T)cc_tmp < 1) || ((int32_T)cc_tmp > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)cc_tmp, 1, k, &eh_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    k = Z->contents->size[1];
    if (((int32_T)(b_cc_tmp + 1.0) < 1) || ((int32_T)(b_cc_tmp + 1.0) > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_cc_tmp + 1.0), 1, k,
        &fh_emlrtBCI, (emlrtConstCTX)sp);
    }

    k = Z->contents->size[0];
    if (((int32_T)cc_tmp < 1) || ((int32_T)cc_tmp > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)cc_tmp, 1, k, &gh_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    k = Z->contents->size[1];
    if (((int32_T)b_cc_tmp < 1) || ((int32_T)b_cc_tmp > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_cc_tmp, 1, k, &hh_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    z = Z->contents->data[((int32_T)cc_tmp + Z->contents->size[0] * ((int32_T)
      b_cc_tmp - 1)) - 1] + (p[1] - b_cc_tmp) * (Z->contents->data[((int32_T)
      cc_tmp + Z->contents->size[0] * ((int32_T)(b_cc_tmp + 1.0) - 1)) - 1] -
      Z->contents->data[((int32_T)cc_tmp + Z->contents->size[0] * ((int32_T)
      b_cc_tmp - 1)) - 1]);
  } else {
    k = Z->contents->size[0];
    if (cc_tmp != (int32_T)cc_tmp) {
      emlrtIntegerCheckR2012b(cc_tmp, &hd_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)cc_tmp < 1) || ((int32_T)cc_tmp > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)cc_tmp, 1, k, &vg_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    k = Z->contents->size[1];
    if (b_cc_tmp != (int32_T)b_cc_tmp) {
      emlrtIntegerCheckR2012b(b_cc_tmp, &id_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)b_cc_tmp < 1) || ((int32_T)b_cc_tmp > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_cc_tmp, 1, k, &wg_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    k = Z->contents->size[0];
    if (((int32_T)(cc_tmp + 1.0) < 1) || ((int32_T)(cc_tmp + 1.0) > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(cc_tmp + 1.0), 1, k, &xg_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    k = Z->contents->size[1];
    if (((int32_T)b_cc_tmp < 1) || ((int32_T)b_cc_tmp > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_cc_tmp, 1, k, &yg_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    k = Z->contents->size[0];
    if (((int32_T)cc_tmp < 1) || ((int32_T)cc_tmp > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)cc_tmp, 1, k, &ah_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    k = Z->contents->size[1];
    if (((int32_T)b_cc_tmp < 1) || ((int32_T)b_cc_tmp > k)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_cc_tmp, 1, k, &bh_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    z = Z->contents->data[((int32_T)cc_tmp + Z->contents->size[0] * ((int32_T)
      b_cc_tmp - 1)) - 1] + (p[0] - cc_tmp) * (Z->contents->data[((int32_T)
      (cc_tmp + 1.0) + Z->contents->size[0] * ((int32_T)b_cc_tmp - 1)) - 1] -
      Z->contents->data[((int32_T)cc_tmp + Z->contents->size[0] * ((int32_T)
      b_cc_tmp - 1)) - 1]);
  }

  return z;
}

static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(NULL, (emlrtConstCTX)sp);
  } else {
    uint32_T tempAbsQuotient;
    uint32_T u;
    if (numerator < 0) {
      tempAbsQuotient = ~(uint32_T)numerator + 1U;
    } else {
      tempAbsQuotient = (uint32_T)numerator;
    }

    if (denominator < 0) {
      u = ~(uint32_T)denominator + 1U;
    } else {
      u = (uint32_T)denominator;
    }

    tempAbsQuotient /= u;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int32_T)tempAbsQuotient;
    } else {
      quotient = (int32_T)tempAbsQuotient;
    }
  }

  return quotient;
}

static void entryExitPoints(const emlrtStack *sp, const captured_var
  *sizeShortBlock, const real_T p[2], const real_T q[2], emxArray_real_T
  *pointList)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *POINTS;
  emxArray_real_T *b_POINTS;
  real_T a_tmp[2];
  real_T *POINTS_data;
  real_T *pointList_data;
  int32_T i;
  int32_T i1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);

  /* ========================================================================================== */
  /* - NESTED FUNCTIONS */
  /* ========================================================================================== */
  /* ------------------------------------------------------------------------------------------ */
  /* - computing the ordered list of cell entry/exit points between two nodes p and q */
  /* ========================================================================================== */
  /* - compute the cell entry/exit points for a graph edge defined by two given nodes */
  pointList->size[0] = 0;
  pointList->size[1] = 2;
  emxInit_real_T(sp, &POINTS, 2, &eb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_POINTS, 2, &hb_emlrtRTEI, true);
  if ((!muDoubleScalarIsNaN(p[0])) && (!muDoubleScalarIsNaN(p[1]))) {
    real_T a1;
    real_T a2;
    real_T b1;
    real_T b2;
    real_T m;
    int32_T loop_ub;
    int32_T stepX;
    int32_T stepY;
    uint32_T pos_POINTS;
    boolean_T tf;
    if (!(sizeShortBlock->contents >= 0.0)) {
      emlrtNonNegativeCheckR2012b(sizeShortBlock->contents, &rc_emlrtDCI,
        (emlrtConstCTX)sp);
    }

    if (sizeShortBlock->contents != (int32_T)muDoubleScalarFloor
        (sizeShortBlock->contents)) {
      emlrtIntegerCheckR2012b(sizeShortBlock->contents, &sc_emlrtDCI,
        (emlrtConstCTX)sp);
    }

    a_tmp[0] = sizeShortBlock->contents;
    i = POINTS->size[0] * POINTS->size[1];
    POINTS->size[0] = (int32_T)a_tmp[0];
    POINTS->size[1] = 2;
    emxEnsureCapacity_real_T(sp, POINTS, i, &eb_emlrtRTEI);
    POINTS_data = POINTS->data;
    loop_ub = (int32_T)a_tmp[0] << 1;
    for (i = 0; i < loop_ub; i++) {
      POINTS_data[i] = 0.0;
    }

    pos_POINTS = 0U;
    if (q[0] > p[0]) {
      stepX = 1;
    } else if (q[0] < p[0]) {
      stepX = -1;
    } else {
      stepX = 0;
    }

    if (q[1] > p[1]) {
      stepY = 1;
    } else if (q[1] < p[1]) {
      stepY = -1;
    } else {
      stepY = 0;
    }

    m = (q[1] - p[1]) / (q[0] - p[0]);
    a1 = p[0] + (real_T)stepX;
    a2 = p[0] + (real_T)stepY / m;
    b1 = p[1] + (real_T)stepX * m;
    b2 = p[1] + (real_T)stepY;
    if (m == 0.0) {
      a2 = (real_T)stepX * rtInf;
    } else if (muDoubleScalarIsInf(m) || muDoubleScalarIsNaN(m)) {
      b1 = (real_T)stepY * rtInf;
    }

    if (m == 1.0) {
      a2 = q[0];
      b2 = q[1];
    }

    while (!((a1 == q[0]) && (b2 == q[1]))) {
      if (((a1 <= a2) && (stepX > 0)) || ((a1 >= a2) && (stepX < 0))) {
        if ((int32_T)pos_POINTS < 1) {
          loop_ub = 0;
        } else {
          if (POINTS->size[0] < 1) {
            emlrtDynamicBoundsCheckR2012b(1, 1, POINTS->size[0], &rf_emlrtBCI,
              (emlrtConstCTX)sp);
          }

          if (((int32_T)pos_POINTS < 1) || ((int32_T)pos_POINTS > POINTS->size[0]))
          {
            emlrtDynamicBoundsCheckR2012b((int32_T)pos_POINTS, 1, POINTS->size[0],
              &qf_emlrtBCI, (emlrtConstCTX)sp);
          }

          loop_ub = (int32_T)pos_POINTS;
        }

        st.site = &qb_emlrtRSI;
        a_tmp[0] = a1;
        a_tmp[1] = b1;
        i = b_POINTS->size[0] * b_POINTS->size[1];
        b_POINTS->size[0] = loop_ub;
        b_POINTS->size[1] = 2;
        emxEnsureCapacity_real_T(&st, b_POINTS, i, &gb_emlrtRTEI);
        pointList_data = b_POINTS->data;
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            pointList_data[i1 + b_POINTS->size[0] * i] = POINTS_data[i1 +
              POINTS->size[0] * i];
          }
        }

        b_st.site = &rb_emlrtRSI;
        tf = isMemberRows(&b_st, a_tmp, b_POINTS);
        if (!tf) {
          pos_POINTS++;
          if (pos_POINTS > (uint32_T)POINTS->size[0]) {
            i = b_POINTS->size[0] * b_POINTS->size[1];
            b_POINTS->size[0] = POINTS->size[0];
            b_POINTS->size[1] = 2;
            emxEnsureCapacity_real_T(sp, b_POINTS, i, &jb_emlrtRTEI);
            pointList_data = b_POINTS->data;
            loop_ub = POINTS->size[0] * POINTS->size[1] - 1;
            for (i = 0; i <= loop_ub; i++) {
              pointList_data[i] = POINTS_data[i];
            }

            st.site = &pb_emlrtRSI;
            b_repmat(&st, b_POINTS, POINTS);
            POINTS_data = POINTS->data;
          }

          if (((int32_T)pos_POINTS < 1) || ((int32_T)pos_POINTS > POINTS->size[0]))
          {
            emlrtDynamicBoundsCheckR2012b((int32_T)pos_POINTS, 1, POINTS->size[0],
              &pf_emlrtBCI, (emlrtConstCTX)sp);
          }

          POINTS_data[(int32_T)pos_POINTS - 1] = a1;
          POINTS_data[((int32_T)pos_POINTS + POINTS->size[0]) - 1] = b1;
        }

        a1 += (real_T)stepX;
        if ((!muDoubleScalarIsInf(m)) && (!muDoubleScalarIsNaN(m))) {
          b1 = p[1] + (a1 - p[0]) * m;
        }
      } else {
        if ((int32_T)pos_POINTS < 1) {
          loop_ub = 0;
        } else {
          if (POINTS->size[0] < 1) {
            emlrtDynamicBoundsCheckR2012b(1, 1, POINTS->size[0], &of_emlrtBCI,
              (emlrtConstCTX)sp);
          }

          if (((int32_T)pos_POINTS < 1) || ((int32_T)pos_POINTS > POINTS->size[0]))
          {
            emlrtDynamicBoundsCheckR2012b((int32_T)pos_POINTS, 1, POINTS->size[0],
              &nf_emlrtBCI, (emlrtConstCTX)sp);
          }

          loop_ub = (int32_T)pos_POINTS;
        }

        st.site = &ob_emlrtRSI;
        a_tmp[0] = a2;
        a_tmp[1] = b2;
        i = b_POINTS->size[0] * b_POINTS->size[1];
        b_POINTS->size[0] = loop_ub;
        b_POINTS->size[1] = 2;
        emxEnsureCapacity_real_T(&st, b_POINTS, i, &hb_emlrtRTEI);
        pointList_data = b_POINTS->data;
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            pointList_data[i1 + b_POINTS->size[0] * i] = POINTS_data[i1 +
              POINTS->size[0] * i];
          }
        }

        b_st.site = &rb_emlrtRSI;
        tf = isMemberRows(&b_st, a_tmp, b_POINTS);
        if (!tf) {
          pos_POINTS++;
          if (pos_POINTS > (uint32_T)POINTS->size[0]) {
            i = b_POINTS->size[0] * b_POINTS->size[1];
            b_POINTS->size[0] = POINTS->size[0];
            b_POINTS->size[1] = 2;
            emxEnsureCapacity_real_T(sp, b_POINTS, i, &kb_emlrtRTEI);
            pointList_data = b_POINTS->data;
            loop_ub = POINTS->size[0] * POINTS->size[1] - 1;
            for (i = 0; i <= loop_ub; i++) {
              pointList_data[i] = POINTS_data[i];
            }

            st.site = &nb_emlrtRSI;
            b_repmat(&st, b_POINTS, POINTS);
            POINTS_data = POINTS->data;
          }

          if (((int32_T)pos_POINTS < 1) || ((int32_T)pos_POINTS > POINTS->size[0]))
          {
            emlrtDynamicBoundsCheckR2012b((int32_T)pos_POINTS, 1, POINTS->size[0],
              &mf_emlrtBCI, (emlrtConstCTX)sp);
          }

          POINTS_data[(int32_T)pos_POINTS - 1] = a2;
          POINTS_data[((int32_T)pos_POINTS + POINTS->size[0]) - 1] = b2;
        }

        b2 += (real_T)stepY;
        if (m != 0.0) {
          a2 = p[0] + (b2 - p[1]) / m;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }

    if ((int32_T)pos_POINTS > 0) {
      if (POINTS->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, POINTS->size[0], &lf_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      loop_ub = (int32_T)pos_POINTS;
      if (((int32_T)pos_POINTS < 1) || ((int32_T)pos_POINTS > POINTS->size[0]))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)pos_POINTS, 1, POINTS->size[0],
          &kf_emlrtBCI, (emlrtConstCTX)sp);
      }

      i = pointList->size[0] * pointList->size[1];
      pointList->size[0] = (int32_T)pos_POINTS + 2;
      pointList->size[1] = 2;
      emxEnsureCapacity_real_T(sp, pointList, i, &fb_emlrtRTEI);
      pointList_data = pointList->data;
      for (i = 0; i < 2; i++) {
        pointList_data[pointList->size[0] * i] = p[i];
        for (i1 = 0; i1 < loop_ub; i1++) {
          pointList_data[(i1 + pointList->size[0] * i) + 1] = POINTS_data[i1 +
            POINTS->size[0] * i];
        }

        pointList_data[((int32_T)pos_POINTS + pointList->size[0] * i) + 1] = q[i];
      }
    } else {
      boolean_T exitg1;
      tf = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub < 2)) {
        if (!(p[loop_ub] == q[loop_ub])) {
          tf = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }

      if (!tf) {
        i = pointList->size[0] * pointList->size[1];
        pointList->size[0] = 2;
        pointList->size[1] = 2;
        emxEnsureCapacity_real_T(sp, pointList, i, &ib_emlrtRTEI);
        pointList_data = pointList->data;
        pointList_data[0] = p[0];
        pointList_data[1] = q[0];
        pointList_data[2] = p[1];
        pointList_data[3] = q[1];
      }
    }
  }

  emxFree_real_T(sp, &b_POINTS);
  emxFree_real_T(sp, &POINTS);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void intersectionPoints(const emlrtStack *sp, const c_captured_var *Z,
  const real_T x0[2], const real_T xn[2], real_T listPoints_data[], int32_T
  listPoints_size[2])
{
  __m128d r;
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_x0[39];
  real_T POINTS_3D[26];
  real_T z[4];
  real_T perpPoint2[3];
  real_T varargin_2[3];
  real_T aux[2];
  real_T c[2];
  real_T dv[2];
  real_T dv1[2];
  real_T dv2[2];
  real_T dv3[2];
  real_T dv4[2];
  real_T pc[2];
  real_T pointA[2];
  real_T pointB[2];
  real_T y[2];
  real_T perpPoint_idx_0;
  real_T perpPoint_idx_1;
  real_T perpPoint_idx_2;
  real_T segment_idx_0_tmp;
  real_T semiaxe1_idx_0;
  real_T semiaxe1_idx_1;
  real_T z0;
  real_T zA;
  real_T zB;
  real_T zc;
  int32_T POINTS_3D_tmp;
  int32_T Z_tmp;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T pos_POINTS_3D;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;

  /* ------------------------------------------------------------------------------------------ */
  /* - computing the ordered list of diagonal intersections between two cell entry/exit points x0 and xn */
  /* ========================================================================================== */
  /* - inline functions */
  /* - compute the diagonal intersections of a line segment defined by two given cell entry/exit points */
  r = _mm_loadu_pd(&x0[0]);
  r1 = _mm_loadu_pd(&xn[0]);
  _mm_storeu_pd(&dv[0], _mm_div_pd(_mm_add_pd(r, r1), _mm_set1_pd(2.0)));
  dv1[0] = muDoubleScalarFloor(dv[0]);
  dv1[1] = muDoubleScalarFloor(dv[1]);
  r = _mm_loadu_pd(&dv1[0]);
  _mm_storeu_pd(&c[0], r);

  /* - compute the central point of the cell */
  i = Z->contents->size[0];
  i1 = (int32_T)muDoubleScalarFloor(c[0]);
  if (c[0] != i1) {
    emlrtIntegerCheckR2012b(c[0], &xc_emlrtDCI, (emlrtConstCTX)sp);
  }

  i2 = (int32_T)c[0];
  if ((i2 < 1) || (i2 > i)) {
    emlrtDynamicBoundsCheckR2012b(i2, 1, i, &jg_emlrtBCI, (emlrtConstCTX)sp);
  }

  i = Z->contents->size[1];
  pos_POINTS_3D = (int32_T)muDoubleScalarFloor(c[1]);
  if (c[1] != pos_POINTS_3D) {
    emlrtIntegerCheckR2012b(c[1], &xc_emlrtDCI, (emlrtConstCTX)sp);
  }

  POINTS_3D_tmp = (int32_T)c[1];
  if ((POINTS_3D_tmp < 1) || (POINTS_3D_tmp > i)) {
    emlrtDynamicBoundsCheckR2012b(POINTS_3D_tmp, 1, i, &jg_emlrtBCI,
      (emlrtConstCTX)sp);
  }

  z[0] = Z->contents->data[(i2 + Z->contents->size[0] * (POINTS_3D_tmp - 1)) - 1];
  i = Z->contents->size[0];
  i3 = (int32_T)(c[0] + 1.0);
  if ((i3 < 1) || (i3 > i)) {
    emlrtDynamicBoundsCheckR2012b(i3, 1, i, &kg_emlrtBCI, (emlrtConstCTX)sp);
  }

  i = Z->contents->size[1];
  if (POINTS_3D_tmp > i) {
    emlrtDynamicBoundsCheckR2012b(POINTS_3D_tmp, 1, i, &kg_emlrtBCI,
      (emlrtConstCTX)sp);
  }

  z[1] = Z->contents->data[(i3 + Z->contents->size[0] * (POINTS_3D_tmp - 1)) - 1];
  i = Z->contents->size[1];
  Z_tmp = (int32_T)(c[1] + 1.0);
  if ((Z_tmp < 1) || (Z_tmp > i)) {
    emlrtDynamicBoundsCheckR2012b(Z_tmp, 1, i, &lg_emlrtBCI, (emlrtConstCTX)sp);
  }

  z[2] = Z->contents->data[(i3 + Z->contents->size[0] * (Z_tmp - 1)) - 1];
  i = Z->contents->size[0];
  if (i2 > i) {
    emlrtDynamicBoundsCheckR2012b(i2, 1, i, &mg_emlrtBCI, (emlrtConstCTX)sp);
  }

  i = Z->contents->size[1];
  if (Z_tmp > i) {
    emlrtDynamicBoundsCheckR2012b(Z_tmp, 1, i, &mg_emlrtBCI, (emlrtConstCTX)sp);
  }

  z[3] = Z->contents->data[(i2 + Z->contents->size[0] * (Z_tmp - 1)) - 1];
  zc = b_sumColumnB(z) / 4.0;

  /* - computing cost function */
  r = _mm_loadu_pd(&c[0]);
  r1 = _mm_set1_pd(0.5);
  _mm_storeu_pd(&pc[0], _mm_add_pd(r, r1));
  z0 = muDoubleScalarFloor(x0[0]);
  dv2[0] = z0;
  segment_idx_0_tmp = muDoubleScalarFloor(x0[1]);
  dv2[1] = segment_idx_0_tmp;
  r = _mm_loadu_pd(&dv2[0]);
  _mm_storeu_pd(&aux[0], r);
  guard1 = false;
  if (isequal(x0, aux)) {
    zB = xn[0];
    zA = muDoubleScalarFloor(zB);
    y[0] = zA;
    zB = xn[1];
    zB = muDoubleScalarFloor(zB);
    y[1] = zB;
    if (isequal(xn, y)) {
      int32_T i4;
      int32_T i5;
      i = Z->contents->size[0];
      if (x0[0] != (int32_T)z0) {
        emlrtIntegerCheckR2012b(x0[0], &yc_emlrtDCI, (emlrtConstCTX)sp);
      }

      i4 = (int32_T)x0[0];
      if ((i4 < 1) || (i4 > i)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, i, &ng_emlrtBCI, (emlrtConstCTX)sp);
      }

      i = Z->contents->size[1];
      if (x0[1] != (int32_T)segment_idx_0_tmp) {
        emlrtIntegerCheckR2012b(x0[1], &ad_emlrtDCI, (emlrtConstCTX)sp);
      }

      i5 = (int32_T)x0[1];
      if ((i5 < 1) || (i5 > i)) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i, &og_emlrtBCI, (emlrtConstCTX)sp);
      }

      z0 = Z->contents->data[(i4 + Z->contents->size[0] * (i5 - 1)) - 1];
      i = Z->contents->size[0];
      if (xn[0] != (int32_T)zA) {
        emlrtIntegerCheckR2012b(xn[0], &bd_emlrtDCI, (emlrtConstCTX)sp);
      }

      i4 = (int32_T)xn[0];
      if ((i4 < 1) || (i4 > i)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, i, &pg_emlrtBCI, (emlrtConstCTX)sp);
      }

      i = Z->contents->size[1];
      if (xn[1] != (int32_T)zB) {
        emlrtIntegerCheckR2012b(xn[1], &cd_emlrtDCI, (emlrtConstCTX)sp);
      }

      i5 = (int32_T)xn[1];
      if ((i5 < 1) || (i5 > i)) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i, &qg_emlrtBCI, (emlrtConstCTX)sp);
      }

      zA = Z->contents->data[(i4 + Z->contents->size[0] * (i5 - 1)) - 1];
      if ((x0[0] == xn[0]) || (x0[1] == xn[1])) {
        /* - adjacent and not opposite nodes */
        aux[0] = c[0] - 1.0;
        aux[1] = c[1];
        i = Z->contents->size[0];
        if (aux[0] != (int32_T)muDoubleScalarFloor(aux[0])) {
          emlrtIntegerCheckR2012b(aux[0], &wc_emlrtDCI, (emlrtConstCTX)sp);
        }

        i4 = (int32_T)aux[0];
        if ((i4 < 1) || (i4 > i)) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, i, &ig_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        i = Z->contents->size[1];
        if (aux[1] != pos_POINTS_3D) {
          emlrtIntegerCheckR2012b(aux[1], &vc_emlrtDCI, (emlrtConstCTX)sp);
        }

        if (POINTS_3D_tmp > i) {
          emlrtDynamicBoundsCheckR2012b(POINTS_3D_tmp, 1, i, &hg_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        i = Z->contents->size[0];
        pos_POINTS_3D = (int32_T)(aux[0] + 1.0);
        if ((pos_POINTS_3D < 1) || (pos_POINTS_3D > i)) {
          emlrtDynamicBoundsCheckR2012b(pos_POINTS_3D, 1, i, &gg_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        i = Z->contents->size[1];
        if (POINTS_3D_tmp > i) {
          emlrtDynamicBoundsCheckR2012b(POINTS_3D_tmp, 1, i, &fg_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        i = Z->contents->size[0];
        if (pos_POINTS_3D > i) {
          emlrtDynamicBoundsCheckR2012b(pos_POINTS_3D, 1, i, &eg_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        i = Z->contents->size[1];
        if (Z_tmp > i) {
          emlrtDynamicBoundsCheckR2012b(Z_tmp, 1, i, &dg_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        i = Z->contents->size[0];
        if (i4 > i) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, i, &cg_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        i = Z->contents->size[1];
        if (Z_tmp > i) {
          emlrtDynamicBoundsCheckR2012b(Z_tmp, 1, i, &bg_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        pos_POINTS_3D = (int32_T)aux[1] - 1;
        POINTS_3D_tmp = (int32_T)aux[0] - 1;
        z[0] = Z->contents->data[POINTS_3D_tmp + Z->contents->size[0] *
          pos_POINTS_3D];
        Z_tmp = (int32_T)(aux[0] + 1.0) - 1;
        z[1] = Z->contents->data[Z_tmp + Z->contents->size[0] * pos_POINTS_3D];
        pos_POINTS_3D = (int32_T)(aux[1] + 1.0) - 1;
        z[2] = Z->contents->data[Z_tmp + Z->contents->size[0] * pos_POINTS_3D];
        z[3] = Z->contents->data[POINTS_3D_tmp + Z->contents->size[0] *
          pos_POINTS_3D];
        semiaxe1_idx_0 = aux[0] + 0.5;
        aux[0] = c[0];
        semiaxe1_idx_1 = aux[1] + 0.5;
        aux[1] = c[1] - 1.0;
        i = Z->contents->size[0];
        if (aux[0] != i1) {
          emlrtIntegerCheckR2012b(aux[0], &uc_emlrtDCI, (emlrtConstCTX)sp);
        }

        if (i2 > i) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i, &ag_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        i = Z->contents->size[1];
        if (aux[1] != (int32_T)muDoubleScalarFloor(aux[1])) {
          emlrtIntegerCheckR2012b(aux[1], &tc_emlrtDCI, (emlrtConstCTX)sp);
        }

        i1 = (int32_T)aux[1];
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &yf_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        i = Z->contents->size[0];
        if ((i3 < 1) || (i3 > i)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, i, &xf_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        i = Z->contents->size[1];
        if (i1 > i) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wf_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        i = Z->contents->size[0];
        if (i3 > i) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, i, &vf_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        i = Z->contents->size[1];
        i1 = (int32_T)(aux[1] + 1.0);
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &uf_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        i = Z->contents->size[0];
        if (i2 > i) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i, &tf_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        i = Z->contents->size[1];
        if (i1 > i) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &sf_emlrtBCI, (emlrtConstCTX)
            sp);
        }

        if (x0[0] == xn[0]) {
          perpPoint2[0] = semiaxe1_idx_0;
          perpPoint2[1] = semiaxe1_idx_1;
          perpPoint2[2] = b_sumColumnB(z) / 4.0;
        } else {
          pos_POINTS_3D = (int32_T)aux[1] - 1;
          POINTS_3D_tmp = (int32_T)aux[0] - 1;
          z[0] = Z->contents->data[POINTS_3D_tmp + Z->contents->size[0] *
            pos_POINTS_3D];
          Z_tmp = (int32_T)(aux[0] + 1.0) - 1;
          z[1] = Z->contents->data[Z_tmp + Z->contents->size[0] * pos_POINTS_3D];
          pos_POINTS_3D = (int32_T)(aux[1] + 1.0) - 1;
          z[2] = Z->contents->data[Z_tmp + Z->contents->size[0] * pos_POINTS_3D];
          z[3] = Z->contents->data[POINTS_3D_tmp + Z->contents->size[0] *
            pos_POINTS_3D];
          r = _mm_loadu_pd(&aux[0]);
          _mm_storeu_pd(&perpPoint2[0], _mm_add_pd(r, r1));
          perpPoint2[2] = b_sumColumnB(z) / 4.0;
        }

        POINTS_3D[0] = x0[0];
        POINTS_3D[2] = x0[1];
        POINTS_3D[4] = z0;
        POINTS_3D[6] = rtNaN;
        POINTS_3D[8] = rtNaN;
        POINTS_3D[10] = rtNaN;
        POINTS_3D[12] = rtNaN;
        POINTS_3D[14] = rtNaN;
        POINTS_3D[20] = rtNaN;
        POINTS_3D[16] = rtNaN;
        POINTS_3D[22] = rtNaN;
        POINTS_3D[18] = rtNaN;
        POINTS_3D[24] = rtNaN;
        POINTS_3D[1] = xn[0];
        POINTS_3D[3] = xn[1];
        POINTS_3D[5] = zA;
        POINTS_3D[7] = rtNaN;
        POINTS_3D[9] = rtNaN;
        POINTS_3D[11] = rtNaN;
        POINTS_3D[13] = rtNaN;
        POINTS_3D[15] = pc[0];
        POINTS_3D[17] = pc[1];
        POINTS_3D[19] = zc;
        POINTS_3D[21] = perpPoint2[0];
        POINTS_3D[23] = perpPoint2[1];
        POINTS_3D[25] = perpPoint2[2];
        listPoints_size[0] = 2;
        listPoints_size[1] = 13;
        memcpy(&listPoints_data[0], &POINTS_3D[0], 26U * sizeof(real_T));
      } else {
        /* - adjacent and opposite nodes */
        aux[0] = c[0];
        aux[1] = c[1];
        if (isequal(x0, aux)) {
          perpPoint_idx_0 = c[0] + 1.0;
          perpPoint_idx_1 = c[1];
          perpPoint_idx_2 = z[1];
          perpPoint2[0] = c[0];
          perpPoint2[1] = c[1] + 1.0;
          perpPoint2[2] = z[3];
        } else {
          aux[0] = c[0] + 1.0;
          aux[1] = c[1];
          if (isequal(x0, aux)) {
            perpPoint_idx_0 = c[0] + 1.0;
            perpPoint_idx_1 = c[1] + 1.0;
            perpPoint_idx_2 = z[2];
            perpPoint2[0] = c[0];
            perpPoint2[1] = c[1];
            perpPoint2[2] = z[0];
          } else {
            aux[0] = c[0] + 1.0;
            aux[1] = c[1] + 1.0;
            if (isequal(x0, aux)) {
              perpPoint_idx_0 = c[0];
              perpPoint_idx_1 = c[1] + 1.0;
              perpPoint_idx_2 = z[3];
              perpPoint2[0] = c[0] + 1.0;
              perpPoint2[1] = c[1];
              perpPoint2[2] = z[1];
            } else {
              perpPoint_idx_0 = c[0];
              perpPoint_idx_1 = c[1];
              perpPoint_idx_2 = z[0];
              perpPoint2[0] = c[0] + 1.0;
              perpPoint2[1] = c[1] + 1.0;
              perpPoint2[2] = z[2];
            }
          }
        }

        b_x0[0] = x0[0];
        b_x0[3] = x0[1];
        b_x0[6] = z0;
        b_x0[9] = rtNaN;
        b_x0[12] = rtNaN;
        b_x0[15] = rtNaN;
        b_x0[18] = rtNaN;
        b_x0[21] = rtNaN;
        b_x0[30] = rtNaN;
        b_x0[24] = rtNaN;
        b_x0[33] = rtNaN;
        b_x0[27] = rtNaN;
        b_x0[36] = rtNaN;
        b_x0[1] = pc[0];
        b_x0[4] = pc[1];
        b_x0[7] = zc;
        b_x0[10] = rtNaN;
        b_x0[13] = rtNaN;
        b_x0[16] = rtNaN;
        b_x0[19] = rtNaN;
        b_x0[22] = perpPoint_idx_0;
        b_x0[31] = perpPoint2[0];
        b_x0[25] = perpPoint_idx_1;
        b_x0[34] = perpPoint2[1];
        b_x0[28] = perpPoint_idx_2;
        b_x0[37] = perpPoint2[2];
        b_x0[2] = xn[0];
        b_x0[5] = xn[1];
        b_x0[8] = zA;
        b_x0[11] = rtNaN;
        b_x0[14] = rtNaN;
        b_x0[17] = rtNaN;
        b_x0[20] = rtNaN;
        b_x0[23] = perpPoint_idx_0;
        b_x0[32] = perpPoint2[0];
        b_x0[26] = perpPoint_idx_1;
        b_x0[35] = perpPoint2[1];
        b_x0[29] = perpPoint_idx_2;
        b_x0[38] = perpPoint2[2];
        listPoints_size[0] = 3;
        listPoints_size[1] = 13;
        memcpy(&listPoints_data[0], &b_x0[0], 39U * sizeof(real_T));
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    emlrtStack *r2;
    emlrtStack *r3;
    real_T perpPoint_xn_idx_0;
    real_T perpPoint_xn_idx_1;
    real_T perpPoint_xn_idx_2;
    real_T segment_idx_0;
    real_T segment_idx_1;

    /* - one node and another any-theta path point, or two any-theta path points */
    memset(&POINTS_3D[0], 0, 26U * sizeof(real_T));
    pos_POINTS_3D = 0;
    perpPoint2[0] = pc[0];
    perpPoint2[1] = pc[1];
    perpPoint2[2] = zc;
    perpPoint_idx_0 = perpPoint2[0];
    perpPoint_xn_idx_0 = perpPoint2[0];
    perpPoint_idx_1 = perpPoint2[1];
    perpPoint_xn_idx_1 = perpPoint2[1];
    perpPoint_idx_2 = perpPoint2[2];
    perpPoint_xn_idx_2 = perpPoint2[2];
    z0 = xn[1] - x0[1];
    segment_idx_0_tmp = xn[0] - x0[0];
    segment_idx_0 = z0 / segment_idx_0_tmp;
    segment_idx_1 = x0[1] - x0[0] * z0 / segment_idx_0_tmp;
    pointB[0] = c[0];
    pointB[1] = c[1];
    zA = c[0] + 1.0;
    segment_idx_0_tmp = c[1] + 1.0;
    segment_idx_0_tmp -= pointB[1];
    zc = zA - pointB[0];
    semiaxe1_idx_0 = segment_idx_0_tmp / zc;
    semiaxe1_idx_1 = pointB[1] - pointB[0] * segment_idx_0_tmp / zc;
    segment_idx_0_tmp = segment_idx_1 - semiaxe1_idx_1;
    zB = semiaxe1_idx_0 - segment_idx_0;
    pointA[0] = segment_idx_0_tmp / zB;
    pointA[1] = semiaxe1_idx_1 + semiaxe1_idx_0 * segment_idx_0_tmp / zB;
    st.site = &vb_emlrtRSI;
    b_st.site = &cb_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    st.site = &vb_emlrtRSI;
    dv3[0] = muDoubleScalarFloor(pointA[0]);
    dv3[1] = muDoubleScalarFloor(pointA[1]);
    r = _mm_loadu_pd(&dv3[0]);
    r1 = _mm_loadu_pd(&c[0]);
    r = _mm_sub_pd(r, r1);
    _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
    z0 = c_sumColumnB(y);
    b_st.site = &v_emlrtRSI;
    if (z0 < 0.0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    z0 = muDoubleScalarSqrt(z0);
    if (z0 < 1.0E-10) {
      st.site = &vb_emlrtRSI;
      b_st.site = &cb_emlrtRSI;
      c_st.site = &db_emlrtRSI;
      st.site = &vb_emlrtRSI;
      r = _mm_loadu_pd(&pointA[0]);
      r1 = _mm_loadu_pd(&x0[0]);
      r = _mm_sub_pd(r, r1);
      _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
      z0 = c_sumColumnB(y);
      b_st.site = &v_emlrtRSI;
      if (z0 < 0.0) {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      z0 = muDoubleScalarSqrt(z0);
      if (!(z0 < 1.0E-10)) {
        st.site = &vb_emlrtRSI;
        b_st.site = &cb_emlrtRSI;
        c_st.site = &db_emlrtRSI;
        st.site = &vb_emlrtRSI;
        r = _mm_loadu_pd(&pointA[0]);
        r1 = _mm_loadu_pd(&xn[0]);
        r = _mm_sub_pd(r, r1);
        _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
        z0 = c_sumColumnB(y);
        b_st.site = &v_emlrtRSI;
        if (z0 < 0.0) {
          emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
            "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
            3, 4, 4, "sqrt");
        }

        z0 = muDoubleScalarSqrt(z0);
        if (!(z0 < 1.0E-10)) {
          if (pointA[0] < c[0] + 0.5) {
            st.site = &wb_emlrtRSI;
            varargin_2[0] = c[0];
            varargin_2[1] = c[1];
            varargin_2[2] = z[0];
            b_st.site = &x_emlrtRSI;
            c_st.site = &hc_emlrtRSI;
            r = _mm_loadu_pd(&pointA[0]);
            r1 = _mm_loadu_pd(&varargin_2[0]);
            r = _mm_sub_pd(r, r1);
            _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
            z0 = c_sumColumnB(y);
            d_st.site = &v_emlrtRSI;
            if (z0 < 0.0) {
              emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
                "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }

            z0 = muDoubleScalarSqrt(z0);
            c_st.site = &hc_emlrtRSI;
            r = _mm_loadu_pd(&perpPoint2[0]);
            r1 = _mm_loadu_pd(&varargin_2[0]);
            r = _mm_sub_pd(r, r1);
            _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
            segment_idx_0_tmp = c_sumColumnB(y);
            d_st.site = &v_emlrtRSI;
            if (segment_idx_0_tmp < 0.0) {
              emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
                "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }

            segment_idx_0_tmp = muDoubleScalarSqrt(segment_idx_0_tmp);
            zA = varargin_2[2] + (perpPoint2[2] - varargin_2[2]) * z0 /
              segment_idx_0_tmp;
          } else {
            st.site = &xb_emlrtRSI;
            varargin_2[0] = c[0] + 1.0;
            varargin_2[1] = c[1] + 1.0;
            varargin_2[2] = z[2];
            b_st.site = &x_emlrtRSI;
            c_st.site = &hc_emlrtRSI;
            r = _mm_loadu_pd(&pointA[0]);
            r1 = _mm_loadu_pd(&varargin_2[0]);
            r = _mm_sub_pd(r, r1);
            _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
            z0 = c_sumColumnB(y);
            d_st.site = &v_emlrtRSI;
            if (z0 < 0.0) {
              emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
                "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }

            z0 = muDoubleScalarSqrt(z0);
            c_st.site = &hc_emlrtRSI;
            r = _mm_loadu_pd(&perpPoint2[0]);
            r1 = _mm_loadu_pd(&varargin_2[0]);
            r = _mm_sub_pd(r, r1);
            _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
            segment_idx_0_tmp = c_sumColumnB(y);
            d_st.site = &v_emlrtRSI;
            if (segment_idx_0_tmp < 0.0) {
              emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
                "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }

            segment_idx_0_tmp = muDoubleScalarSqrt(segment_idx_0_tmp);
            zA = varargin_2[2] + (perpPoint2[2] - varargin_2[2]) * z0 /
              segment_idx_0_tmp;
          }

          st.site = &yb_emlrtRSI;
          b_st.site = &cb_emlrtRSI;
          c_st.site = &db_emlrtRSI;
          st.site = &yb_emlrtRSI;
          r = _mm_loadu_pd(&pc[0]);
          r1 = _mm_loadu_pd(&pointA[0]);
          r = _mm_sub_pd(r, r1);
          _mm_storeu_pd(&pc[0], r);
          _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
          z0 = c_sumColumnB(y);
          b_st.site = &v_emlrtRSI;
          if (z0 < 0.0) {
            emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          z0 = muDoubleScalarSqrt(z0);
          if (z0 < 1.0E-10) {
            perpPoint_idx_0 = aux[0];
            perpPoint_idx_1 = aux[1];
            i = Z->contents->size[0];
            if (aux[0] != (int32_T)muDoubleScalarFloor(aux[0])) {
              emlrtIntegerCheckR2012b(aux[0], &dd_emlrtDCI, (emlrtConstCTX)sp);
            }

            i1 = (int32_T)aux[0];
            if ((i1 < 1) || (i1 > i)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &rg_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            i = Z->contents->size[1];
            if (aux[1] != (int32_T)muDoubleScalarFloor(aux[1])) {
              emlrtIntegerCheckR2012b(aux[1], &dd_emlrtDCI, (emlrtConstCTX)sp);
            }

            i2 = (int32_T)aux[1];
            if ((i2 < 1) || (i2 > i)) {
              emlrtDynamicBoundsCheckR2012b(i2, 1, i, &rg_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            perpPoint_idx_2 = Z->contents->data[(i1 + Z->contents->size[0] * (i2
              - 1)) - 1];
            perpPoint_xn_idx_1 = xn[0];
            perpPoint_xn_idx_1 = muDoubleScalarFloor(perpPoint_xn_idx_1);
            aux[0] = perpPoint_xn_idx_1;
            perpPoint_xn_idx_0 = perpPoint_xn_idx_1;
            perpPoint_xn_idx_1 = xn[1];
            perpPoint_xn_idx_1 = muDoubleScalarFloor(perpPoint_xn_idx_1);
            aux[1] = perpPoint_xn_idx_1;
            i = Z->contents->size[0];
            if (aux[0] != (int32_T)muDoubleScalarFloor(aux[0])) {
              emlrtIntegerCheckR2012b(aux[0], &ed_emlrtDCI, (emlrtConstCTX)sp);
            }

            i1 = (int32_T)aux[0];
            if ((i1 < 1) || (i1 > i)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &sg_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            i = Z->contents->size[1];
            if (aux[1] != (int32_T)muDoubleScalarFloor(aux[1])) {
              emlrtIntegerCheckR2012b(aux[1], &ed_emlrtDCI, (emlrtConstCTX)sp);
            }

            i2 = (int32_T)aux[1];
            if ((i2 < 1) || (i2 > i)) {
              emlrtDynamicBoundsCheckR2012b(i2, 1, i, &sg_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            perpPoint_xn_idx_2 = Z->contents->data[(i1 + Z->contents->size[0] *
              (i2 - 1)) - 1];
          }

          pos_POINTS_3D = 1;
          POINTS_3D[0] = pointA[0];
          POINTS_3D[2] = pointA[1];
          POINTS_3D[4] = zA;
          POINTS_3D[6] = rtNaN;
          POINTS_3D[8] = rtNaN;
          POINTS_3D[10] = rtNaN;
          POINTS_3D[12] = rtNaN;
          POINTS_3D[14] = perpPoint_idx_0;
          POINTS_3D[20] = rtNaN;
          POINTS_3D[16] = perpPoint_idx_1;
          POINTS_3D[22] = rtNaN;
          POINTS_3D[18] = perpPoint_idx_2;
          POINTS_3D[24] = rtNaN;
        }
      }
    }

    pointB[0] = c[0];
    pointB[1] = c[1] + 1.0;
    segment_idx_0_tmp = c[1];
    zA = segment_idx_0_tmp - pointB[1];
    aux[0] = zA / zc;
    aux[1] = pointB[1] - pointB[0] * zA / zc;
    zA = segment_idx_1 - aux[1];
    zB = aux[0] - segment_idx_0;
    pointB[0] = zA / zB;
    pointB[1] = aux[1] + aux[0] * zA / zB;
    if (pointB[0] < c[0] + 0.5) {
      st.site = &ac_emlrtRSI;
      varargin_2[0] = c[0];
      varargin_2[1] = c[1] + 1.0;
      varargin_2[2] = z[3];
      b_st.site = &x_emlrtRSI;
      c_st.site = &hc_emlrtRSI;
      r = _mm_loadu_pd(&pointB[0]);
      r1 = _mm_loadu_pd(&varargin_2[0]);
      r = _mm_sub_pd(r, r1);
      _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
      z0 = c_sumColumnB(y);
      d_st.site = &v_emlrtRSI;
      if (z0 < 0.0) {
        emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      z0 = muDoubleScalarSqrt(z0);
      c_st.site = &hc_emlrtRSI;
      r = _mm_loadu_pd(&perpPoint2[0]);
      r1 = _mm_loadu_pd(&varargin_2[0]);
      r = _mm_sub_pd(r, r1);
      _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
      segment_idx_0_tmp = c_sumColumnB(y);
      d_st.site = &v_emlrtRSI;
      if (segment_idx_0_tmp < 0.0) {
        emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      segment_idx_0_tmp = muDoubleScalarSqrt(segment_idx_0_tmp);
      zB = varargin_2[2] + (perpPoint2[2] - varargin_2[2]) * z0 /
        segment_idx_0_tmp;
    } else {
      st.site = &bc_emlrtRSI;
      varargin_2[0] = c[0] + 1.0;
      varargin_2[1] = c[1];
      varargin_2[2] = z[1];
      b_st.site = &x_emlrtRSI;
      c_st.site = &hc_emlrtRSI;
      r = _mm_loadu_pd(&pointB[0]);
      r1 = _mm_loadu_pd(&varargin_2[0]);
      r = _mm_sub_pd(r, r1);
      _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
      z0 = c_sumColumnB(y);
      d_st.site = &v_emlrtRSI;
      if (z0 < 0.0) {
        emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      z0 = muDoubleScalarSqrt(z0);
      c_st.site = &hc_emlrtRSI;
      r = _mm_loadu_pd(&perpPoint2[0]);
      r1 = _mm_loadu_pd(&varargin_2[0]);
      r = _mm_sub_pd(r, r1);
      _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
      segment_idx_0_tmp = c_sumColumnB(y);
      d_st.site = &v_emlrtRSI;
      if (segment_idx_0_tmp < 0.0) {
        emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      segment_idx_0_tmp = muDoubleScalarSqrt(segment_idx_0_tmp);
      zB = varargin_2[2] + (perpPoint2[2] - varargin_2[2]) * z0 /
        segment_idx_0_tmp;
    }

    st.site = &cc_emlrtRSI;
    b_st.site = &cb_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    st.site = &cc_emlrtRSI;
    dv4[0] = muDoubleScalarFloor(pointB[0]);
    dv4[1] = muDoubleScalarFloor(pointB[1]);
    r = _mm_loadu_pd(&dv4[0]);
    r1 = _mm_loadu_pd(&c[0]);
    r = _mm_sub_pd(r, r1);
    _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
    z0 = c_sumColumnB(y);
    b_st.site = &v_emlrtRSI;
    if (z0 < 0.0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    z0 = muDoubleScalarSqrt(z0);
    if (z0 < 1.0E-10) {
      st.site = &dc_emlrtRSI;
      b_st.site = &cb_emlrtRSI;
      c_st.site = &db_emlrtRSI;
      st.site = &dc_emlrtRSI;
      r = _mm_loadu_pd(&pointB[0]);
      r1 = _mm_loadu_pd(&pointA[0]);
      r = _mm_sub_pd(r, r1);
      _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
      z0 = c_sumColumnB(y);
      b_st.site = &v_emlrtRSI;
      if (z0 < 0.0) {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      z0 = muDoubleScalarSqrt(z0);
      if (!(z0 < 1.0E-10)) {
        st.site = &dc_emlrtRSI;
        b_st.site = &cb_emlrtRSI;
        c_st.site = &db_emlrtRSI;
        st.site = &dc_emlrtRSI;
        r = _mm_loadu_pd(&pointB[0]);
        r1 = _mm_loadu_pd(&x0[0]);
        r = _mm_sub_pd(r, r1);
        _mm_storeu_pd(&aux[0], r);
        _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
        z0 = c_sumColumnB(y);
        b_st.site = &v_emlrtRSI;
        if (z0 < 0.0) {
          emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
            "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
            3, 4, 4, "sqrt");
        }

        z0 = muDoubleScalarSqrt(z0);
        if (!(z0 < 1.0E-10)) {
          st.site = &dc_emlrtRSI;
          b_st.site = &cb_emlrtRSI;
          c_st.site = &db_emlrtRSI;
          st.site = &dc_emlrtRSI;
          r = _mm_loadu_pd(&pointB[0]);
          r1 = _mm_loadu_pd(&xn[0]);
          r = _mm_sub_pd(r, r1);
          _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
          z0 = c_sumColumnB(y);
          b_st.site = &v_emlrtRSI;
          if (z0 < 0.0) {
            emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          z0 = muDoubleScalarSqrt(z0);
          if (!(z0 < 1.0E-10)) {
            st.site = &ec_emlrtRSI;
            if (pos_POINTS_3D != 0) {
              st.site = &fc_emlrtRSI;
              r = _mm_loadu_pd(&pointA[0]);
              r1 = _mm_loadu_pd(&x0[0]);
              r = _mm_sub_pd(r, r1);
              _mm_storeu_pd(&pointA[0], r);
              _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
              z0 = c_sumColumnB(y);
              b_st.site = &v_emlrtRSI;
              if (z0 < 0.0) {
                emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                  "Coder:toolbox:ElFunDomainError",
                  "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
              }

              z0 = muDoubleScalarSqrt(z0);
              st.site = &fc_emlrtRSI;
              r = _mm_loadu_pd(&aux[0]);
              _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
              segment_idx_0_tmp = c_sumColumnB(y);
              b_st.site = &v_emlrtRSI;
              if (segment_idx_0_tmp < 0.0) {
                emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                  "Coder:toolbox:ElFunDomainError",
                  "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
              }

              segment_idx_0_tmp = muDoubleScalarSqrt(segment_idx_0_tmp);
              if (z0 < segment_idx_0_tmp) {
                pos_POINTS_3D = 2;
                POINTS_3D[1] = pointB[0];
                POINTS_3D[3] = pointB[1];
                POINTS_3D[5] = zB;
                POINTS_3D[7] = rtNaN;
                POINTS_3D[9] = rtNaN;
                POINTS_3D[11] = rtNaN;
                POINTS_3D[13] = rtNaN;
                POINTS_3D[15] = perpPoint_idx_0;
                POINTS_3D[21] = rtNaN;
                POINTS_3D[17] = perpPoint_idx_1;
                POINTS_3D[23] = rtNaN;
                POINTS_3D[19] = perpPoint_idx_2;
                POINTS_3D[25] = rtNaN;
              } else {
                pos_POINTS_3D = 2;
                for (i = 0; i < 13; i++) {
                  POINTS_3D_tmp = i << 1;
                  POINTS_3D[POINTS_3D_tmp + 1] = POINTS_3D[POINTS_3D_tmp];
                }

                POINTS_3D[0] = pointB[0];
                POINTS_3D[2] = pointB[1];
                POINTS_3D[4] = zB;
                POINTS_3D[6] = rtNaN;
                POINTS_3D[8] = rtNaN;
                POINTS_3D[10] = rtNaN;
                POINTS_3D[12] = rtNaN;
                POINTS_3D[14] = perpPoint_idx_0;
                POINTS_3D[20] = rtNaN;
                POINTS_3D[16] = perpPoint_idx_1;
                POINTS_3D[22] = rtNaN;
                POINTS_3D[18] = perpPoint_idx_2;
                POINTS_3D[24] = rtNaN;
              }
            } else {
              pos_POINTS_3D = 1;
              POINTS_3D[0] = pointB[0];
              POINTS_3D[2] = pointB[1];
              POINTS_3D[4] = zB;
              POINTS_3D[6] = rtNaN;
              POINTS_3D[8] = rtNaN;
              POINTS_3D[10] = rtNaN;
              POINTS_3D[12] = rtNaN;
              POINTS_3D[14] = perpPoint_idx_0;
              POINTS_3D[20] = rtNaN;
              POINTS_3D[16] = perpPoint_idx_1;
              POINTS_3D[22] = rtNaN;
              POINTS_3D[18] = perpPoint_idx_2;
              POINTS_3D[24] = rtNaN;
            }
          }
        }
      }
    }

    if (pos_POINTS_3D < 1) {
      pos_POINTS_3D = 1;
    } else {
      pos_POINTS_3D++;
    }

    st.site = &gc_emlrtRSI;
    r2 = &st;
    z0 = computeZ(r2, Z, x0);
    b_st.site = &gc_emlrtRSI;
    r3 = &b_st;
    segment_idx_0_tmp = computeZ(r3, Z, xn);
    listPoints_size[0] = pos_POINTS_3D + 1;
    listPoints_size[1] = 13;
    listPoints_data[0] = x0[0];
    listPoints_data[pos_POINTS_3D + 1] = x0[1];
    listPoints_data[(pos_POINTS_3D + 1) * 2] = z0;
    listPoints_data[(pos_POINTS_3D + 1) * 3] = rtNaN;
    listPoints_data[(pos_POINTS_3D + 1) * 4] = rtNaN;
    listPoints_data[(pos_POINTS_3D + 1) * 5] = rtNaN;
    listPoints_data[(pos_POINTS_3D + 1) * 6] = rtNaN;
    listPoints_data[(pos_POINTS_3D + 1) * 7] = rtNaN;
    listPoints_data[(pos_POINTS_3D + 1) * 10] = rtNaN;
    listPoints_data[(pos_POINTS_3D + 1) * 8] = rtNaN;
    listPoints_data[(pos_POINTS_3D + 1) * 11] = rtNaN;
    listPoints_data[(pos_POINTS_3D + 1) * 9] = rtNaN;
    listPoints_data[(pos_POINTS_3D + 1) * 12] = rtNaN;
    for (i = 0; i < 13; i++) {
      for (i1 = 0; i1 <= pos_POINTS_3D - 2; i1++) {
        listPoints_data[(i1 + (pos_POINTS_3D + 1) * i) + 1] = POINTS_3D[i1 + (i <<
          1)];
      }
    }

    listPoints_data[pos_POINTS_3D] = xn[0];
    listPoints_data[(pos_POINTS_3D + pos_POINTS_3D) + 1] = xn[1];
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 2] = segment_idx_0_tmp;
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 3] = rtNaN;
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 4] = rtNaN;
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 5] = rtNaN;
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 6] = rtNaN;
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 7] =
      perpPoint_xn_idx_0;
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 10] = rtNaN;
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 8] =
      perpPoint_xn_idx_1;
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 11] = rtNaN;
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 9] =
      perpPoint_xn_idx_2;
    listPoints_data[pos_POINTS_3D + (pos_POINTS_3D + 1) * 12] = rtNaN;
  }
}

static real_T segmentCost(const emlrtStack *sp, const b_captured_var *LUT_vRef,
  const real_T x0[13], const real_T xn[13], real_T *speedRef, real_T
  *proposalSlope, real_T *slope, real_T *tilt)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T y[3];
  real_T realTiltItem[2];
  real_T a_tmp;
  real_T b_a_tmp;
  real_T coefA_tmp;
  real_T coefB;
  real_T cosRealTilt;
  real_T cost;
  real_T tanRealSlope;
  real_T xx_idx_0;
  real_T xx_idx_1;
  real_T xx_idx_2;
  uint64_T u;
  uint64_T u1;
  int32_T ii;
  int32_T numAngles;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* ------------------------------------------------------------------------------------------ */
  /* - computing the path segment cost between two diagonal intersections by sight line checking */
  /* - ... attending to motion constraints (inclination-aware) */
  /* ========================================================================================== */
  /* - compute the distance, reference speed, time and slopes for the path segment */
  /* - note: these points don't have to be nodes but also arbitrary points */
  /* %% proposalSlope = NaN; */
  cosRealTilt = rtNaN;
  realTiltItem[0] = 0.0;
  realTiltItem[1] = 0.0;
  coefA_tmp = xn[2] - x0[2];
  st.site = &ic_emlrtRSI;
  a_tmp = xn[0] - x0[0];
  st.site = &ic_emlrtRSI;
  b_a_tmp = xn[1] - x0[1];
  coefB = a_tmp * a_tmp + b_a_tmp * b_a_tmp;
  st.site = &jc_emlrtRSI;
  if (coefB < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  tanRealSlope = coefA_tmp / muDoubleScalarSqrt(coefB);
  if (muDoubleScalarIsNaN(tanRealSlope)) {
    tanRealSlope = rtInf;
  }

  *slope = muDoubleScalarAtan(tanRealSlope);
  *proposalSlope = *slope;
  xx_idx_0 = xn[7];
  xx_idx_1 = xn[8];
  xx_idx_2 = xn[9];
  if (!muDoubleScalarIsNaN(xn[10])) {
    numAngles = 2;
  } else {
    numAngles = 1;
  }

  for (ii = 0; ii < numAngles; ii++) {
    real_T a;
    real_T c_a_tmp;
    if (ii + 1 == 2) {
      xx_idx_0 = xn[10];
      xx_idx_1 = xn[11];
      xx_idx_2 = xn[12];
    }

    cosRealTilt = x0[1];
    tanRealSlope = x0[2];
    tanRealSlope = xx_idx_2 - tanRealSlope;
    c_a_tmp = xx_idx_1 - cosRealTilt;
    a = c_a_tmp * coefA_tmp - tanRealSlope * b_a_tmp;
    cosRealTilt = x0[0];
    cosRealTilt = xx_idx_0 - cosRealTilt;
    tanRealSlope = cosRealTilt * coefA_tmp - tanRealSlope * a_tmp;
    cosRealTilt = cosRealTilt * b_a_tmp - c_a_tmp * a_tmp;
    st.site = &kc_emlrtRSI;
    st.site = &kc_emlrtRSI;
    st.site = &kc_emlrtRSI;
    st.site = &kc_emlrtRSI;
    st.site = &kc_emlrtRSI;
    tanRealSlope = (coefA_tmp * coefA_tmp + coefB) / (coefB * ((a * a +
      tanRealSlope * tanRealSlope) + cosRealTilt * cosRealTilt));
    if (tanRealSlope < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    tanRealSlope = muDoubleScalarSqrt(tanRealSlope);
    cosRealTilt = muDoubleScalarMin(muDoubleScalarAbs(cosRealTilt) *
      tanRealSlope, 1.0);

    /* %% if isnan(cosRealTilt), cosRealTilt = 0; end */
    if (numAngles == 2) {
      st.site = &lc_emlrtRSI;
      realTiltItem[ii] = muDoubleScalarAcos(cosRealTilt);
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }

  if (numAngles == 2) {
    cosRealTilt = muDoubleScalarCos(c_sumColumnB(realTiltItem) / 2.0);
  }

  st.site = &mc_emlrtRSI;
  *tilt = muDoubleScalarAcos(cosRealTilt);

  /* ========================================================================================== */
  /* - checking motion constraints: slope threshold */
  /* %% speedRef = interp2(THETA,PHI,LUT_vRef.table,slope,tilt,'nearest'); */
  cosRealTilt = (trunc(*slope / LUT_vRef->contents.resolution) + 1570.0) + 1.0;
  if (cosRealTilt < 1.8446744073709552E+19) {
    if (cosRealTilt >= 0.0) {
      u = (uint64_T)cosRealTilt;
    } else {
      u = 0UL;
    }
  } else if (cosRealTilt >= 1.8446744073709552E+19) {
    u = MAX_uint64_T;
  } else {
    u = 0UL;
  }

  if ((real_T)u != (int32_T)muDoubleScalarFloor((real_T)u)) {
    emlrtIntegerCheckR2012b((real_T)u, &ld_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (((int64_T)(uint64_T)(real_T)u < 1L) || ((int64_T)(uint64_T)(real_T)u >
       3141L)) {
    emlrtDynamicBoundsCheckInt64((int64_T)(uint64_T)(real_T)u, 1, 3141,
      &ih_emlrtBCI, (emlrtCTX)sp);
  }

  cosRealTilt = (trunc(*tilt / LUT_vRef->contents.resolution) + 1570.0) + 1.0;
  if (cosRealTilt < 1.8446744073709552E+19) {
    if (cosRealTilt >= 0.0) {
      u1 = (uint64_T)cosRealTilt;
    } else {
      u1 = 0UL;
    }
  } else if (cosRealTilt >= 1.8446744073709552E+19) {
    u1 = MAX_uint64_T;
  } else {
    u1 = 0UL;
  }

  if ((real_T)u1 != (int32_T)muDoubleScalarFloor((real_T)u1)) {
    emlrtIntegerCheckR2012b((real_T)u1, &md_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (((int64_T)(uint64_T)(real_T)u1 < 1L) || ((int64_T)(uint64_T)(real_T)u1 >
       3141L)) {
    emlrtDynamicBoundsCheckInt64((int64_T)(uint64_T)(real_T)u1, 1, 3141,
      &jh_emlrtBCI, (emlrtCTX)sp);
  }

  *speedRef = LUT_vRef->contents.table[((int32_T)(uint64_T)(real_T)u + 3141 *
    ((int32_T)(uint64_T)(real_T)u1 - 1)) - 1];

  /* - determining cost: trajectory time */
  st.site = &nc_emlrtRSI;
  if (muDoubleScalarIsNaN(*speedRef)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI, "MATLAB:nologicalnan",
      "MATLAB:nologicalnan", 0);
  }

  if (*speedRef != 0.0) {
    __m128d r;
    __m128d r1;
    st.site = &oc_emlrtRSI;
    r = _mm_loadu_pd(&xn[0]);
    r1 = _mm_loadu_pd(&x0[0]);
    r = _mm_sub_pd(r, r1);
    _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
    y[2] = coefA_tmp * coefA_tmp;
    tanRealSlope = sumColumnB(y);
    b_st.site = &v_emlrtRSI;
    if (tanRealSlope < 0.0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    tanRealSlope = muDoubleScalarSqrt(tanRealSlope);
    cost = tanRealSlope / *speedRef;
  } else {
    cost = rtMinusInf;
    *speedRef = rtNaN;
  }

  return cost;
}

void DEMAIA(DEMAIAStackData *SD, const emlrtStack *sp, const emxArray_real_T *Z,
            const real_T s[2], const real_T g[2], const struct0_T *LUT_vRef,
            const real_T features[4], real_T mapasTiempo, emxArray_real_T
            *waypoints, emxArray_real_T *G, emxArray_real_T *parent,
            emxArray_cell_wrap_0 *segments)
{
  static const int8_T psi[16] = { 1, 1, 0, -1, -1, -1, 0, 1, 0, 1, 1, 1, 0, -1,
    -1, -1 };

  c_captured_var b_Z;
  captured_var sizeShortBlock;
  cell_wrap_0 *segments_data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T b_CLOSED;
  emxArray_boolean_T *CLOSED;
  emxArray_real_T *F;
  emxArray_real_T *H;
  emxArray_real_T *OPEN;
  emxArray_real_T *WAYPOINTS;
  emxArray_real_T *b_OPEN;
  emxArray_real_T *b_WAYPOINTS;
  emxArray_real_T *iop;
  real_T ipGA_data[52];
  real_T b_g[3];
  real_T c_i[3];
  real_T b_parent[2];
  real_T p[2];
  const real_T *Z_data;
  real_T GT;
  real_T d;
  real_T d1;
  real_T d2;
  real_T enabled_nonNeighborMotion;
  real_T enabled_reexpansions;
  real_T idx;
  real_T *F_data;
  real_T *G_data;
  real_T *H_data;
  real_T *OPEN_data;
  real_T *WAYPOINTS_data;
  real_T *b_WAYPOINTS_data;
  real_T *iop_data;
  real_T *parent_data;
  int32_T CLOSED_size[2];
  int32_T c_WAYPOINTS[2];
  int32_T iv[2];
  int32_T b_i;
  int32_T c_CLOSED;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T i9;
  int32_T ipGTsize;
  int32_T item;
  int32_T k;
  int32_T loop_ub;
  uint32_T pos_OPEN;
  int8_T c_tmp_data[8];
  int8_T d_tmp_data[8];
  int8_T e_tmp_data[8];
  boolean_T *CLOSED_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  Z_data = Z->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  emxInitStruct_captured_var(sp, &b_Z, &t_emlrtRTEI);
  i = b_Z.contents->size[0] * b_Z.contents->size[1];
  b_Z.contents->size[0] = Z->size[0];
  b_Z.contents->size[1] = Z->size[1];
  emxEnsureCapacity_real_T(sp, b_Z.contents, i, &h_emlrtRTEI);
  loop_ub = Z->size[0] * Z->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_Z.contents->data[i] = Z_data[i];
  }

  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  SD->f0.LUT_vRef.contents = *LUT_vRef;
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;

  /* ------------------------------------------------------------------------------------------ */
  /* - DEM-based asymmetric inclination-aware trajectory planner, DEM-AIA, by Manuel Toscano Moreno (UMA, Spain) */
  /* - designed, revised and implemented by Manuel Toscano Moreno (UMA, Spain), May 2022 */
  /* - inline functions */
  /* normalVectorAngle = @(p1,p2,p3)acos( ((p2(1)-p1(1))*(p3(2)-p1(2))-(p3(1)-p1(1))*(p2(2)-p1(2))) / sqrt(sum(cross(p2-p1,p3-p1).^2)) ); */
  /* - global variables for benchmark rates */
  /* %%- angles related to LUT resolution for vehicle motion constraints */
  /* %%negativeAngles = flip([0:-LUT_vRef.resolution:-pi/2]); */
  /* %%negativeAngles = negativeAngles(1:end-1); */
  /* %%angles = [negativeAngles 0:LUT_vRef.resolution:pi/2]; */
  /* %%[THETA,PHI] = ndgrid(angles); */
  /* %%[THETA,PHI] = meshgrid(angles); */
  /* - path/trajectory planner features */
  enabled_nonNeighborMotion = features[0];
  enabled_reexpansions = features[3];

  /* %% w_alpha                   = features(5); */
  /* %% enabled_vectorSlope       = features(6); */
  /* - declaration and initialization of variables */
  /* - some of the initializations are required to use Matlab Coder and to generate MEX file */
  numExplorations = 0.0;
  numExplorations_dirty |= 1U;
  numExploredNodes = 0.0;
  numExploredNodes_dirty |= 1U;
  numReexpandedNodes = 0.0;
  numReexpandedNodes_dirty |= 1U;
  sizeShortBlock.contents = 10.0;
  emxInit_real_T(sp, &OPEN, 2, &i_emlrtRTEI, true);
  i = OPEN->size[0] * OPEN->size[1];
  OPEN->size[0] = 1000;
  OPEN->size[1] = 3;
  emxEnsureCapacity_real_T(sp, OPEN, i, &i_emlrtRTEI);
  OPEN_data = OPEN->data;
  for (i = 0; i < 3000; i++) {
    OPEN_data[i] = 0.0;
  }

  i = Z->size[0];
  i1 = G->size[0] * G->size[1];
  G->size[0] = Z->size[0];
  G->size[1] = Z->size[1];
  emxEnsureCapacity_real_T(sp, G, i1, &j_emlrtRTEI);
  G_data = G->data;
  ipGTsize = Z->size[0] * Z->size[1];
  for (i1 = 0; i1 < ipGTsize; i1++) {
    G_data[i1] = rtInf;
  }

  emxInit_real_T(sp, &F, 2, &k_emlrtRTEI, true);
  i1 = F->size[0] * F->size[1];
  F->size[0] = Z->size[0];
  F->size[1] = Z->size[1];
  emxEnsureCapacity_real_T(sp, F, i1, &k_emlrtRTEI);
  F_data = F->data;
  for (i1 = 0; i1 < ipGTsize; i1++) {
    F_data[i1] = rtInf;
  }

  emxInit_real_T(sp, &H, 2, &l_emlrtRTEI, true);
  i1 = H->size[0] * H->size[1];
  H->size[0] = Z->size[0];
  H->size[1] = Z->size[1];
  emxEnsureCapacity_real_T(sp, H, i1, &l_emlrtRTEI);
  H_data = H->data;
  for (i1 = 0; i1 < ipGTsize; i1++) {
    H_data[i1] = 0.0;
  }

  b_g[0] = Z->size[0];
  b_g[1] = Z->size[1];
  i1 = parent->size[0] * parent->size[1] * parent->size[2];
  parent->size[0] = Z->size[0];
  parent->size[1] = Z->size[1];
  parent->size[2] = 2;
  emxEnsureCapacity_real_T(sp, parent, i1, &m_emlrtRTEI);
  parent_data = parent->data;
  loop_ub = ipGTsize << 1;
  for (i1 = 0; i1 < loop_ub; i1++) {
    parent_data[i1] = rtNaN;
  }

  /* %% OJO: la funcion heuristica debería estar dividida por una velocidad para que sea tiempo */
  st.site = &u_emlrtRSI;
  if (muDoubleScalarIsNaN(features[1])) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI, "MATLAB:nologicalnan",
      "MATLAB:nologicalnan", 0);
  }

  if (features[1] != 0.0) {
    st.site = &u_emlrtRSI;
    if (muDoubleScalarIsNaN(mapasTiempo)) {
      emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI, "MATLAB:nologicalnan",
        "MATLAB:nologicalnan", 0);
    }

    if (mapasTiempo != 0.0) {
      if (features[2] != (int32_T)muDoubleScalarFloor(features[2])) {
        emlrtIntegerCheckR2012b(features[2], &emlrtDCI, (emlrtConstCTX)sp);
      }

      if ((int32_T)features[2] == 1) {
        for (b_i = 0; b_i < i; b_i++) {
          i1 = H->size[1];
          if (H->size[1] - 1 >= 0) {
            c_i[0] = (real_T)b_i + 1.0;
          }

          for (item = 0; item < i1; item++) {
            st.site = &t_emlrtRSI;
            if (b_i + 1 > Z->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Z->size[0], &emlrtBCI,
                &st);
            }

            if (item + 1 > Z->size[1]) {
              emlrtDynamicBoundsCheckR2012b(item + 1, 1, Z->size[1], &b_emlrtBCI,
                &st);
            }

            if (g[0] != (int32_T)muDoubleScalarFloor(g[0])) {
              emlrtIntegerCheckR2012b(g[0], &b_emlrtDCI, &st);
            }

            if (((int32_T)g[0] < 1) || ((int32_T)g[0] > Z->size[0])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)g[0], 1, Z->size[0],
                &c_emlrtBCI, &st);
            }

            if (g[1] != (int32_T)muDoubleScalarFloor(g[1])) {
              emlrtIntegerCheckR2012b(g[1], &c_emlrtDCI, &st);
            }

            if (((int32_T)g[1] < 1) || ((int32_T)g[1] > Z->size[1])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)g[1], 1, Z->size[1],
                &d_emlrtBCI, &st);
            }

            c_i[1] = (real_T)item + 1.0;
            c_i[2] = Z_data[b_i + Z->size[0] * item];
            b_g[0] = g[0];
            b_g[1] = g[1];
            b_g[2] = Z_data[((int32_T)g[0] + Z->size[0] * ((int32_T)g[1] - 1)) -
              1];
            b_st.site = &x_emlrtRSI;
            GT = DEMAIA_anonFcn2(&b_st, Z, c_i, b_g);
            if (b_i + 1 > H->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H->size[0], &dc_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            if (item + 1 > H->size[1]) {
              emlrtDynamicBoundsCheckR2012b(item + 1, 1, H->size[1],
                &ec_emlrtBCI, (emlrtConstCTX)sp);
            }

            H_data[b_i + H->size[0] * item] = GT / LUT_vRef->vMax;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b((emlrtConstCTX)sp);
            }
          }

          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }
      } else {
        for (b_i = 0; b_i < i; b_i++) {
          i1 = H->size[1];
          for (item = 0; item < i1; item++) {
            __m128d r;
            __m128d r1;
            st.site = &s_emlrtRSI;
            if (b_i + 1 > Z->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Z->size[0], &e_emlrtBCI,
                &st);
            }

            if (item + 1 > Z->size[1]) {
              emlrtDynamicBoundsCheckR2012b(item + 1, 1, Z->size[1], &f_emlrtBCI,
                &st);
            }

            if (g[0] != (int32_T)muDoubleScalarFloor(g[0])) {
              emlrtIntegerCheckR2012b(g[0], &d_emlrtDCI, &st);
            }

            if (((int32_T)g[0] < 1) || ((int32_T)g[0] > Z->size[0])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)g[0], 1, Z->size[0],
                &g_emlrtBCI, &st);
            }

            if (g[1] != (int32_T)muDoubleScalarFloor(g[1])) {
              emlrtIntegerCheckR2012b(g[1], &e_emlrtDCI, &st);
            }

            if (((int32_T)g[1] < 1) || ((int32_T)g[1] > Z->size[1])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)g[1], 1, Z->size[1],
                &h_emlrtBCI, &st);
            }

            b_g[0] = g[0];
            b_g[1] = g[1];
            b_g[2] = Z_data[((int32_T)g[0] + Z->size[0] * ((int32_T)g[1] - 1)) -
              1];
            c_i[0] = (real_T)b_i + 1.0;
            c_i[1] = (real_T)item + 1.0;
            c_i[2] = Z_data[b_i + Z->size[0] * item];
            r = _mm_loadu_pd(&b_g[0]);
            r1 = _mm_loadu_pd(&c_i[0]);
            r = _mm_sub_pd(r, r1);
            _mm_storeu_pd(&b_g[0], r);
            _mm_storeu_pd(&c_i[0], _mm_mul_pd(r, r));
            d = b_g[2];
            d -= c_i[2];
            b_g[2] = d;
            c_i[2] = d * d;
            GT = sumColumnB(c_i);
            b_st.site = &v_emlrtRSI;
            if (GT < 0.0) {
              emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }

            GT = muDoubleScalarSqrt(GT);
            if (b_i + 1 > H->size[0]) {
              emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, H->size[0], &hc_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            if (item + 1 > H->size[1]) {
              emlrtDynamicBoundsCheckR2012b(item + 1, 1, H->size[1],
                &ic_emlrtBCI, (emlrtConstCTX)sp);
            }

            H_data[b_i + H->size[0] * item] = GT / LUT_vRef->vMax;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b((emlrtConstCTX)sp);
            }
          }

          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }
      }
    }
  }

  emxInit_boolean_T(sp, &CLOSED, &n_emlrtRTEI);
  i = CLOSED->size[0] * CLOSED->size[1];
  CLOSED->size[0] = Z->size[0];
  CLOSED->size[1] = Z->size[1];
  emxEnsureCapacity_boolean_T(sp, CLOSED, i, &n_emlrtRTEI);
  CLOSED_data = CLOSED->data;
  for (i = 0; i < ipGTsize; i++) {
    CLOSED_data[i] = false;
  }

  waypoints->size[0] = 0;
  waypoints->size[1] = 7;
  idx = rtNaN;

  /* %% tentativeG = NaN; tentativeParent = NaN(1,2); */
  emxInit_real_T(sp, &WAYPOINTS, 2, &q_emlrtRTEI, true);
  i = WAYPOINTS->size[0] * WAYPOINTS->size[1];
  WAYPOINTS->size[0] = 1;
  WAYPOINTS->size[1] = 13;
  emxEnsureCapacity_real_T(sp, WAYPOINTS, i, &o_emlrtRTEI);
  WAYPOINTS_data = WAYPOINTS->data;
  for (i = 0; i < 13; i++) {
    WAYPOINTS_data[i] = rtNaN;
  }

  /* %% tentativeSegments = NaN(1,3*(size(s,2)+1)+4); coder.varsize('tentativeSegments',[Inf 3*(size(s,2)+1)+4],[1 0]); */
  i = segments->size[0] * segments->size[1];
  segments->size[0] = Z->size[0];
  segments->size[1] = Z->size[1];
  emxEnsureCapacity_cell_wrap_0(sp, segments, i, &p_emlrtRTEI);
  segments_data = segments->data;
  i = (int32_T)muDoubleScalarFloor(s[0]);
  if (s[0] != i) {
    emlrtIntegerCheckR2012b(s[0], &db_emlrtDCI, (emlrtConstCTX)sp);
  }

  i1 = (int32_T)s[0];
  if ((s[0] < 1.0) || (i1 > Z->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)s[0], 1, Z->size[0], &fc_emlrtBCI,
      (emlrtConstCTX)sp);
  }

  i2 = (int32_T)muDoubleScalarFloor(s[1]);
  if (s[1] != i2) {
    emlrtIntegerCheckR2012b(s[1], &eb_emlrtDCI, (emlrtConstCTX)sp);
  }

  i3 = (int32_T)s[1];
  if ((s[1] < 1.0) || (i3 > Z->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)s[1], 1, Z->size[1], &gc_emlrtBCI,
      (emlrtConstCTX)sp);
  }

  G_data[(i1 + G->size[0] * (i3 - 1)) - 1] = 0.0;
  if (i1 != i) {
    emlrtIntegerCheckR2012b(s[0], &fb_emlrtDCI, (emlrtConstCTX)sp);
  }

  if ((s[0] < 1.0) || (i1 > Z->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)s[0], 1, Z->size[0], &jc_emlrtBCI,
      (emlrtConstCTX)sp);
  }

  if (i3 != i2) {
    emlrtIntegerCheckR2012b(s[1], &gb_emlrtDCI, (emlrtConstCTX)sp);
  }

  if ((s[1] < 1.0) || (i3 > Z->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)s[1], 1, Z->size[1], &kc_emlrtBCI,
      (emlrtConstCTX)sp);
  }

  F_data[(i1 + F->size[0] * (i3 - 1)) - 1] = 0.0;
  pos_OPEN = 1U;
  OPEN_data[0] = s[0];
  OPEN_data[OPEN->size[0]] = s[1];
  if (i1 != i) {
    emlrtIntegerCheckR2012b(s[0], &hb_emlrtDCI, (emlrtConstCTX)sp);
  }

  if ((s[0] < 1.0) || (i1 > F->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)s[0], 1, F->size[0], &lc_emlrtBCI,
      (emlrtConstCTX)sp);
  }

  if (i3 != i2) {
    emlrtIntegerCheckR2012b(s[1], &hb_emlrtDCI, (emlrtConstCTX)sp);
  }

  if ((s[1] < 1.0) || (i3 > F->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)s[1], 1, F->size[1], &lc_emlrtBCI,
      (emlrtConstCTX)sp);
  }

  OPEN_data[OPEN->size[0] * 2] = F_data[((int32_T)s[0] + F->size[0] * ((int32_T)
    s[1] - 1)) - 1];

  /* - main loop, graph search strategy used by Dijkstra, A* and other graph-based algorithms */
  emxInit_real_T(sp, &iop, 2, &db_emlrtRTEI, true);
  emxInit_real_T(sp, &b_WAYPOINTS, 2, &w_emlrtRTEI, true);
  emxInit_real_T(sp, &b_OPEN, 2, &bb_emlrtRTEI, true);
  int32_T exitg1;
  do {
    exitg1 = 0;
    st.site = &r_emlrtRSI;
    if (pos_OPEN != 0U) {
      real_T b_p_tmp;
      real_T p_tmp;
      boolean_T found;

      /* - extracting the best node from OPEN list (the lowest cost value) and marking it as a CLOSED node */
      ipGTsize = (int32_T)pos_OPEN;
      found = (((int32_T)pos_OPEN < 1) || ((int32_T)pos_OPEN > OPEN->size[0]));
      if (found) {
        emlrtDynamicBoundsCheckR2012b((int32_T)pos_OPEN, 1, OPEN->size[0],
          &i_emlrtBCI, (emlrtConstCTX)sp);
      }

      st.site = &q_emlrtRSI;
      b_st.site = &eb_emlrtRSI;
      c_st.site = &fb_emlrtRSI;
      d_st.site = &gb_emlrtRSI;
      e_st.site = &hb_emlrtRSI;
      if ((int32_T)pos_OPEN <= 2) {
        if ((int32_T)pos_OPEN == 1) {
          item = 1;
        } else {
          d = OPEN_data[((int32_T)pos_OPEN + OPEN->size[0] * 2) - 1];
          if ((OPEN_data[OPEN->size[0] * 2] > d) || (muDoubleScalarIsNaN
               (OPEN_data[OPEN->size[0] * 2]) && (!muDoubleScalarIsNaN(d)))) {
            item = (int32_T)pos_OPEN;
          } else {
            item = 1;
          }
        }
      } else {
        f_st.site = &jb_emlrtRSI;
        if (!muDoubleScalarIsNaN(OPEN_data[OPEN->size[0] * 2])) {
          item = 1;
        } else {
          boolean_T exitg2;
          item = 0;
          g_st.site = &kb_emlrtRSI;
          if ((int32_T)pos_OPEN > 2147483646) {
            h_st.site = &lb_emlrtRSI;
            check_forloop_overflow_error(&h_st);
          }

          k = 2;
          exitg2 = false;
          while ((!exitg2) && (k <= (int32_T)pos_OPEN)) {
            if (!muDoubleScalarIsNaN(OPEN_data[(k + OPEN->size[0] * 2) - 1])) {
              item = k;
              exitg2 = true;
            } else {
              k++;
            }
          }
        }

        if (item == 0) {
          item = 1;
        } else {
          f_st.site = &ib_emlrtRSI;
          GT = OPEN_data[(item + OPEN->size[0] * 2) - 1];
          loop_ub = item + 1;
          g_st.site = &mb_emlrtRSI;
          if ((item + 1 <= (int32_T)pos_OPEN) && ((int32_T)pos_OPEN > 2147483646))
          {
            h_st.site = &lb_emlrtRSI;
            check_forloop_overflow_error(&h_st);
          }

          for (k = loop_ub; k <= ipGTsize; k++) {
            d = OPEN_data[(k + OPEN->size[0] * 2) - 1];
            if (GT > d) {
              GT = d;
              item = k;
            }
          }
        }
      }

      if ((item < 1) || (item > OPEN->size[0])) {
        emlrtDynamicBoundsCheckR2012b(item, 1, OPEN->size[0], &j_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      p_tmp = OPEN_data[item - 1];
      p[0] = p_tmp;
      b_p_tmp = OPEN_data[(item + OPEN->size[0]) - 1];
      p[1] = b_p_tmp;
      numExplorations++;
      numExplorations_dirty |= 1U;
      i4 = (int32_T)muDoubleScalarFloor(p_tmp);
      if (p_tmp != i4) {
        emlrtIntegerCheckR2012b(p_tmp, &ib_emlrtDCI, (emlrtConstCTX)sp);
      }

      i5 = (int32_T)p_tmp;
      if ((p_tmp < 1.0) || (i5 > CLOSED->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)p_tmp, 1, CLOSED->size[0],
          &mc_emlrtBCI, (emlrtConstCTX)sp);
      }

      i6 = (int32_T)muDoubleScalarFloor(b_p_tmp);
      if (b_p_tmp != i6) {
        emlrtIntegerCheckR2012b(b_p_tmp, &jb_emlrtDCI, (emlrtConstCTX)sp);
      }

      i7 = (int32_T)b_p_tmp;
      if ((b_p_tmp < 1.0) || (i7 > CLOSED->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_p_tmp, 1, CLOSED->size[1],
          &nc_emlrtBCI, (emlrtConstCTX)sp);
      }

      CLOSED_data[(i5 + CLOSED->size[0] * (i7 - 1)) - 1] = true;
      if (item < (int32_T)pos_OPEN) {
        if (item > OPEN->size[0]) {
          emlrtDynamicBoundsCheckR2012b(item, 1, OPEN->size[0], &k_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        c_i[0] = OPEN_data[(int32_T)pos_OPEN - 1];
        c_i[1] = OPEN_data[((int32_T)pos_OPEN + OPEN->size[0]) - 1];
        c_i[2] = OPEN_data[((int32_T)pos_OPEN + OPEN->size[0] * 2) - 1];
        OPEN_data[item - 1] = c_i[0];
        OPEN_data[(item + OPEN->size[0]) - 1] = c_i[1];
        OPEN_data[(item + OPEN->size[0] * 2) - 1] = c_i[2];
      }

      pos_OPEN = (uint32_T)((int32_T)pos_OPEN - 1);

      /* - if final cell is reached, exit of main loop */
      /* %%if ( enabled_heuristic || ~enabled_reexpansions ) && isequal(p,g) */
      if ((mapasTiempo != 0.0) && isequal(p, g)) {
        exitg1 = 1;
      } else {
        real_T succ[16];
        real_T succ_data[16];
        int32_T trueCount;
        int8_T i10;
        boolean_T b_tmp_data[8];
        boolean_T tmp_data[8];

        /* - if not... proposing new OPEN nodes from the best node's successors */
        /* ========================================================================================== */
        /* - computing the successor nodes of a given node by eight-neighbourhood criterion, */
        /* - without including nodes belonging to the CLOSED set, unless reexpansion is enabled */
        repmat(p, succ);
        for (i8 = 0; i8 < 16; i8++) {
          succ[i8] += (real_T)psi[i8];
        }

        item = 0;
        loop_ub = 0;
        for (b_i = 0; b_i < 8; b_i++) {
          d = succ[b_i];
          found = ((d < (real_T)b_Z.contents->size[0] - 1.0) && (d > 1.0));
          if (found) {
            item++;
            c_tmp_data[loop_ub] = (int8_T)b_i;
            loop_ub++;
          }
        }

        /*  excluding nodes of the frontier */
        for (i8 = 0; i8 < item; i8++) {
          d = succ[c_tmp_data[i8] + 8];
          tmp_data[i8] = (d < (real_T)b_Z.contents->size[1] - 1.0);
          b_tmp_data[i8] = (d > 1.0);
        }

        ipGTsize = item - 1;
        k = 0;
        loop_ub = 0;
        for (b_i = 0; b_i <= ipGTsize; b_i++) {
          if (tmp_data[b_i] && b_tmp_data[b_i]) {
            k++;
            d_tmp_data[loop_ub] = (int8_T)b_i;
            loop_ub++;
          }
        }

        trueCount = k;
        for (i8 = 0; i8 < 2; i8++) {
          for (i9 = 0; i9 < k; i9++) {
            i10 = d_tmp_data[i9];
            if ((i10 < 0) || (i10 > item - 1)) {
              emlrtDynamicBoundsCheckR2012b(i10, 0, item - 1, &pc_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            succ_data[i9 + k * i8] = succ[c_tmp_data[i10] + (i8 << 3)];
          }
        }

        /*  excluding nodes of the frontier */
        st.site = &p_emlrtRSI;
        if (muDoubleScalarIsNaN(enabled_reexpansions)) {
          emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI, "MATLAB:nologicalnan",
            "MATLAB:nologicalnan", 0);
        }

        if (!(enabled_reexpansions != 0.0)) {
          boolean_T b_CLOSED_data[64];
          CLOSED_size[0] = k;
          CLOSED_size[1] = k;
          for (i8 = 0; i8 < k; i8++) {
            for (i9 = 0; i9 < k; i9++) {
              if (succ_data[i9] != (int32_T)muDoubleScalarFloor(succ_data[i9]))
              {
                emlrtIntegerCheckR2012b(succ_data[i9], &lb_emlrtDCI,
                  (emlrtConstCTX)sp);
              }

              ipGTsize = (int32_T)succ_data[i9];
              if ((ipGTsize < 1) || (ipGTsize > CLOSED->size[0])) {
                emlrtDynamicBoundsCheckR2012b(ipGTsize, 1, CLOSED->size[0],
                  &qc_emlrtBCI, (emlrtConstCTX)sp);
              }

              d = succ_data[i8 + k];
              if (d != (int32_T)muDoubleScalarFloor(d)) {
                emlrtIntegerCheckR2012b(succ_data[i8 + k], &mb_emlrtDCI,
                  (emlrtConstCTX)sp);
              }

              if (((int32_T)d < 1) || ((int32_T)d > CLOSED->size[1])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, CLOSED->size[1],
                  &rc_emlrtBCI, (emlrtConstCTX)sp);
              }

              b_CLOSED_data[i9 + k * i8] = !CLOSED_data[(ipGTsize + CLOSED->
                size[0] * ((int32_T)d - 1)) - 1];
            }
          }

          st.site = &p_emlrtRSI;
          ipGTsize = diag(&st, b_CLOSED_data, CLOSED_size, tmp_data);
          ipGTsize--;
          trueCount = 0;
          loop_ub = 0;
          for (b_i = 0; b_i <= ipGTsize; b_i++) {
            if (tmp_data[b_i]) {
              trueCount++;
              e_tmp_data[loop_ub] = (int8_T)b_i;
              loop_ub++;
            }
          }

          for (i8 = 0; i8 < 2; i8++) {
            for (i9 = 0; i9 < trueCount; i9++) {
              i10 = e_tmp_data[i9];
              if ((i10 < 0) || (i10 > k - 1)) {
                emlrtDynamicBoundsCheckR2012b(i10, 0, k - 1, &sc_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              succ_data[i9 + trueCount * i8] = succ[c_tmp_data[d_tmp_data[i10]]
                + (i8 << 3)];
            }
          }
        }

        /* ========================================================================================== */
        /* - updating evaluation value (addition of cost and heuristic values) for each successor node */
        /* - some of the initializations are required to use Matlab Coder and to generate MEX file */
        item = 1;
        int32_T exitg3;
        do {
          exitg3 = 0;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }

          if (item <= trueCount) {
            real_T b_ipGA[13];
            real_T ipGA[13];
            real_T b_succ[2];
            real_T GA;
            real_T b_succ_tmp;
            real_T itemCost;
            real_T succ_tmp;
            int32_T ipGA_size[2];
            boolean_T guard1;
            boolean_T guard2;

            /* ========================================================================================== */
            /* - updating the 'OPEN' nodes list ... */
            GT = rtInf;
            st.site = &o_emlrtRSI;
            if (muDoubleScalarIsNaN(enabled_nonNeighborMotion)) {
              emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
                "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
            }

            if ((enabled_nonNeighborMotion != 0.0) && (!isequaln(p, s))) {
              uint32_T b_i1;
              if (i5 != i4) {
                emlrtIntegerCheckR2012b(p_tmp, &ob_emlrtDCI, (emlrtConstCTX)sp);
              }

              if ((p_tmp < 1.0) || (i5 > parent->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)p_tmp, 1, parent->size[0],
                  &uc_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (i7 != i6) {
                emlrtIntegerCheckR2012b(b_p_tmp, &pb_emlrtDCI, (emlrtConstCTX)sp);
              }

              if ((b_p_tmp < 1.0) || (i7 > parent->size[1])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)b_p_tmp, 1, parent->size
                  [1], &vc_emlrtBCI, (emlrtConstCTX)sp);
              }

              d = parent_data[(i5 + parent->size[0] * (i7 - 1)) - 1];
              if (d != (int32_T)muDoubleScalarFloor(d)) {
                emlrtIntegerCheckR2012b(d, &nb_emlrtDCI, (emlrtConstCTX)sp);
              }

              if (((int32_T)d < 1) || ((int32_T)d > G->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, G->size[0],
                  &tc_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (i5 != i4) {
                emlrtIntegerCheckR2012b(p_tmp, &rb_emlrtDCI, (emlrtConstCTX)sp);
              }

              if ((p_tmp < 1.0) || (i5 > parent->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)p_tmp, 1, parent->size[0],
                  &xc_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (i7 != i6) {
                emlrtIntegerCheckR2012b(b_p_tmp, &sb_emlrtDCI, (emlrtConstCTX)sp);
              }

              if ((b_p_tmp < 1.0) || (i7 > parent->size[1])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)b_p_tmp, 1, parent->size
                  [1], &yc_emlrtBCI, (emlrtConstCTX)sp);
              }

              d1 = parent_data[(((int32_T)p_tmp + parent->size[0] * ((int32_T)
                b_p_tmp - 1)) + parent->size[0] * parent->size[1]) - 1];
              if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
                emlrtIntegerCheckR2012b(d1, &qb_emlrtDCI, (emlrtConstCTX)sp);
              }

              if (((int32_T)d1 < 1) || ((int32_T)d1 > G->size[1])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, G->size[1],
                  &wc_emlrtBCI, (emlrtConstCTX)sp);
              }

              GT = G_data[((int32_T)d + G->size[0] * ((int32_T)d1 - 1)) - 1];
              if (i5 != i4) {
                emlrtIntegerCheckR2012b(p_tmp, &f_emlrtDCI, (emlrtConstCTX)sp);
              }

              if ((p_tmp < 1.0) || (i5 > parent->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)p_tmp, 1, parent->size[0],
                  &l_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (i7 != i6) {
                emlrtIntegerCheckR2012b(b_p_tmp, &g_emlrtDCI, (emlrtConstCTX)sp);
              }

              if ((b_p_tmp < 1.0) || (i7 > parent->size[1])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)b_p_tmp, 1, parent->size
                  [1], &m_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &n_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              b_parent[0] = parent_data[((int32_T)p_tmp + parent->size[0] *
                ((int32_T)b_p_tmp - 1)) - 1];
              b_succ[0] = succ_data[item - 1];
              b_parent[1] = parent_data[(((int32_T)p_tmp + parent->size[0] *
                ((int32_T)b_p_tmp - 1)) + parent->size[0] * parent->size[1]) - 1];
              b_succ[1] = succ_data[(item + trueCount) - 1];
              st.site = &n_emlrtRSI;
              entryExitPoints(&st, &sizeShortBlock, b_parent, b_succ, iop);
              iop_data = iop->data;
              b_i1 = 2U;
              while ((b_i1 <= (uint32_T)iop->size[0]) && ((!muDoubleScalarIsInf
                       (GT)) && (!muDoubleScalarIsNaN(GT)))) {
                uint32_T b_i2;
                if ((int32_T)b_i1 == 2) {
                  ipGTsize = 0;
                  b_parent[0] = iop_data[0];
                  b_succ[0] = iop_data[1];
                  b_parent[1] = iop_data[iop->size[0]];
                  b_succ[1] = iop_data[iop->size[0] + 1];
                  st.site = &m_emlrtRSI;
                  intersectionPoints(&st, &b_Z, b_parent, b_succ, ipGA_data,
                                     ipGA_size);
                  i8 = WAYPOINTS->size[0] * WAYPOINTS->size[1];
                  WAYPOINTS->size[0] = ipGA_size[0];
                  WAYPOINTS->size[1] = 13;
                  emxEnsureCapacity_real_T(sp, WAYPOINTS, i8, &v_emlrtRTEI);
                  WAYPOINTS_data = WAYPOINTS->data;
                  loop_ub = ipGA_size[0] * 13;
                  for (i8 = 0; i8 < loop_ub; i8++) {
                    WAYPOINTS_data[i8] = ipGA_data[i8];
                  }
                } else {
                  ipGTsize = WAYPOINTS->size[0] - 1;
                  if ((int32_T)b_i1 - 1 > iop->size[0]) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)b_i1 - 1, 1,
                      iop->size[0], &o_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  if ((int32_T)b_i1 > iop->size[0]) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)b_i1, 1, iop->size[0],
                      &p_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  b_parent[0] = iop_data[(int32_T)b_i1 - 2];
                  b_succ[0] = iop_data[(int32_T)b_i1 - 1];
                  b_parent[1] = iop_data[((int32_T)b_i1 + iop->size[0]) - 2];
                  b_succ[1] = iop_data[((int32_T)b_i1 + iop->size[0]) - 1];
                  st.site = &l_emlrtRSI;
                  intersectionPoints(&st, &b_Z, b_parent, b_succ, ipGA_data,
                                     ipGA_size);
                  if (ipGA_size[0] < 1) {
                    emlrtDynamicBoundsCheckR2012b(ipGA_size[0], 1, ipGA_size[0],
                      &q_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  i8 = b_WAYPOINTS->size[0] * b_WAYPOINTS->size[1];
                  b_WAYPOINTS->size[0] = (WAYPOINTS->size[0] + ipGA_size[0]) - 1;
                  b_WAYPOINTS->size[1] = 13;
                  emxEnsureCapacity_real_T(sp, b_WAYPOINTS, i8, &w_emlrtRTEI);
                  b_WAYPOINTS_data = b_WAYPOINTS->data;
                  for (i8 = 0; i8 < 13; i8++) {
                    loop_ub = WAYPOINTS->size[0];
                    for (i9 = 0; i9 < loop_ub; i9++) {
                      b_WAYPOINTS_data[i9 + b_WAYPOINTS->size[0] * i8] =
                        WAYPOINTS_data[i9 + WAYPOINTS->size[0] * i8];
                    }
                  }

                  loop_ub = ipGA_size[0];
                  for (i8 = 0; i8 < 13; i8++) {
                    for (i9 = 0; i9 <= loop_ub - 2; i9++) {
                      b_WAYPOINTS_data[(i9 + WAYPOINTS->size[0]) +
                        b_WAYPOINTS->size[0] * i8] = ipGA_data[(i9 + ipGA_size[0]
                        * i8) + 1];
                    }
                  }

                  i8 = WAYPOINTS->size[0] * WAYPOINTS->size[1];
                  WAYPOINTS->size[0] = b_WAYPOINTS->size[0];
                  WAYPOINTS->size[1] = 13;
                  emxEnsureCapacity_real_T(sp, WAYPOINTS, i8, &x_emlrtRTEI);
                  WAYPOINTS_data = WAYPOINTS->data;
                  loop_ub = b_WAYPOINTS->size[0] * 13;
                  for (i8 = 0; i8 < loop_ub; i8++) {
                    WAYPOINTS_data[i8] = b_WAYPOINTS_data[i8];
                  }
                }

                b_i2 = (uint32_T)((real_T)ipGTsize + 2.0);
                while ((b_i2 <= (uint32_T)WAYPOINTS->size[0]) &&
                       ((!muDoubleScalarIsInf(GT)) && (!muDoubleScalarIsNaN(GT))))
                {
                  if (((int32_T)b_i2 - 1 < 1) || ((int32_T)b_i2 - 1 >
                       WAYPOINTS->size[0])) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)b_i2 - 1, 1,
                      WAYPOINTS->size[0], &r_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  if ((int32_T)b_i2 > WAYPOINTS->size[0]) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)b_i2, 1,
                      WAYPOINTS->size[0], &s_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  for (i8 = 0; i8 < 13; i8++) {
                    ipGA[i8] = WAYPOINTS_data[((int32_T)b_i2 + WAYPOINTS->size[0]
                      * i8) - 2];
                    b_ipGA[i8] = WAYPOINTS_data[((int32_T)b_i2 + WAYPOINTS->
                      size[0] * i8) - 1];
                  }

                  if ((int32_T)b_i2 > WAYPOINTS->size[0]) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)b_i2, 1,
                      WAYPOINTS->size[0], &cf_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  st.site = &k_emlrtRSI;
                  itemCost = segmentCost(&st, &SD->f0.LUT_vRef, ipGA, b_ipGA,
                    &WAYPOINTS_data[((int32_T)b_i2 + WAYPOINTS->size[0] * 3) - 1],
                    &d, &d1, &d2);
                  if ((int32_T)b_i2 > WAYPOINTS->size[0]) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)b_i2, 1,
                      WAYPOINTS->size[0], &df_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  WAYPOINTS_data[((int32_T)b_i2 + WAYPOINTS->size[0] * 4) - 1] =
                    d;
                  if ((int32_T)b_i2 > WAYPOINTS->size[0]) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)b_i2, 1,
                      WAYPOINTS->size[0], &ef_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  WAYPOINTS_data[((int32_T)b_i2 + WAYPOINTS->size[0] * 5) - 1] =
                    d1;
                  if ((int32_T)b_i2 > WAYPOINTS->size[0]) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)b_i2, 1,
                      WAYPOINTS->size[0], &ff_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  WAYPOINTS_data[((int32_T)b_i2 + WAYPOINTS->size[0] * 6) - 1] =
                    d2;
                  GT += itemCost;
                  b_i2++;
                  if (*emlrtBreakCheckR2012bFlagVar != 0) {
                    emlrtBreakCheckR2012b((emlrtConstCTX)sp);
                  }
                }

                b_i1++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b((emlrtConstCTX)sp);
                }
              }
            }

            if (i5 != i4) {
              emlrtIntegerCheckR2012b(p_tmp, &tb_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((p_tmp < 1.0) || (i5 > G->size[0])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)p_tmp, 1, G->size[0],
                &ad_emlrtBCI, (emlrtConstCTX)sp);
            }

            if (i7 != i6) {
              emlrtIntegerCheckR2012b(b_p_tmp, &ub_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((b_p_tmp < 1.0) || (i7 > G->size[1])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)b_p_tmp, 1, G->size[1],
                &bd_emlrtBCI, (emlrtConstCTX)sp);
            }

            GA = G_data[(i5 + G->size[0] * (i7 - 1)) - 1];
            if (item > trueCount) {
              emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &t_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            succ_tmp = succ_data[item - 1];
            b_succ[0] = succ_tmp;
            b_succ_tmp = succ_data[(item + trueCount) - 1];
            b_succ[1] = b_succ_tmp;
            st.site = &j_emlrtRSI;
            intersectionPoints(&st, &b_Z, p, b_succ, ipGA_data, ipGA_size);
            i8 = ipGA_size[0];
            i9 = ipGA_size[0];
            for (b_i = 0; b_i <= i8 - 2; b_i++) {
              /* %% cambiar for por while condicionado a GA finito e i menor de size(ipGA,1) */
              if (b_i + 1 > ipGA_size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ipGA_size[0],
                  &u_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (b_i + 2 > ipGA_size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ipGA_size[0],
                  &v_emlrtBCI, (emlrtConstCTX)sp);
              }

              for (ipGTsize = 0; ipGTsize < 13; ipGTsize++) {
                loop_ub = b_i + i9 * ipGTsize;
                ipGA[ipGTsize] = ipGA_data[loop_ub];
                b_ipGA[ipGTsize] = ipGA_data[loop_ub + 1];
              }

              if (b_i + 2 > ipGA_size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ipGA_size[0],
                  &cd_emlrtBCI, (emlrtConstCTX)sp);
              }

              st.site = &i_emlrtRSI;
              itemCost = segmentCost(&st, &SD->f0.LUT_vRef, ipGA, b_ipGA,
                &ipGA_data[(b_i + ipGA_size[0] * 3) + 1], &d, &d1, &d2);
              if (b_i + 2 > ipGA_size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ipGA_size[0],
                  &dd_emlrtBCI, (emlrtConstCTX)sp);
              }

              ipGA_data[(b_i + ipGA_size[0] * 4) + 1] = d;
              if (b_i + 2 > ipGA_size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ipGA_size[0],
                  &id_emlrtBCI, (emlrtConstCTX)sp);
              }

              ipGA_data[(b_i + ipGA_size[0] * 5) + 1] = d1;
              if (b_i + 2 > ipGA_size[0]) {
                emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ipGA_size[0],
                  &nd_emlrtBCI, (emlrtConstCTX)sp);
              }

              ipGA_data[(b_i + ipGA_size[0] * 6) + 1] = d2;
              GA += itemCost;
              if (*emlrtBreakCheckR2012bFlagVar != 0) {
                emlrtBreakCheckR2012b((emlrtConstCTX)sp);
              }
            }

            /*  any-angle nodes path (allowed non-neighbor nodes motion; possible insertion of new graph edge) */
            st.site = &h_emlrtRSI;
            guard1 = false;
            guard2 = false;
            if ((enabled_nonNeighborMotion != 0.0) && (GT > 0.0) && (GT <= GA))
            {
              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &fd_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              d = (int32_T)muDoubleScalarFloor(succ_tmp);
              if (succ_tmp != d) {
                emlrtIntegerCheckR2012b(succ_tmp, &vb_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > G->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1, G->size[0],
                  &ed_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &hd_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              d1 = (int32_T)muDoubleScalarFloor(b_succ_tmp);
              if (b_succ_tmp != d1) {
                emlrtIntegerCheckR2012b(b_succ_tmp, &wb_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp > G->size[1]))
              {
                emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1, G->size[1],
                  &gd_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (GT < G_data[((int32_T)succ_tmp + G->size[0] * ((int32_T)
                    b_succ_tmp - 1)) - 1]) {
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &kd_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &xb_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > G->size[0]))
                {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1, G->size[0],
                    &jd_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &md_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &yb_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp > G->size
                     [1])) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1, G->size
                    [1], &ld_emlrtBCI, (emlrtConstCTX)sp);
                }

                G_data[((int32_T)succ_tmp + G->size[0] * ((int32_T)b_succ_tmp -
                         1)) - 1] = GT;
                if (i5 != i4) {
                  emlrtIntegerCheckR2012b(p_tmp, &h_emlrtDCI, (emlrtConstCTX)sp);
                }

                if ((p_tmp < 1.0) || (i5 > parent->size[0])) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)p_tmp, 1, parent->size
                    [0], &w_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (i7 != i6) {
                  emlrtIntegerCheckR2012b(b_p_tmp, &i_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if ((b_p_tmp < 1.0) || (i7 > parent->size[1])) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_p_tmp, 1,
                    parent->size[1], &x_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &le_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &j_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > parent->
                     size[0])) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1,
                    parent->size[0], &y_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ne_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &k_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp >
                     parent->size[1])) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1,
                    parent->size[1], &ab_emlrtBCI, (emlrtConstCTX)sp);
                }

                GT = parent_data[(((int32_T)p_tmp + parent->size[0] * ((int32_T)
                  b_p_tmp - 1)) + parent->size[0] * parent->size[1]) - 1];
                parent_data[((int32_T)succ_tmp + parent->size[0] * ((int32_T)
                  b_succ_tmp - 1)) - 1] = parent_data[((int32_T)p_tmp +
                  parent->size[0] * ((int32_T)b_p_tmp - 1)) - 1];
                parent_data[(((int32_T)succ_tmp + parent->size[0] * ((int32_T)
                  b_succ_tmp - 1)) + parent->size[0] * parent->size[1]) - 1] =
                  GT;
                i8 = segments->size[0] - 1;
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &te_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &bb_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp - 1 < 0) || ((int32_T)succ_tmp - 1 >
                     segments->size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp - 1, 0,
                    segments->size[0] - 1, &bc_emlrtBCI, (emlrtConstCTX)sp);
                }

                i9 = segments->size[1] - 1;
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ue_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &cb_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp - 1 < 0) || ((int32_T)b_succ_tmp - 1 >
                     segments->size[1] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp - 1, 0,
                    segments->size[1] - 1, &cc_emlrtBCI, (emlrtConstCTX)sp);
                }

                ipGTsize = segments_data[((int32_T)succ_tmp + segments->size[0] *
                  ((int32_T)b_succ_tmp - 1)) - 1].f1->size[0] * segments_data
                  [((int32_T)succ_tmp + segments->size[0] * ((int32_T)b_succ_tmp
                     - 1)) - 1].f1->size[1];
                segments_data[((int32_T)succ_tmp + segments->size[0] * ((int32_T)
                  b_succ_tmp - 1)) - 1].f1->size[0] = WAYPOINTS->size[0];
                emxEnsureCapacity_real_T(sp, segments_data[((int32_T)succ_tmp +
                  segments->size[0] * ((int32_T)b_succ_tmp - 1)) - 1].f1,
                  ipGTsize, &ab_emlrtRTEI);
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &te_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &bb_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp - 1 < 0) || ((int32_T)succ_tmp - 1 >
                     segments->size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp - 1, 0,
                    segments->size[0] - 1, &bc_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ue_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &cb_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp - 1 < 0) || ((int32_T)b_succ_tmp - 1 >
                     segments->size[1] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp - 1, 0,
                    segments->size[1] - 1, &cc_emlrtBCI, (emlrtConstCTX)sp);
                }

                ipGTsize = segments_data[((int32_T)succ_tmp + segments->size[0] *
                  ((int32_T)b_succ_tmp - 1)) - 1].f1->size[0] * segments_data
                  [((int32_T)succ_tmp + segments->size[0] * ((int32_T)b_succ_tmp
                     - 1)) - 1].f1->size[1];
                segments_data[((int32_T)succ_tmp + segments->size[0] * ((int32_T)
                  b_succ_tmp - 1)) - 1].f1->size[1] = 13;
                emxEnsureCapacity_real_T(sp, segments_data[((int32_T)succ_tmp +
                  segments->size[0] * ((int32_T)b_succ_tmp - 1)) - 1].f1,
                  ipGTsize, &ab_emlrtRTEI);
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &te_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &bb_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp - 1 < 0) || ((int32_T)succ_tmp - 1 >
                     segments->size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp - 1, 0,
                    segments->size[0] - 1, &bc_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ue_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &cb_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp - 1 < 0) || ((int32_T)b_succ_tmp - 1 >
                     segments->size[1] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp - 1, 0,
                    segments->size[1] - 1, &cc_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &te_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &bb_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp - 1 < 0) || ((int32_T)succ_tmp - 1 >
                     segments->size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp - 1, 0,
                    segments->size[0] - 1, &bc_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ue_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &cb_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp - 1 < 0) || ((int32_T)b_succ_tmp - 1 >
                     segments->size[1] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp - 1, 0,
                    segments->size[1] - 1, &cc_emlrtBCI, (emlrtConstCTX)sp);
                }

                loop_ub = WAYPOINTS->size[0] * 13;
                for (ipGTsize = 0; ipGTsize < loop_ub; ipGTsize++) {
                  if (item > trueCount) {
                    emlrtDynamicBoundsCheckR2012b(item, 1, trueCount,
                      &bf_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  if (succ_tmp != d) {
                    emlrtIntegerCheckR2012b(succ_tmp, &oc_emlrtDCI,
                      (emlrtConstCTX)sp);
                  }

                  if (((int32_T)succ_tmp - 1 < 0) || ((int32_T)succ_tmp - 1 > i8))
                  {
                    emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp - 1, 0, i8,
                      &af_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  if (item > trueCount) {
                    emlrtDynamicBoundsCheckR2012b(item, 1, trueCount,
                      &bf_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  if (b_succ_tmp != d1) {
                    emlrtIntegerCheckR2012b(b_succ_tmp, &oc_emlrtDCI,
                      (emlrtConstCTX)sp);
                  }

                  if (((int32_T)b_succ_tmp - 1 < 0) || ((int32_T)b_succ_tmp - 1 >
                       i9)) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp - 1, 0, i9,
                      &af_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  segments_data[((int32_T)succ_tmp + segments->size[0] *
                                 ((int32_T)b_succ_tmp - 1)) - 1].f1->
                    data[ipGTsize] = WAYPOINTS_data[ipGTsize];
                }

                /*  adjacent nodes path (only allowed neighbor nodes motion) */
                guard1 = true;
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }

            if (guard2 && (GA > 0.0)) {
              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &pd_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              d = (int32_T)muDoubleScalarFloor(succ_tmp);
              if (succ_tmp != d) {
                emlrtIntegerCheckR2012b(succ_tmp, &ac_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > G->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1, G->size[0],
                  &od_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &rd_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              d1 = (int32_T)muDoubleScalarFloor(b_succ_tmp);
              if (b_succ_tmp != d1) {
                emlrtIntegerCheckR2012b(b_succ_tmp, &bc_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp > G->size[1]))
              {
                emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1, G->size[1],
                  &qd_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (GA < G_data[((int32_T)succ_tmp + G->size[0] * ((int32_T)
                    b_succ_tmp - 1)) - 1]) {
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &td_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &cc_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > G->size[0]))
                {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1, G->size[0],
                    &sd_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &vd_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &dc_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp > G->size
                     [1])) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1, G->size
                    [1], &ud_emlrtBCI, (emlrtConstCTX)sp);
                }

                G_data[((int32_T)succ_tmp + G->size[0] * ((int32_T)b_succ_tmp -
                         1)) - 1] = GA;
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &wd_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &l_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > parent->
                     size[0])) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1,
                    parent->size[0], &bb_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &xd_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &m_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp >
                     parent->size[1])) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1,
                    parent->size[1], &cb_emlrtBCI, (emlrtConstCTX)sp);
                }

                parent_data[((int32_T)succ_tmp + parent->size[0] * ((int32_T)
                  b_succ_tmp - 1)) - 1] = p_tmp;
                parent_data[(((int32_T)succ_tmp + parent->size[0] * ((int32_T)
                  b_succ_tmp - 1)) + parent->size[0] * parent->size[1]) - 1] =
                  b_p_tmp;
                i8 = segments->size[0] - 1;
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &me_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &y_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp - 1 < 0) || ((int32_T)succ_tmp - 1 >
                     segments->size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp - 1, 0,
                    segments->size[0] - 1, &yb_emlrtBCI, (emlrtConstCTX)sp);
                }

                i9 = segments->size[1] - 1;
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &oe_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &ab_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp - 1 < 0) || ((int32_T)b_succ_tmp - 1 >
                     segments->size[1] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp - 1, 0,
                    segments->size[1] - 1, &ac_emlrtBCI, (emlrtConstCTX)sp);
                }

                ipGTsize = segments_data[((int32_T)succ_tmp + segments->size[0] *
                  ((int32_T)b_succ_tmp - 1)) - 1].f1->size[0] * segments_data
                  [((int32_T)succ_tmp + segments->size[0] * ((int32_T)b_succ_tmp
                     - 1)) - 1].f1->size[1];
                segments_data[((int32_T)succ_tmp + segments->size[0] * ((int32_T)
                  b_succ_tmp - 1)) - 1].f1->size[0] = ipGA_size[0];
                emxEnsureCapacity_real_T(sp, segments_data[((int32_T)succ_tmp +
                  segments->size[0] * ((int32_T)b_succ_tmp - 1)) - 1].f1,
                  ipGTsize, &y_emlrtRTEI);
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &me_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &y_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp - 1 < 0) || ((int32_T)succ_tmp - 1 >
                     segments->size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp - 1, 0,
                    segments->size[0] - 1, &yb_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &oe_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &ab_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp - 1 < 0) || ((int32_T)b_succ_tmp - 1 >
                     segments->size[1] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp - 1, 0,
                    segments->size[1] - 1, &ac_emlrtBCI, (emlrtConstCTX)sp);
                }

                ipGTsize = segments_data[((int32_T)succ_tmp + segments->size[0] *
                  ((int32_T)b_succ_tmp - 1)) - 1].f1->size[0] * segments_data
                  [((int32_T)succ_tmp + segments->size[0] * ((int32_T)b_succ_tmp
                     - 1)) - 1].f1->size[1];
                segments_data[((int32_T)succ_tmp + segments->size[0] * ((int32_T)
                  b_succ_tmp - 1)) - 1].f1->size[1] = 13;
                emxEnsureCapacity_real_T(sp, segments_data[((int32_T)succ_tmp +
                  segments->size[0] * ((int32_T)b_succ_tmp - 1)) - 1].f1,
                  ipGTsize, &y_emlrtRTEI);
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &me_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &y_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp - 1 < 0) || ((int32_T)succ_tmp - 1 >
                     segments->size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp - 1, 0,
                    segments->size[0] - 1, &yb_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &oe_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &ab_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp - 1 < 0) || ((int32_T)b_succ_tmp - 1 >
                     segments->size[1] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp - 1, 0,
                    segments->size[1] - 1, &ac_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &me_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &y_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp - 1 < 0) || ((int32_T)succ_tmp - 1 >
                     segments->size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp - 1, 0,
                    segments->size[0] - 1, &yb_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &oe_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &ab_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp - 1 < 0) || ((int32_T)b_succ_tmp - 1 >
                     segments->size[1] - 1)) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp - 1, 0,
                    segments->size[1] - 1, &ac_emlrtBCI, (emlrtConstCTX)sp);
                }

                loop_ub = ipGA_size[0] * 13;
                for (ipGTsize = 0; ipGTsize < loop_ub; ipGTsize++) {
                  if (item > trueCount) {
                    emlrtDynamicBoundsCheckR2012b(item, 1, trueCount,
                      &ye_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  if (succ_tmp != d) {
                    emlrtIntegerCheckR2012b(succ_tmp, &nc_emlrtDCI,
                      (emlrtConstCTX)sp);
                  }

                  if (((int32_T)succ_tmp - 1 < 0) || ((int32_T)succ_tmp - 1 > i8))
                  {
                    emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp - 1, 0, i8,
                      &xe_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  if (item > trueCount) {
                    emlrtDynamicBoundsCheckR2012b(item, 1, trueCount,
                      &ye_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  if (b_succ_tmp != d1) {
                    emlrtIntegerCheckR2012b(b_succ_tmp, &nc_emlrtDCI,
                      (emlrtConstCTX)sp);
                  }

                  if (((int32_T)b_succ_tmp - 1 < 0) || ((int32_T)b_succ_tmp - 1 >
                       i9)) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp - 1, 0, i9,
                      &xe_emlrtBCI, (emlrtConstCTX)sp);
                  }

                  segments_data[((int32_T)succ_tmp + segments->size[0] *
                                 ((int32_T)b_succ_tmp - 1)) - 1].f1->
                    data[ipGTsize] = ipGA_data[ipGTsize];
                }

                guard1 = true;
              }
            }

            if (guard1) {
              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ae_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              d = (int32_T)muDoubleScalarFloor(succ_tmp);
              if (succ_tmp != d) {
                emlrtIntegerCheckR2012b(succ_tmp, &ec_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > G->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1, G->size[0],
                  &yd_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ce_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              d1 = (int32_T)muDoubleScalarFloor(b_succ_tmp);
              if (b_succ_tmp != d1) {
                emlrtIntegerCheckR2012b(b_succ_tmp, &fc_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp > G->size[1]))
              {
                emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1, G->size[1],
                  &be_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ee_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              if (succ_tmp != d) {
                emlrtIntegerCheckR2012b(succ_tmp, &gc_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > H->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1, H->size[0],
                  &de_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ge_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              if (b_succ_tmp != d1) {
                emlrtIntegerCheckR2012b(b_succ_tmp, &hc_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp > H->size[1]))
              {
                emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1, H->size[1],
                  &fe_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ie_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              if (succ_tmp != d) {
                emlrtIntegerCheckR2012b(succ_tmp, &ic_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > F->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1, F->size[0],
                  &he_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &ke_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              if (b_succ_tmp != d1) {
                emlrtIntegerCheckR2012b(b_succ_tmp, &jc_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp > F->size[1]))
              {
                emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1, F->size[1],
                  &je_emlrtBCI, (emlrtConstCTX)sp);
              }

              F_data[((int32_T)succ_tmp + F->size[0] * ((int32_T)b_succ_tmp - 1))
                - 1] = G_data[((int32_T)succ_tmp + G->size[0] * ((int32_T)
                b_succ_tmp - 1)) - 1] + H_data[((int32_T)succ_tmp + H->size[0] *
                ((int32_T)b_succ_tmp - 1)) - 1];
              st.site = &g_emlrtRSI;
              if (enabled_reexpansions != 0.0) {
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &qe_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (succ_tmp != d) {
                  emlrtIntegerCheckR2012b(succ_tmp, &kc_emlrtDCI, (emlrtConstCTX)
                    sp);
                }

                if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > CLOSED->
                     size[0])) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1,
                    CLOSED->size[0], &pe_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &se_emlrtBCI,
                    (emlrtConstCTX)sp);
                }

                if (b_succ_tmp != d1) {
                  emlrtIntegerCheckR2012b(b_succ_tmp, &lc_emlrtDCI,
                    (emlrtConstCTX)sp);
                }

                if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp >
                     CLOSED->size[1])) {
                  emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1,
                    CLOSED->size[1], &re_emlrtBCI, (emlrtConstCTX)sp);
                }

                if (CLOSED_data[((int32_T)succ_tmp + CLOSED->size[0] * ((int32_T)
                      b_succ_tmp - 1)) - 1]) {
                  numReexpandedNodes++;
                  numReexpandedNodes_dirty |= 1U;
                }
              }

              if (pos_OPEN > 0U) {
                loop_ub = (int32_T)pos_OPEN;
                if (((int32_T)pos_OPEN < 1) || ((int32_T)pos_OPEN > OPEN->size[0]))
                {
                  emlrtDynamicBoundsCheckR2012b((int32_T)pos_OPEN, 1, OPEN->
                    size[0], &eb_emlrtBCI, (emlrtConstCTX)sp);
                }

                st.site = &f_emlrtRSI;
                if (item > trueCount) {
                  emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &db_emlrtBCI,
                    &st);
                }

                i8 = iop->size[0] * iop->size[1];
                iop->size[0] = (int32_T)pos_OPEN;
                iop->size[1] = 2;
                emxEnsureCapacity_real_T(&st, iop, i8, &cb_emlrtRTEI);
                iop_data = iop->data;
                for (i8 = 0; i8 < 2; i8++) {
                  b_succ[i8] = succ_data[(item + trueCount * i8) - 1];
                  for (i9 = 0; i9 < loop_ub; i9++) {
                    iop_data[i9 + iop->size[0] * i8] = OPEN_data[i9 + OPEN->
                      size[0] * i8];
                  }
                }

                b_st.site = &pc_emlrtRSI;
                found = b_isMemberRows(&b_st, b_succ, iop, &ipGTsize);
                idx = ipGTsize;
              } else {
                found = false;
              }

              if (!found) {
                pos_OPEN++;
                idx = pos_OPEN;
                if (pos_OPEN > (uint32_T)OPEN->size[0]) {
                  i8 = b_OPEN->size[0] * b_OPEN->size[1];
                  b_OPEN->size[0] = OPEN->size[0];
                  b_OPEN->size[1] = 3;
                  emxEnsureCapacity_real_T(sp, b_OPEN, i8, &bb_emlrtRTEI);
                  iop_data = b_OPEN->data;
                  loop_ub = OPEN->size[0] * OPEN->size[1] - 1;
                  for (i8 = 0; i8 <= loop_ub; i8++) {
                    iop_data[i8] = OPEN_data[i8];
                  }

                  st.site = &e_emlrtRSI;
                  c_repmat(&st, b_OPEN, OPEN);
                  OPEN_data = OPEN->data;
                }
              }

              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &fb_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              if (idx != (int32_T)idx) {
                emlrtIntegerCheckR2012b(idx, &n_emlrtDCI, (emlrtConstCTX)sp);
              }

              if (((int32_T)idx < 1) || ((int32_T)idx > OPEN->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, OPEN->size[0],
                  &gb_emlrtBCI, (emlrtConstCTX)sp);
              }

              OPEN_data[(int32_T)idx - 1] = succ_tmp;
              OPEN_data[((int32_T)idx + OPEN->size[0]) - 1] = b_succ_tmp;
              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &we_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              if (succ_tmp != d) {
                emlrtIntegerCheckR2012b(succ_tmp, &mc_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)succ_tmp < 1) || ((int32_T)succ_tmp > F->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)succ_tmp, 1, F->size[0],
                  &ve_emlrtBCI, (emlrtConstCTX)sp);
              }

              if (item > trueCount) {
                emlrtDynamicBoundsCheckR2012b(item, 1, trueCount, &we_emlrtBCI,
                  (emlrtConstCTX)sp);
              }

              if (b_succ_tmp != d1) {
                emlrtIntegerCheckR2012b(b_succ_tmp, &mc_emlrtDCI, (emlrtConstCTX)
                  sp);
              }

              if (((int32_T)b_succ_tmp < 1) || ((int32_T)b_succ_tmp > F->size[1]))
              {
                emlrtDynamicBoundsCheckR2012b((int32_T)b_succ_tmp, 1, F->size[1],
                  &ve_emlrtBCI, (emlrtConstCTX)sp);
              }

              OPEN_data[((int32_T)idx + OPEN->size[0] * 2) - 1] = F_data
                [((int32_T)succ_tmp + F->size[0] * ((int32_T)b_succ_tmp - 1)) -
                1];
            }

            /* ========================================================================================== */
            item++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b((emlrtConstCTX)sp);
            }
          } else {
            exitg3 = 1;
          }
        } while (exitg3 == 0);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(sp, &b_OPEN);
  emxFree_real_T(sp, &iop);
  emxFree_real_T(sp, &H);
  emxFree_real_T(sp, &F);
  emxFree_real_T(sp, &OPEN);

  /* - returning the waypoint list */
  st.site = &d_emlrtRSI;
  if (muDoubleScalarIsNaN(mapasTiempo)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI, "MATLAB:nologicalnan",
      "MATLAB:nologicalnan", 0);
  }

  if (mapasTiempo != 0.0) {
    if (g[0] != (int32_T)muDoubleScalarFloor(g[0])) {
      emlrtIntegerCheckR2012b(g[0], &o_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)g[0] < 1) || ((int32_T)g[0] > parent->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)g[0], 1, parent->size[0],
        &hb_emlrtBCI, (emlrtConstCTX)sp);
    }

    if (g[1] != (int32_T)muDoubleScalarFloor(g[1])) {
      emlrtIntegerCheckR2012b(g[1], &p_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (((int32_T)g[1] < 1) || ((int32_T)g[1] > parent->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)g[1], 1, parent->size[1],
        &ib_emlrtBCI, (emlrtConstCTX)sp);
    }

    b_parent[0] = parent_data[((int32_T)g[0] + parent->size[0] * ((int32_T)g[1]
      - 1)) - 1];
    b_parent[1] = parent_data[(((int32_T)g[0] + parent->size[0] * ((int32_T)g[1]
      - 1)) + parent->size[0] * parent->size[1]) - 1];
    if (!b_isequaln(b_parent)) {
      p[0] = g[0];
      p[1] = g[1];
      i4 = WAYPOINTS->size[0] * WAYPOINTS->size[1];
      WAYPOINTS->size[0] = 10;
      WAYPOINTS->size[1] = 13;
      emxEnsureCapacity_real_T(sp, WAYPOINTS, i4, &q_emlrtRTEI);
      WAYPOINTS_data = WAYPOINTS->data;
      for (i4 = 0; i4 < 130; i4++) {
        WAYPOINTS_data[i4] = 0.0;
      }

      GT = 0.0;
      if (!isequal(p, s)) {
        iv[1] = 13;
      }

      while (!isequal(p, s)) {
        i4 = (int32_T)muDoubleScalarFloor(p[0]);
        if (p[0] != i4) {
          emlrtIntegerCheckR2012b(p[0], &q_emlrtDCI, (emlrtConstCTX)sp);
        }

        item = (int32_T)p[0];
        if ((item - 1 < 0.0) || (item - 1 > segments->size[0] - 1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)p[0] - 1, 0, segments->size[0]
            - 1, &sb_emlrtBCI, (emlrtConstCTX)sp);
        }

        i5 = (int32_T)muDoubleScalarFloor(p[1]);
        if (p[1] != i5) {
          emlrtIntegerCheckR2012b(p[1], &r_emlrtDCI, (emlrtConstCTX)sp);
        }

        k = (int32_T)p[1];
        if ((k - 1 < 0.0) || (k - 1 > segments->size[1] - 1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)p[1] - 1, 0, segments->size[1]
            - 1, &tb_emlrtBCI, (emlrtConstCTX)sp);
        }

        ipGTsize = segments_data[(item + segments->size[0] * (k - 1)) - 1]
          .f1->size[0];
        GT = (GT + (real_T)ipGTsize) - 1.0;
        if (GT > WAYPOINTS->size[0]) {
          b_parent[0] = muDoubleScalarCeil(GT / (real_T)WAYPOINTS->size[0]);
          b_parent[1] = 1.0;
          i6 = b_WAYPOINTS->size[0] * b_WAYPOINTS->size[1];
          b_WAYPOINTS->size[0] = WAYPOINTS->size[0];
          b_WAYPOINTS->size[1] = WAYPOINTS->size[1];
          emxEnsureCapacity_real_T(sp, b_WAYPOINTS, i6, &s_emlrtRTEI);
          b_WAYPOINTS_data = b_WAYPOINTS->data;
          loop_ub = WAYPOINTS->size[0] * WAYPOINTS->size[1] - 1;
          for (i6 = 0; i6 <= loop_ub; i6++) {
            b_WAYPOINTS_data[i6] = WAYPOINTS_data[i6];
          }

          st.site = &c_emlrtRSI;
          d_repmat(&st, b_WAYPOINTS, b_parent, WAYPOINTS);
          WAYPOINTS_data = WAYPOINTS->data;
        }

        if (item != i4) {
          emlrtIntegerCheckR2012b(p[0], &s_emlrtDCI, (emlrtConstCTX)sp);
        }

        if ((item - 1 < 0.0) || (item - 1 > segments->size[0] - 1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)p[0] - 1, 0, segments->size[0]
            - 1, &ub_emlrtBCI, (emlrtConstCTX)sp);
        }

        if (k != i5) {
          emlrtIntegerCheckR2012b(p[1], &t_emlrtDCI, (emlrtConstCTX)sp);
        }

        if ((k - 1 < 0.0) || (k - 1 > segments->size[1] - 1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)p[1] - 1, 0, segments->size[1]
            - 1, &vb_emlrtBCI, (emlrtConstCTX)sp);
        }

        if (segments_data[((int32_T)p[0] + segments->size[0] * ((int32_T)p[1] -
              1)) - 1].f1->size[0] < 2) {
          i6 = 0;
          i7 = 1;
          i8 = -1;
        } else {
          i6 = segments_data[((int32_T)p[0] + segments->size[0] * ((int32_T)p[1]
            - 1)) - 1].f1->size[0];
          i7 = segments_data[((int32_T)p[0] + segments->size[0] * ((int32_T)p[1]
            - 1)) - 1].f1->size[0];
          if ((i7 < 1) || (i7 > i6)) {
            emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &jb_emlrtBCI,
              (emlrtConstCTX)sp);
          }

          i6 = i7 - 1;
          i7 = -1;
          i8 = segments_data[((int32_T)p[0] + segments->size[0] * ((int32_T)p[1]
            - 1)) - 1].f1->size[0];
          if (i8 < 2) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i8, &kb_emlrtBCI, (emlrtConstCTX)
              sp);
          }

          i8 = 1;
        }

        if (item != i4) {
          emlrtIntegerCheckR2012b(p[0], &u_emlrtDCI, (emlrtConstCTX)sp);
        }

        if ((item - 1 < 0.0) || (item - 1 > segments->size[0] - 1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)p[0] - 1, 0, segments->size[0]
            - 1, &wb_emlrtBCI, (emlrtConstCTX)sp);
        }

        if (k != i5) {
          emlrtIntegerCheckR2012b(p[1], &v_emlrtDCI, (emlrtConstCTX)sp);
        }

        if ((k - 1 < 0.0) || (k - 1 > segments->size[1] - 1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)p[1] - 1, 0, segments->size[1]
            - 1, &xb_emlrtBCI, (emlrtConstCTX)sp);
        }

        d = (GT - (real_T)ipGTsize) + 2.0;
        if (d > GT) {
          i9 = 0;
          ipGTsize = 0;
        } else {
          if (((int32_T)d < 1) || ((int32_T)d > WAYPOINTS->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, WAYPOINTS->size[0],
              &lb_emlrtBCI, (emlrtConstCTX)sp);
          }

          i9 = (int32_T)d - 1;
          if (((int32_T)GT < 1) || ((int32_T)GT > WAYPOINTS->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)GT, 1, WAYPOINTS->size[0],
              &mb_emlrtBCI, (emlrtConstCTX)sp);
          }

          ipGTsize = (int32_T)GT;
        }

        loop_ub = ipGTsize - i9;
        c_WAYPOINTS[0] = loop_ub;
        c_WAYPOINTS[1] = 13;
        st.site = &ad_emlrtRSI;
        iv[0] = div_s32(&st, i8 - i6, i7) + 1;
        emlrtSubAssignSizeCheckR2012b(&c_WAYPOINTS[0], 2, &iv[0], 2, &emlrtECI,
          (emlrtCTX)sp);
        for (i8 = 0; i8 < 13; i8++) {
          for (ipGTsize = 0; ipGTsize < loop_ub; ipGTsize++) {
            WAYPOINTS_data[(i9 + ipGTsize) + WAYPOINTS->size[0] * i8] =
              segments_data[(item + segments->size[0] * (k - 1)) - 1].f1->data
              [(i6 + i7 * ipGTsize) + segments_data[(item + segments->size[0] *
              (k - 1)) - 1].f1->size[0] * i8];
          }
        }

        if (item != i4) {
          emlrtIntegerCheckR2012b(p[0], &w_emlrtDCI, (emlrtConstCTX)sp);
        }

        if ((p[0] < 1.0) || (item > parent->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)p[0], 1, parent->size[0],
            &nb_emlrtBCI, (emlrtConstCTX)sp);
        }

        if (k != i5) {
          emlrtIntegerCheckR2012b(p[1], &x_emlrtDCI, (emlrtConstCTX)sp);
        }

        if ((p[1] < 1.0) || (k > parent->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)p[1], 1, parent->size[1],
            &ob_emlrtBCI, (emlrtConstCTX)sp);
        }

        p[0] = parent_data[(item + parent->size[0] * (k - 1)) - 1];
        p[1] = parent_data[((item + parent->size[0] * (k - 1)) + parent->size[0]
                            * parent->size[1]) - 1];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }

      GT++;
      if (GT > WAYPOINTS->size[0]) {
        i4 = b_WAYPOINTS->size[0] * b_WAYPOINTS->size[1];
        b_WAYPOINTS->size[0] = WAYPOINTS->size[0];
        b_WAYPOINTS->size[1] = WAYPOINTS->size[1];
        emxEnsureCapacity_real_T(sp, b_WAYPOINTS, i4, &r_emlrtRTEI);
        b_WAYPOINTS_data = b_WAYPOINTS->data;
        loop_ub = WAYPOINTS->size[0] * WAYPOINTS->size[1] - 1;
        for (i4 = 0; i4 <= loop_ub; i4++) {
          b_WAYPOINTS_data[i4] = WAYPOINTS_data[i4];
        }

        st.site = &b_emlrtRSI;
        e_repmat(&st, b_WAYPOINTS, WAYPOINTS);
        WAYPOINTS_data = WAYPOINTS->data;
      }

      if (((int32_T)GT < 1) || ((int32_T)GT > WAYPOINTS->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)GT, 1, WAYPOINTS->size[0],
          &pb_emlrtBCI, (emlrtConstCTX)sp);
      }

      c_WAYPOINTS[0] = 1;
      iv[0] = 1;
      c_WAYPOINTS[1] = 13;
      iv[1] = 13;
      emlrtSubAssignSizeCheckR2012b(&c_WAYPOINTS[0], 2, &iv[0], 2, &b_emlrtECI,
        (emlrtCTX)sp);
      ipGTsize = (int32_T)GT - 1;
      WAYPOINTS_data[(int32_T)GT - 1] = s[0];
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0]) - 1] = s[1];
      if (i1 != i) {
        emlrtIntegerCheckR2012b(s[0], &kb_emlrtDCI, (emlrtConstCTX)sp);
      }

      if ((s[0] < 1.0) || (i1 > b_Z.contents->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)s[0], 1, b_Z.contents->size[0],
          &oc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (i3 != i2) {
        emlrtIntegerCheckR2012b(s[1], &kb_emlrtDCI, (emlrtConstCTX)sp);
      }

      if ((s[1] < 1.0) || (i3 > b_Z.contents->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)s[1], 1, b_Z.contents->size[1],
          &oc_emlrtBCI, (emlrtConstCTX)sp);
      }

      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 2) - 1] =
        b_Z.contents->data[(i1 + b_Z.contents->size[0] * (i3 - 1)) - 1];
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 3) - 1] = rtNaN;
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 4) - 1] = rtNaN;
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 5) - 1] = rtNaN;
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 6) - 1] = rtNaN;
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 7) - 1] = rtNaN;
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 10) - 1] = rtNaN;
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 8) - 1] = rtNaN;
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 11) - 1] = rtNaN;
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 9) - 1] = rtNaN;
      WAYPOINTS_data[((int32_T)GT + WAYPOINTS->size[0] * 12) - 1] = rtNaN;
      if (((int32_T)GT < 1) || ((int32_T)GT > WAYPOINTS->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)GT, 1, WAYPOINTS->size[0],
          &qb_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (WAYPOINTS->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, WAYPOINTS->size[0], &rb_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      i = waypoints->size[0] * waypoints->size[1];
      waypoints->size[0] = (int32_T)GT;
      waypoints->size[1] = 7;
      emxEnsureCapacity_real_T(sp, waypoints, i, &u_emlrtRTEI);
      iop_data = waypoints->data;
      for (i = 0; i < 7; i++) {
        for (i1 = 0; i1 <= ipGTsize; i1++) {
          iop_data[i1 + waypoints->size[0] * i] = WAYPOINTS_data[(((int32_T)GT -
            i1) + WAYPOINTS->size[0] * i) - 1];
        }
      }
    }
  }

  emxFree_real_T(sp, &b_WAYPOINTS);
  emxFree_real_T(sp, &WAYPOINTS);
  emxFreeStruct_captured_var(sp, &b_Z);
  st.site = &emlrtRSI;
  b_st.site = &uc_emlrtRSI;
  ipGTsize = CLOSED->size[0] * CLOSED->size[1];
  b_CLOSED = *CLOSED;
  c_CLOSED = ipGTsize;
  b_CLOSED.size = &c_CLOSED;
  b_CLOSED.numDimensions = 1;
  c_st.site = &vc_emlrtRSI;
  ipGTsize = combineVectorElements(&c_st, &b_CLOSED);
  emxFree_boolean_T(&b_st, &CLOSED);
  numExploredNodes = ipGTsize;
  numExploredNodes_dirty |= 1U;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void emlrt_checkEscapedGlobals(void)
{
  numExplorations_dirty |= numExplorations_dirty >> 1U;
  numExploredNodes_dirty |= numExploredNodes_dirty >> 1U;
  numReexpandedNodes_dirty |= numReexpandedNodes_dirty >> 1U;
}

/* End of code generation (DEMAIA.c) */
