/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DEMAIA_types.h
 *
 * Code generation for function 'DEMAIA'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  boolean_T symmetric;
  real_T theta_threshold[2];
  real_T phi_threshold[2];
  real_T symmetric_threshold;
  real_T resolution;
  real_T vMax;
  real_T table[9865881];
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_b_captured_var
#define typedef_b_captured_var
typedef struct {
  struct0_T contents;
} b_captured_var;
#endif /* typedef_b_captured_var */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  emxArray_real_T *f1;
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0
typedef struct {
  cell_wrap_0 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_0;
#endif /* typedef_emxArray_cell_wrap_0 */

#ifndef typedef_c_captured_var
#define typedef_c_captured_var
typedef struct {
  emxArray_real_T *contents;
} c_captured_var;
#endif /* typedef_c_captured_var */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#ifndef typedef_b_DEMAIA
#define typedef_b_DEMAIA
typedef struct {
  b_captured_var LUT_vRef;
} b_DEMAIA;
#endif /* typedef_b_DEMAIA */

#ifndef typedef_b_DEMAIA_api
#define typedef_b_DEMAIA_api
typedef struct {
  struct0_T LUT_vRef;
} b_DEMAIA_api;
#endif /* typedef_b_DEMAIA_api */

#ifndef typedef_DEMAIAStackData
#define typedef_DEMAIAStackData
typedef struct {
  b_DEMAIA f0;
  b_DEMAIA_api f1;
} DEMAIAStackData;
#endif /* typedef_DEMAIAStackData */

/* End of code generation (DEMAIA_types.h) */
