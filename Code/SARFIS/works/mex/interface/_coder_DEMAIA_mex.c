/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_DEMAIA_mex.c
 *
 * Code generation for function '_coder_DEMAIA_mex'
 *
 */

/* Include files */
#include "_coder_DEMAIA_mex.h"
#include "DEMAIA_data.h"
#include "DEMAIA_initialize.h"
#include "DEMAIA_terminate.h"
#include "DEMAIA_types.h"
#include "_coder_DEMAIA_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void DEMAIA_mexFunction(DEMAIAStackData *SD, int32_T nlhs, mxArray *plhs[4],
                        int32_T nrhs, const mxArray *prhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[4];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        6, "DEMAIA");
  }
  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 6,
                        "DEMAIA");
  }
  /* Call the function. */
  DEMAIA_api(SD, prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  DEMAIAStackData *DEMAIAStackDataGlobal = NULL;
  DEMAIAStackDataGlobal = (DEMAIAStackData *)emlrtMxCalloc(
      (size_t)1, (size_t)1U * sizeof(DEMAIAStackData));
  mexAtExit(&DEMAIA_atexit);
  /* Module initialization. */
  DEMAIA_initialize();
  /* Dispatch the entry-point. */
  DEMAIA_mexFunction(DEMAIAStackDataGlobal, nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  DEMAIA_terminate();
  emlrtMxFree(DEMAIAStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "US-ASCII", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_DEMAIA_mex.c) */
