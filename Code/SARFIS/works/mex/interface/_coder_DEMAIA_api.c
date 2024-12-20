/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_DEMAIA_api.c
 *
 * Code generation for function '_coder_DEMAIA_api'
 *
 */

/* Include files */
#include "_coder_DEMAIA_api.h"
#include "DEMAIA.h"
#include "DEMAIA_data.h"
#include "DEMAIA_emxutil.h"
#include "DEMAIA_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo mb_emlrtRTEI = {
    1,                   /* lineNo */
    1,                   /* colNo */
    "_coder_DEMAIA_api", /* fName */
    ""                   /* pName */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y);

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *d_emlrt_marshallOut(const emxArray_cell_wrap_0 *u);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[2];

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const real_T u);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T *y);

static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[9865881]);

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[4];

static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4];

static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static boolean_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[9865881]);

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4];

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T iv[3] = {0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(3, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 3);
  emlrtAssign(&y, m);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const emxArray_cell_wrap_0 *u)
{
  const cell_wrap_0 *u_data;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  int32_T n;
  u_data = u->data;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &u->size[0]));
  i = 0;
  n = u->size[0] * u->size[1];
  if (n > 0) {
    iv[1] = 13;
  }
  n = u->size[0] * u->size[1];
  while (i < n) {
    int32_T i1;
    b_y = NULL;
    iv[0] = u_data[i].f1->size[0];
    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    for (b_i = 0; b_i < 13; b_i++) {
      for (c_i = 0; c_i < u_data[i].f1->size[0]; c_i++) {
        pData[i1] = u_data[i].f1->data[c_i + u_data[i].f1->size[0] * b_i];
        i1++;
      }
    }
    emlrtAssign(&b_y, m);
    emlrtSetCell(y, i, b_y);
    i++;
  }
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[7] = {"symmetric",     "theta_threshold",
                                        "phi_threshold", "symmetric_threshold",
                                        "resolution",    "vMax",
                                        "table"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 7,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "symmetric";
  y->symmetric = i_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "symmetric")),
      &thisId);
  thisId.fIdentifier = "theta_threshold";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1,
                                                    "theta_threshold")),
                     &thisId, y->theta_threshold);
  thisId.fIdentifier = "phi_threshold";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2,
                                                    "phi_threshold")),
                     &thisId, y->phi_threshold);
  thisId.fIdentifier = "symmetric_threshold";
  y->symmetric_threshold = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3,
                                     "symmetric_threshold")),
      &thisId);
  thisId.fIdentifier = "resolution";
  y->resolution = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "resolution")),
      &thisId);
  thisId.fIdentifier = "vMax";
  y->vMax = b_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "vMax")),
      &thisId);
  thisId.fIdentifier = "table";
  k_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "table")),
      &thisId, y->table);
  emlrtDestroyArray(&u);
}

static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[9865881])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = m_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4]
{
  real_T(*y)[4];
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2] = {1, 2};
  real_T(*ret)[2];
  int32_T iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "logical", false, 0U,
                          (const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = {1, 2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[9865881])
{
  static const int32_T dims[2] = {3141, 3141};
  real_T(*r)[9865881];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[9865881])emlrtMxGetData(src);
  for (i = 0; i < 9865881; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4]
{
  static const int32_T dims[2] = {1, 4};
  real_T(*ret)[4];
  int32_T iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real_T(*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void DEMAIA_api(DEMAIAStackData *SD, const mxArray *const prhs[6], int32_T nlhs,
                const mxArray *plhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_cell_wrap_0 *segments;
  emxArray_real_T *G;
  emxArray_real_T *Z;
  emxArray_real_T *parent;
  emxArray_real_T *waypoints;
  real_T(*features)[4];
  real_T(*g)[2];
  real_T(*s)[2];
  real_T mapasTiempo;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  emxInit_real_T(&st, &Z, 2, &mb_emlrtRTEI, true);
  Z->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Z", Z);
  s = e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "s");
  g = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "g");
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "LUT_vRef", &SD->f1.LUT_vRef);
  features = l_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "features");
  mapasTiempo = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "mapasTiempo");
  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);
  /* Invoke the target function */
  emxInit_real_T(&st, &waypoints, 2, &mb_emlrtRTEI, true);
  emxInit_real_T(&st, &G, 2, &mb_emlrtRTEI, true);
  emxInit_real_T(&st, &parent, 3, &mb_emlrtRTEI, true);
  emxInit_cell_wrap_0(&st, &segments, &mb_emlrtRTEI);
  DEMAIA(SD, &st, Z, *s, *g, &SD->f1.LUT_vRef, *features, mapasTiempo,
         waypoints, G, parent, segments);
  emxFree_real_T(&st, &Z);
  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);
  /* Marshall function outputs */
  waypoints->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(waypoints);
  emxFree_real_T(&st, &waypoints);
  if (nlhs > 1) {
    G->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(G);
  }
  emxFree_real_T(&st, &G);
  if (nlhs > 2) {
    parent->canFreeData = false;
    plhs[2] = c_emlrt_marshallOut(parent);
  }
  emxFree_real_T(&st, &parent);
  if (nlhs > 3) {
    plhs[3] = d_emlrt_marshallOut(segments);
  }
  emxFree_cell_wrap_0(&st, &segments);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void MEXGlobalSyncInFunction(const emlrtStack *sp)
{
  const mxArray *tmp;
  /* Marshall in global variables */
  tmp = emlrtGetGlobalVariable("numExplorations");
  if (tmp != NULL) {
    numExplorations = emlrt_marshallIn(sp, tmp, "numExplorations");
    numExplorations_dirty = 0U;
  }
  tmp = emlrtGetGlobalVariable("numExploredNodes");
  if (tmp != NULL) {
    numExploredNodes = emlrt_marshallIn(sp, tmp, "numExploredNodes");
    numExploredNodes_dirty = 0U;
  }
  tmp = emlrtGetGlobalVariable("numReexpandedNodes");
  if (tmp != NULL) {
    numReexpandedNodes = emlrt_marshallIn(sp, tmp, "numReexpandedNodes");
    numReexpandedNodes_dirty = 0U;
  }
}

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck)
{
  /* Marshall out global variables */
  if (skipDirtyCheck || (numExplorations_dirty != 0U)) {
    emlrtPutGlobalVariable("numExplorations",
                           emlrt_marshallOut(numExplorations));
  }
  if (skipDirtyCheck || (numExploredNodes_dirty != 0U)) {
    emlrtPutGlobalVariable("numExploredNodes",
                           emlrt_marshallOut(numExploredNodes));
  }
  if (skipDirtyCheck || (numReexpandedNodes_dirty != 0U)) {
    emlrtPutGlobalVariable("numReexpandedNodes",
                           emlrt_marshallOut(numReexpandedNodes));
  }
}

void emlrt_synchGlobalsFromML(const emlrtStack *sp)
{
  MEXGlobalSyncInFunction(sp);
  numExplorations_dirty = 0U;
  numExploredNodes_dirty = 0U;
  numReexpandedNodes_dirty = 0U;
}

void emlrt_synchGlobalsToML(const emlrtStack *sp)
{
  (void)sp;
  MEXGlobalSyncOutFunction(false);
}

/* End of code generation (_coder_DEMAIA_api.c) */
