/*
 * PIDPositionerF141_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PIDPositionerF141".
 *
 * Model version              : 1.65
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Mon Feb 25 16:26:39 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PIDPositionerF141_private_h_
#define RTW_HEADER_PIDPositionerF141_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);

/* private model entry point functions */
extern void PIDPositionerF141_derivatives(void);

#endif                                 /* RTW_HEADER_PIDPositionerF141_private_h_ */
