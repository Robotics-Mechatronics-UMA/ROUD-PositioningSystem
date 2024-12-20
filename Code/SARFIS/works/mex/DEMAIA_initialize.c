/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DEMAIA_initialize.c
 *
 * Code generation for function 'DEMAIA_initialize'
 *
 */

/* Include files */
#include "DEMAIA_initialize.h"
#include "DEMAIA_data.h"
#include "_coder_DEMAIA_api.h"
#include "_coder_DEMAIA_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void DEMAIA_once(const emlrtStack *sp);

/* Function Definitions */
static void DEMAIA_once(const emlrtStack *sp)
{
  mex_InitInfAndNan();
  numReexpandedNodes = 1.0;
  numReexpandedNodes_dirty = 1U;
  numExploredNodes = 1.0;
  numExploredNodes_dirty = 1U;
  numExplorations = 1.0;
  numExplorations_dirty = 1U;
  emlrtSetGlobalSyncFcn((emlrtCTX)sp, (void *)&emlrt_synchGlobalsToML);
}

void DEMAIA_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    DEMAIA_once(&st);
  }
}

/* End of code generation (DEMAIA_initialize.c) */
