/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diag.c
 *
 * Code generation for function 'diag'
 *
 */

/* Include files */
#include "diag.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo d_emlrtRTEI = {
    102,                                                     /* lineNo */
    19,                                                      /* colNo */
    "diag",                                                  /* fName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/elmat/diag.m" /* pName */
};

/* Function Definitions */
int32_T diag(const emlrtStack *sp, const boolean_T v_data[],
             const int32_T v_size[2], boolean_T d_data[])
{
  int32_T d_size;
  int32_T k;
  if ((v_size[0] == 1) && (v_size[1] == 1)) {
    d_size = 1;
    d_data[0] = v_data[0];
  } else {
    int32_T i;
    if ((v_size[0] == 1) || (v_size[1] == 1)) {
      emlrtErrorWithMessageIdR2018a(
          sp, &d_emlrtRTEI, "Coder:toolbox:diag_varsizedMatrixVector",
          "Coder:toolbox:diag_varsizedMatrixVector", 0);
    }
    if (v_size[1] > 0) {
      d_size = muIntScalarMin_sint32(v_size[0], v_size[1]);
    } else {
      d_size = 0;
    }
    i = d_size - 1;
    for (k = 0; k <= i; k++) {
      d_data[k] = v_data[k + v_size[0] * k];
    }
  }
  return d_size;
}

/* End of code generation (diag.c) */
