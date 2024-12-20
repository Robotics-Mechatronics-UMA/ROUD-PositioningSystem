/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ismember.h
 *
 * Code generation for function 'ismember'
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
boolean_T b_isMemberRows(const emlrtStack *sp, const real_T A[2],
                         const emxArray_real_T *S, int32_T *loc);

boolean_T isMemberRows(const emlrtStack *sp, const real_T A[2],
                       const emxArray_real_T *S);

/* End of code generation (ismember.h) */
