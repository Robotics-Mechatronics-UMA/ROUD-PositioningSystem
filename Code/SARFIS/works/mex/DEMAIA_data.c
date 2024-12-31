/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DEMAIA_data.c
 *
 * Code generation for function 'DEMAIA_data'
 *
 */

/* Include files */
#include "DEMAIA_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

real_T numExplorations;

real_T numExploredNodes;

real_T numReexpandedNodes;

uint32_T numExplorations_dirty;

uint32_T numExploredNodes_dirty;

uint32_T numReexpandedNodes_dirty;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131643U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "DEMAIA",                                             /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo lb_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

/* End of code generation (DEMAIA_data.c) */
