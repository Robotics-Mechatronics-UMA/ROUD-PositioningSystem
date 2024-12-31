/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ismember.c
 *
 * Code generation for function 'ismember'
 *
 */

/* Include files */
#include "ismember.h"
#include "DEMAIA_data.h"
#include "DEMAIA_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo sb_emlrtRSI = {
    95,                                                        /* lineNo */
    "isMemberRows",                                            /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/ops/ismember.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    484,                                                       /* lineNo */
    "isMemberRowsLinearSearch",                                /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/ops/ismember.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    93,                                                        /* lineNo */
    "isMemberRows",                                            /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/ops/ismember.m" /* pathName */
};

/* Function Definitions */
boolean_T b_isMemberRows(const emlrtStack *sp, const real_T A[2],
                         const emxArray_real_T *S, int32_T *loc)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *S_data;
  int32_T iRowS;
  boolean_T exitg1;
  boolean_T tf;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  S_data = S->data;
  st.site = &qc_emlrtRSI;
  tf = false;
  *loc = 0;
  b_st.site = &tb_emlrtRSI;
  if (S->size[0] > 2147483646) {
    c_st.site = &lb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  iRowS = 0;
  exitg1 = false;
  while ((!exitg1) && (iRowS <= S->size[0] - 1)) {
    int32_T j;
    boolean_T exitg2;
    boolean_T p;
    p = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 2)) {
      if (A[j] != S_data[iRowS + S->size[0] * j]) {
        p = false;
        exitg2 = true;
      } else {
        j++;
      }
    }
    if (p) {
      tf = true;
      *loc = iRowS + 1;
      exitg1 = true;
    } else {
      iRowS++;
    }
  }
  return tf;
}

boolean_T isMemberRows(const emlrtStack *sp, const real_T A[2],
                       const emxArray_real_T *S)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *S_data;
  int32_T iRowS;
  boolean_T exitg1;
  boolean_T tf;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  S_data = S->data;
  st.site = &sb_emlrtRSI;
  tf = false;
  b_st.site = &tb_emlrtRSI;
  if (S->size[0] > 2147483646) {
    c_st.site = &lb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  iRowS = 0;
  exitg1 = false;
  while ((!exitg1) && (iRowS <= S->size[0] - 1)) {
    int32_T j;
    boolean_T exitg2;
    boolean_T p;
    p = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 2)) {
      if (A[j] != S_data[iRowS + S->size[0] * j]) {
        p = false;
        exitg2 = true;
      } else {
        j++;
      }
    }
    if (p) {
      tf = true;
      exitg1 = true;
    } else {
      iRowS++;
    }
  }
  return tf;
}

/* End of code generation (ismember.c) */
