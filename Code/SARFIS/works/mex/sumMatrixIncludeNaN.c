/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "rt_nonfinite.h"

/* Function Definitions */
real_T b_sumColumnB(const real_T x[4])
{
  return ((x[0] + x[1]) + x[2]) + x[3];
}

real_T c_sumColumnB(const real_T x[2])
{
  return x[0] + x[1];
}

real_T sumColumnB(const real_T x[3])
{
  return (x[0] + x[1]) + x[2];
}

/* End of code generation (sumMatrixIncludeNaN.c) */
