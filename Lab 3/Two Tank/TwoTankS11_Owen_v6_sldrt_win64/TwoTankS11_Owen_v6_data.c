/*
 * TwoTankS11_Owen_v6_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TwoTankS11_Owen_v6".
 *
 * Model version              : 1.79
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Mon Feb 11 17:23:36 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TwoTankS11_Owen_v6.h"
#include "TwoTankS11_Owen_v6_private.h"

/* Block parameters (default storage) */
P_TwoTankS11_Owen_v6_T TwoTankS11_Owen_v6_P = {
  /* Mask Parameter: Voltagefrombottomsensor_MaxMissedTicks
   * Referenced by: '<Root>/Voltage from  bottom sensor'
   */
  10.0,

  /* Mask Parameter: Voltagefromtopsensor_MaxMissedTicks
   * Referenced by: '<Root>/Voltage from  top sensor'
   */
  10.0,

  /* Mask Parameter: Voltageouttovalve_MaxMissedTicks
   * Referenced by: '<Root>/Voltage out to valve'
   */
  10.0,

  /* Mask Parameter: Voltagefrombottomsensor_YieldWhenWaiting
   * Referenced by: '<Root>/Voltage from  bottom sensor'
   */
  0.0,

  /* Mask Parameter: Voltagefromtopsensor_YieldWhenWaiting
   * Referenced by: '<Root>/Voltage from  top sensor'
   */
  0.0,

  /* Mask Parameter: Voltageouttovalve_YieldWhenWaiting
   * Referenced by: '<Root>/Voltage out to valve'
   */
  0.0,

  /* Mask Parameter: Voltagefrombottomsensor_Channels
   * Referenced by: '<Root>/Voltage from  bottom sensor'
   */
  4,

  /* Mask Parameter: Voltagefromtopsensor_Channels
   * Referenced by: '<Root>/Voltage from  top sensor'
   */
  3,

  /* Mask Parameter: Voltageouttovalve_Channels
   * Referenced by: '<Root>/Voltage out to valve'
   */
  0,

  /* Mask Parameter: Voltagefrombottomsensor_RangeMode
   * Referenced by: '<Root>/Voltage from  bottom sensor'
   */
  0,

  /* Mask Parameter: Voltagefromtopsensor_RangeMode
   * Referenced by: '<Root>/Voltage from  top sensor'
   */
  0,

  /* Mask Parameter: Voltageouttovalve_RangeMode
   * Referenced by: '<Root>/Voltage out to valve'
   */
  0,

  /* Mask Parameter: Voltagefrombottomsensor_VoltRange
   * Referenced by: '<Root>/Voltage from  bottom sensor'
   */
  0,

  /* Mask Parameter: Voltagefromtopsensor_VoltRange
   * Referenced by: '<Root>/Voltage from  top sensor'
   */
  0,

  /* Mask Parameter: Voltageouttovalve_VoltRange
   * Referenced by: '<Root>/Voltage out to valve'
   */
  0,

  /* Expression: 4.3602
   * Referenced by: '<Root>/Bias -  bottom tank (inches)'
   */
  4.3602,

  /* Expression: 2.6769
   * Referenced by: '<Root>/Sensor gain - bottom tank (inches//volt)'
   */
  2.6769,

  /* Expression: 2.6760
   * Referenced by: '<Root>/Sensor gain - top tank (inches//volt)'
   */
  2.676,

  /* Expression: 4.0873
   * Referenced by: '<Root>/Top tank bias (inches)'
   */
  4.0873,

  /* Expression: 0
   * Referenced by: '<Root>/Desired height of bottom tank'
   */
  0.0,

  /* Expression: 3.5
   * Referenced by: '<Root>/Design valve actuation voltage'
   */
  3.5,

  /* Expression: 0
   * Referenced by: '<Root>/Design height of bottom tank'
   */
  0.0,

  /* Expression: 0.6
   * Referenced by: '<Root>/KP'
   */
  0.6,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/KI'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/KD'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Man=0 Auto=1'
   */
  0.0,

  /* Expression: -6.1525
   * Referenced by: '<Root>/Valve bias (% opening)'
   */
  -6.1525,

  /* Expression: 10.399
   * Referenced by: '<Root>/Valve gain (% opening// volt)'
   */
  10.399
};
