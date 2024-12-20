/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DEMAIA_emxutil.h
 *
 * Code generation for function 'DEMAIA_emxutil'
 *
 */

#pragma once

/* Include files */
#include "DEMAIA_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
                                 emxArray_boolean_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_0(const emlrtStack *sp,
                                   emxArray_cell_wrap_0 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation);

void emxFreeStruct_captured_var(const emlrtStack *sp, c_captured_var *pStruct);

void emxFreeStruct_cell_wrap_0(const emlrtStack *sp, cell_wrap_0 *pStruct);

void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray);

void emxFree_cell_wrap_0(const emlrtStack *sp,
                         emxArray_cell_wrap_0 **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxInitStruct_captured_var(const emlrtStack *sp, c_captured_var *pStruct,
                                const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_0(const emlrtStack *sp, cell_wrap_0 *pStruct,
                               const emlrtRTEInfo *srcLocation);

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                    boolean_T doPush);

void emxTrim_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0 *emxArray,
                         int32_T fromIndex, int32_T toIndex);

/* End of code generation (DEMAIA_emxutil.h) */
