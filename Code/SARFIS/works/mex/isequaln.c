/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * isequaln.c
 *
 * Code generation for function 'isequaln'
 *
 */

/* Include files */
#include "isequaln.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
boolean_T b_isequaln(const real_T varargin_1[2])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!muDoubleScalarIsNaN(varargin_1[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  return p;
}

boolean_T isequaln(const real_T varargin_1[2], const real_T varargin_2[2])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((varargin_1[k] == varargin_2[k]) ||
        (muDoubleScalarIsNaN(varargin_1[k]) &&
         muDoubleScalarIsNaN(varargin_2[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  return p;
}

/* End of code generation (isequaln.c) */
