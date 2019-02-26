/*
 * OpenLoop1_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OpenLoop1".
 *
 * Model version              : 1.28
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Mon Feb 25 16:12:48 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OpenLoop1.h"
#include "OpenLoop1_private.h"

/* Block parameters (default storage) */
P_OpenLoop1_T OpenLoop1_P = {
  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: Voltageinfrompotentiometer_MaxMissedTicks
   * Referenced by: '<Root>/Voltage in from potentiometer'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: Voltageinfrompotentiometer_YieldWhenWaiting
   * Referenced by: '<Root>/Voltage in from potentiometer'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: Voltageinfrompotentiometer_Channels
   * Referenced by: '<Root>/Voltage in from potentiometer'
   */
  1,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: Voltageinfrompotentiometer_RangeMode
   * Referenced by: '<Root>/Voltage in from potentiometer'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: Voltageinfrompotentiometer_VoltRange
   * Referenced by: '<Root>/Voltage in from potentiometer'
   */
  0,

  /* Expression: 0
   * Referenced by: '<Root>/Voltage out to servo valve'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<Root>/-10<V<10'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<Root>/-10<V<10'
   */
  -10.0,

  /* Expression: 0.6011
   * Referenced by: '<Root>/Gain'
   */
  0.6011,

  /* Expression: 0.3633
   * Referenced by: '<Root>/Offset'
   */
  0.3633
};
