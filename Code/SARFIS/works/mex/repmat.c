/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "DEMAIA_data.h"
#include "DEMAIA_emxutil.h"
#include "DEMAIA_types.h"
#include "_coder_DEMAIA_api.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ub_emlrtRSI = {
    71,                                                        /* lineNo */
    "repmat",                                                  /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    69,                                                        /* lineNo */
    "repmat",                                                  /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    66,                                                        /* lineNo */
    "repmat",                                                  /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    28,                                                        /* lineNo */
    "repmat",                                                  /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    47,                                                        /* lineNo */
    5,                                                         /* colNo */
    "repmat",                                                  /* fName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI =
    {
        49,                   /* lineNo */
        19,                   /* colNo */
        "assertValidSizeArg", /* fName */
        "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/"
        "assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI =
    {
        64,                   /* lineNo */
        15,                   /* colNo */
        "assertValidSizeArg", /* fName */
        "/opt/matlab/R2023b/toolbox/eml/eml/+coder/+internal/"
        "assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    59,                                                        /* lineNo */
    28,                                                        /* colNo */
    "repmat",                                                  /* fName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pName */
};

static const char_T cv[15] = {'M', 'A', 'T', 'L', 'A', 'B', ':', 'p',
                              'm', 'a', 'x', 's', 'i', 'z', 'e'};

static emlrtRSInfo yc_emlrtRSI = {
    47,                                                        /* lineNo */
    "repmat",                                                  /* fcnName */
    "/opt/matlab/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" /* pathName */
};

/* Function Declarations */
static void b_error(const emlrtStack *sp, const mxArray *m,
                    emlrtMCInfo *location);

/* Function Definitions */
static void b_error(const emlrtStack *sp, const mxArray *m,
                    emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b((emlrtConstCTX)sp, 0, NULL, 1, &pArray, "error", true,
                        location);
}

void b_repmat(const emlrtStack *sp, const emxArray_real_T *a,
              emxArray_real_T *b)
{
  static const int32_T iv[2] = {1, 15};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *y;
  const real_T *a_data;
  real_T *b_data;
  int32_T itilerow;
  int32_T jcol;
  int32_T k;
  int32_T nrows;
  int32_T outsize_idx_0_tmp;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  a_data = a->data;
  m = NULL;
  outsize_idx_0_tmp = a->size[0] << 1;
  if (!(outsize_idx_0_tmp == (real_T)a->size[0] * 2.0)) {
    y = NULL;
    m1 = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 15, m1, &cv[0]);
    emlrtAssign(&y, m1);
    emlrtAssign(&m, y);
    emlrt_synchGlobalsToML(sp);
    st.site = &yc_emlrtRSI;
    b_error(&st, emlrtAlias(m), &emlrtMCI);
  }
  nrows = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0_tmp;
  b->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b, nrows, &lb_emlrtRTEI);
  b_data = b->data;
  nrows = a->size[0];
  overflow = (a->size[0] > 2147483646);
  for (jcol = 0; jcol < 2; jcol++) {
    int32_T iacol;
    int32_T ibmat;
    iacol = jcol * nrows;
    ibmat = jcol * outsize_idx_0_tmp - 1;
    for (itilerow = 0; itilerow < 2; itilerow++) {
      int32_T ibcol;
      ibcol = ibmat + itilerow * nrows;
      st.site = &ub_emlrtRSI;
      if (overflow) {
        b_st.site = &lb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (k = 0; k < nrows; k++) {
        b_data[(ibcol + k) + 1] = a_data[iacol + k];
      }
    }
  }
  emlrtDestroyArray(&m);
}

void c_repmat(const emlrtStack *sp, const emxArray_real_T *a,
              emxArray_real_T *b)
{
  static const int32_T iv[2] = {1, 15};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *y;
  const real_T *a_data;
  real_T *b_data;
  int32_T itilerow;
  int32_T jcol;
  int32_T k;
  int32_T nrows;
  int32_T outsize_idx_0_tmp;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  a_data = a->data;
  m = NULL;
  outsize_idx_0_tmp = a->size[0] << 1;
  if (!(outsize_idx_0_tmp == (real_T)a->size[0] * 2.0)) {
    y = NULL;
    m1 = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 15, m1, &cv[0]);
    emlrtAssign(&y, m1);
    emlrtAssign(&m, y);
    emlrt_synchGlobalsToML(sp);
    st.site = &yc_emlrtRSI;
    b_error(&st, emlrtAlias(m), &emlrtMCI);
  }
  nrows = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0_tmp;
  b->size[1] = 3;
  emxEnsureCapacity_real_T(sp, b, nrows, &lb_emlrtRTEI);
  b_data = b->data;
  nrows = a->size[0];
  overflow = (a->size[0] > 2147483646);
  for (jcol = 0; jcol < 3; jcol++) {
    int32_T iacol;
    int32_T ibmat;
    iacol = jcol * nrows;
    ibmat = jcol * outsize_idx_0_tmp - 1;
    for (itilerow = 0; itilerow < 2; itilerow++) {
      int32_T ibcol;
      ibcol = ibmat + itilerow * nrows;
      st.site = &ub_emlrtRSI;
      if (overflow) {
        b_st.site = &lb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (k = 0; k < nrows; k++) {
        b_data[(ibcol + k) + 1] = a_data[iacol + k];
      }
    }
  }
  emlrtDestroyArray(&m);
}

