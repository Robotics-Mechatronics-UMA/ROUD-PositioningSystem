/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DEMAIA.h
 *
 * Code generation for function 'DEMAIA'
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
void DEMAIA(DEMAIAStackData *SD, const emlrtStack *sp, const emxArray_real_T *Z,
            const real_T s[2], const real_T g[2], const struct0_T *LUT_vRef,
            const real_T features[4], real_T mapasTiempo,
            emxArray_real_T *waypoints, emxArray_real_T *G,
            emxArray_real_T *parent, emxArray_cell_wrap_0 *segments);

void emlrt_checkEscapedGlobals(void);

/* End of code generation (DEMAIA.h) */
