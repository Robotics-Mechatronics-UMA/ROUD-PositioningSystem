/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DEMAIA_terminate.c
 *
 * Code generation for function 'DEMAIA_terminate'
 *
 */

/* Include files */
#include "DEMAIA_terminate.h"
#include "DEMAIA_data.h"
#include "_coder_DEMAIA_api.h"
#include "_coder_DEMAIA_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void DEMAIA_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrt_synchGlobalsFromML(&st);
  emlrt_synchGlobalsToML(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void DEMAIA_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (DEMAIA_terminate.c) */