void d_repmat(const emlrtStack *sp, const emxArray_real_T *a,
              const real_T varargin_1[2], emxArray_real_T *b)
{
  static const int32_T iv[2] = {1, 15};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *y;
  const real_T *a_data;
  real_T *b_data;
  int32_T exitg2;
  int32_T itilerow;
  int32_T jcol;
  int32_T k;
  int32_T nrows;
  int32_T ntilerows;
  int32_T outsize_idx_0_tmp;
  boolean_T b_overflow;
  boolean_T guard1;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  a_data = a->data;
  m = NULL;
  st.site = &tc_emlrtRSI;
  k = 0;
  guard1 = false;
  do {
    exitg2 = 0;
    if (k < 2) {
      if ((varargin_1[k] != varargin_1[k]) ||
          muDoubleScalarIsInf(varargin_1[k])) {
        guard1 = true;
        exitg2 = 1;
      } else {
        k++;
        guard1 = false;
      }
    } else {
      k = 0;
      exitg2 = 2;
    }
  } while (exitg2 == 0);
  if (exitg2 != 1) {
    boolean_T exitg1;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (varargin_1[k] > 2.147483647E+9) {
        guard1 = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &e_emlrtRTEI,
        "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector",
        "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
        MIN_int32_T, 12, MAX_int32_T);
  }
  if (!(varargin_1[0] * varargin_1[1] <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  outsize_idx_0_tmp = a->size[0] * (int32_T)varargin_1[0];
  if (!(outsize_idx_0_tmp ==
        (real_T)a->size[0] * (real_T)(int32_T)varargin_1[0])) {
    y = NULL;
    m1 = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 15, m1, &cv[0]);
    emlrtAssign(&y, m1);
    emlrtAssign(&m, y);
    emlrt_synchGlobalsToML(sp);
    st.site = &yc_emlrtRSI;
    b_error(&st, emlrtAlias(m), &emlrtMCI);
  }
  nrows = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0_tmp;
  b->size[1] = 13;
  emxEnsureCapacity_real_T(sp, b, nrows, &lb_emlrtRTEI);
  b_data = b->data;
  nrows = a->size[0];
  ntilerows = (int32_T)varargin_1[0];
  st.site = &sc_emlrtRSI;
  overflow = ((int32_T)varargin_1[0] > 2147483646);
  b_overflow = (a->size[0] > 2147483646);
  for (jcol = 0; jcol < 13; jcol++) {
    int32_T iacol;
    int32_T ibmat;
    iacol = jcol * nrows;
    ibmat = jcol * outsize_idx_0_tmp - 1;
    st.site = &rc_emlrtRSI;
    if (overflow) {
      b_st.site = &lb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      int32_T ibcol;
      ibcol = ibmat + itilerow * nrows;
      st.site = &ub_emlrtRSI;
      if (b_overflow) {
        b_st.site = &lb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (k = 0; k < nrows; k++) {
        b_data[(ibcol + k) + 1] = a_data[iacol + k];
      }
    }
  }
  emlrtDestroyArray(&m);
}

void e_repmat(const emlrtStack *sp, const emxArray_real_T *a,
              emxArray_real_T *b)
{
  static const int32_T iv[2] = {1, 15};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *y;
  const real_T *a_data;
  real_T *b_data;
  int32_T itilerow;
  int32_T jcol;
  int32_T k;
  int32_T nrows;
  int32_T outsize_idx_0_tmp;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  a_data = a->data;
  m = NULL;
  outsize_idx_0_tmp = a->size[0] << 1;
  if (!(outsize_idx_0_tmp == (real_T)a->size[0] * 2.0)) {
    y = NULL;
    m1 = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 15, m1, &cv[0]);
    emlrtAssign(&y, m1);
    emlrtAssign(&m, y);
    emlrt_synchGlobalsToML(sp);
    st.site = &yc_emlrtRSI;
    b_error(&st, emlrtAlias(m), &emlrtMCI);
  }
  nrows = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0_tmp;
  b->size[1] = 13;
  emxEnsureCapacity_real_T(sp, b, nrows, &lb_emlrtRTEI);
  b_data = b->data;
  nrows = a->size[0];
  st.site = &sc_emlrtRSI;
  overflow = (a->size[0] > 2147483646);
  for (jcol = 0; jcol < 13; jcol++) {
    int32_T iacol;
    int32_T ibmat;
    iacol = jcol * nrows;
    ibmat = jcol * outsize_idx_0_tmp - 1;
    for (itilerow = 0; itilerow < 2; itilerow++) {
      int32_T ibcol;
      ibcol = ibmat + itilerow * nrows;
      st.site = &ub_emlrtRSI;
      if (overflow) {
        b_st.site = &lb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (k = 0; k < nrows; k++) {
        b_data[(ibcol + k) + 1] = a_data[iacol + k];
      }
    }
  }
  emlrtDestroyArray(&m);
}

void repmat(const real_T a[2], real_T b[16])
{
  int32_T itilerow;
  int32_T jcol;
  for (jcol = 0; jcol < 2; jcol++) {
    int32_T ibmat;
    ibmat = jcol << 3;
    for (itilerow = 0; itilerow < 8; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

/* End of code generation (repmat.c) */
