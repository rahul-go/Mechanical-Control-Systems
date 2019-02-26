/*
 * PIDPositionerF141_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PIDPositionerF141".
 *
 * Model version              : 1.65
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Mon Feb 25 16:40:29 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PIDPositionerF141.h"
#include "PIDPositionerF141_private.h"

/* Block parameters (default storage) */
P_PIDPositionerF141_T PIDPositionerF141_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S1>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S1>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S1>/Derivative Divisor'
   */
  600.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S1>/Proportional Gain'
   */
  82.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: RepeatingSequence_rep_seq_y
   * Referenced by: '<S2>/Look-Up Table1'
   */
  { 0.0, 0.0, 0.2, 0.2, 0.0 },

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<Root>/Analog Input'
   */
  1,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Expression: period
   * Referenced by: '<S2>/Constant'
   */
  2.0,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S2>/Look-Up Table1'
   */
  { 0.0, 1.0, 1.001, 1.999, 2.0 },

  /* Expression: 0.6011
   * Referenced by: '<Root>/Feedback Sensor Gain (in//V)'
   */
  0.6011,

  /* Expression: 0.3633
   * Referenced by: '<Root>/Potentiometer Offset (inches)'
   */
  0.3633,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Filter'
   */
  0.0
};
