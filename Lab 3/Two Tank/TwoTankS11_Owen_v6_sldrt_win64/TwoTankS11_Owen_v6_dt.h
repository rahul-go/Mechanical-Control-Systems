/*
 * TwoTankS11_Owen_v6_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TwoTankS11_Owen_v6".
 *
 * Model version              : 1.90
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Tue Feb 19 17:27:30 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&TwoTankS11_Owen_v6_B.Voltagefrombottomsensor), 0, 0, 17 }
  ,

  { (char_T *)(&TwoTankS11_Owen_v6_DW.TimeStampA), 0, 0, 4 },

  { (char_T *)(&TwoTankS11_Owen_v6_DW.Voltagefrombottomsensor_PWORK), 11, 0, 8 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  3U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&TwoTankS11_Owen_v6_P.Voltagefrombottomsensor_MaxMissedTicks), 0,
    0, 6 },

  { (char_T *)(&TwoTankS11_Owen_v6_P.Voltagefrombottomsensor_Channels), 6, 0, 9
  },

  { (char_T *)(&TwoTankS11_Owen_v6_P.Biasbottomtankinches_Value), 0, 0, 14 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] TwoTankS11_Owen_v6_dt.h */
