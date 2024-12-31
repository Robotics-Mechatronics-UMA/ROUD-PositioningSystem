/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * combineVectorElements.c
 *
 * Code generation for function 'combineVectorElements'
 *
 */

/* Include files */
#include "combineVectorElements.h"
#include "DEMAIA_data.h"
#include "DEMAIA_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo wc_emlrtRSI = {
    149,                     /* lineNo */
    "combineVectorElements", /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    209,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

/* Function Definitions */
int32_T combineVectorElements(const emlrtStack *sp, const emxArray_boolean_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  int32_T vlen;
  int32_T y;
  const boolean_T *x_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  vlen = x->size[0];
  if (x->size[0] == 0) {
    y = 0;
  } else {
    st.site = &wc_emlrtRSI;
    y = x_data[0];
    b_st.site = &xc_emlrtRSI;
    if (x->size[0] > 2147483646) {
      c_st.site = &lb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 2; k <= vlen; k++) {
      y += x_data[k - 1];
    }
  }
  return y;
}

/* End of code generation (combineVectorElements.c) */
