/*
 * TwoTankS11_Owen_v6.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TwoTankS11_Owen_v6".
 *
 * Model version              : 1.82
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Tue Feb 19 15:44:18 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TwoTankS11_Owen_v6.h"
#include "TwoTankS11_Owen_v6_private.h"
#include "TwoTankS11_Owen_v6_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  1.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 2;
const double SLDRTTimers[4] = {
  0.1, 0.0,
  1.0, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-MIO-16E-4", 4294967295U, 6, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_TwoTankS11_Owen_v6_T TwoTankS11_Owen_v6_B;

/* Continuous states */
X_TwoTankS11_Owen_v6_T TwoTankS11_Owen_v6_X;

/* Block states (default storage) */
DW_TwoTankS11_Owen_v6_T TwoTankS11_Owen_v6_DW;

/* Real-time model */
RT_MODEL_TwoTankS11_Owen_v6_T TwoTankS11_Owen_v6_M_;
RT_MODEL_TwoTankS11_Owen_v6_T *const TwoTankS11_Owen_v6_M =
  &TwoTankS11_Owen_v6_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(TwoTankS11_Owen_v6_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(TwoTankS11_Owen_v6_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (TwoTankS11_Owen_v6_M->Timing.TaskCounters.TID[1] == 0) {
    TwoTankS11_Owen_v6_M->Timing.RateInteraction.TID1_2 =
      (TwoTankS11_Owen_v6_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    TwoTankS11_Owen_v6_M->Timing.perTaskSampleHits[5] =
      TwoTankS11_Owen_v6_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (TwoTankS11_Owen_v6_M->Timing.TaskCounters.TID[2])++;
  if ((TwoTankS11_Owen_v6_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [1.0s, 0.0s] */
    TwoTankS11_Owen_v6_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TwoTankS11_Owen_v6_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  TwoTankS11_Owen_v6_output0();
  TwoTankS11_Owen_v6_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  TwoTankS11_Owen_v6_output0();
  TwoTankS11_Owen_v6_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void TwoTankS11_Owen_v6_output0(void)  /* Sample time: [0.0s, 0.0s] */
{
  real_T *lastU;
  real_T rtb_Derivative;
  if (rtmIsMajorTimeStep(TwoTankS11_Owen_v6_M)) {
    /* set solver stop time */
    if (!(TwoTankS11_Owen_v6_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&TwoTankS11_Owen_v6_M->solverInfo,
                            ((TwoTankS11_Owen_v6_M->Timing.clockTickH0 + 1) *
        TwoTankS11_Owen_v6_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&TwoTankS11_Owen_v6_M->solverInfo,
                            ((TwoTankS11_Owen_v6_M->Timing.clockTick0 + 1) *
        TwoTankS11_Owen_v6_M->Timing.stepSize0 +
        TwoTankS11_Owen_v6_M->Timing.clockTickH0 *
        TwoTankS11_Owen_v6_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TwoTankS11_Owen_v6_M)) {
    TwoTankS11_Owen_v6_M->Timing.t[0] = rtsiGetT
      (&TwoTankS11_Owen_v6_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(TwoTankS11_Owen_v6_M)) {
    /* S-Function (sldrtai): '<Root>/Voltage from  bottom sensor' */
    /* S-Function Block: <Root>/Voltage from  bottom sensor */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        TwoTankS11_Owen_v6_P.Voltagefrombottomsensor_RangeMode;
      parm.rangeidx = TwoTankS11_Owen_v6_P.Voltagefrombottomsensor_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &TwoTankS11_Owen_v6_P.Voltagefrombottomsensor_Channels,
                     &TwoTankS11_Owen_v6_B.Voltagefrombottomsensor, &parm);
    }

    /* S-Function (sldrtai): '<Root>/Voltage from  top sensor' */
    /* S-Function Block: <Root>/Voltage from  top sensor */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        TwoTankS11_Owen_v6_P.Voltagefromtopsensor_RangeMode;
      parm.rangeidx = TwoTankS11_Owen_v6_P.Voltagefromtopsensor_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &TwoTankS11_Owen_v6_P.Voltagefromtopsensor_Channels,
                     &TwoTankS11_Owen_v6_B.Voltagefromtopsensor, &parm);
    }

    /* Sum: '<Root>/Sum8' incorporates:
     *  Constant: '<Root>/Bias -  bottom tank (inches)'
     *  Gain: '<Root>/Sensor gain - bottom tank (inches//volt)'
     */
    TwoTankS11_Owen_v6_B.Sum8 =
      TwoTankS11_Owen_v6_P.Sensorgainbottomtankinchesvolt_Gain *
      TwoTankS11_Owen_v6_B.Voltagefrombottomsensor -
      TwoTankS11_Owen_v6_P.Biasbottomtankinches_Value;

    /* Sum: '<Root>/Sum4' incorporates:
     *  Constant: '<Root>/Top tank bias (inches)'
     *  Gain: '<Root>/Sensor gain - top tank (inches//volt)'
     */
    TwoTankS11_Owen_v6_B.Sum4 =
      TwoTankS11_Owen_v6_P.Sensorgaintoptankinchesvolt_Gain *
      TwoTankS11_Owen_v6_B.Voltagefromtopsensor -
      TwoTankS11_Owen_v6_P.Toptankbiasinches_Value;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Design height of bottom tank'
     *  Constant: '<Root>/Desired height of bottom tank'
     *  Sum: '<Root>/Sum'
     *  Sum: '<Root>/Sum5'
     */
    TwoTankS11_Owen_v6_B.Sum1 =
      (TwoTankS11_Owen_v6_P.Desiredheightofbottomtank_Value -
       TwoTankS11_Owen_v6_P.Designheightofbottomtank_Value) -
      (TwoTankS11_Owen_v6_B.Sum8 -
       TwoTankS11_Owen_v6_P.Designheightofbottomtank_Value);

    /* Gain: '<Root>/KP' */
    TwoTankS11_Owen_v6_B.KP = TwoTankS11_Owen_v6_P.KP_Gain *
      TwoTankS11_Owen_v6_B.Sum1;
  }

  /* Clock: '<Root>/Clock' */
  TwoTankS11_Owen_v6_B.Clock = TwoTankS11_Owen_v6_M->Timing.t[0];

  /* Derivative: '<Root>/Derivative' */
  if ((TwoTankS11_Owen_v6_DW.TimeStampA >= TwoTankS11_Owen_v6_M->Timing.t[0]) &&
      (TwoTankS11_Owen_v6_DW.TimeStampB >= TwoTankS11_Owen_v6_M->Timing.t[0])) {
    rtb_Derivative = 0.0;
  } else {
    rtb_Derivative = TwoTankS11_Owen_v6_DW.TimeStampA;
    lastU = &TwoTankS11_Owen_v6_DW.LastUAtTimeA;
    if (TwoTankS11_Owen_v6_DW.TimeStampA < TwoTankS11_Owen_v6_DW.TimeStampB) {
      if (TwoTankS11_Owen_v6_DW.TimeStampB < TwoTankS11_Owen_v6_M->Timing.t[0])
      {
        rtb_Derivative = TwoTankS11_Owen_v6_DW.TimeStampB;
        lastU = &TwoTankS11_Owen_v6_DW.LastUAtTimeB;
      }
    } else {
      if (TwoTankS11_Owen_v6_DW.TimeStampA >= TwoTankS11_Owen_v6_M->Timing.t[0])
      {
        rtb_Derivative = TwoTankS11_Owen_v6_DW.TimeStampB;
        lastU = &TwoTankS11_Owen_v6_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (TwoTankS11_Owen_v6_B.Sum1 - *lastU) /
      (TwoTankS11_Owen_v6_M->Timing.t[0] - rtb_Derivative);
  }

  /* End of Derivative: '<Root>/Derivative' */

  /* Sum: '<Root>/Sum3' incorporates:
   *  Constant: '<Root>/Design valve actuation voltage'
   *  Gain: '<Root>/KD'
   *  Gain: '<Root>/KI'
   *  Gain: '<Root>/Man=0 Auto=1'
   *  Integrator: '<Root>/Integrator'
   *  Sum: '<Root>/Sum2'
   */
  TwoTankS11_Owen_v6_B.Sum3 = ((TwoTankS11_Owen_v6_P.KI_Gain *
    TwoTankS11_Owen_v6_X.Integrator_CSTATE + TwoTankS11_Owen_v6_B.KP) +
    TwoTankS11_Owen_v6_P.KD_Gain * rtb_Derivative) *
    TwoTankS11_Owen_v6_P.Man0Auto1_Gain +
    TwoTankS11_Owen_v6_P.Designvalveactuationvoltage_Value;

  /* Sum: '<Root>/Sum7' incorporates:
   *  Constant: '<Root>/Valve bias (% opening)'
   *  Gain: '<Root>/Valve gain (% opening// volt)'
   */
  TwoTankS11_Owen_v6_B.Sum7 = TwoTankS11_Owen_v6_P.Valvegainopeningvolt_Gain *
    TwoTankS11_Owen_v6_B.Sum3 + TwoTankS11_Owen_v6_P.Valvebiasopening_Value;

  /* RateTransition: '<Root>/Store data every second' incorporates:
   *  Constant: '<Root>/Desired height of bottom tank'
   */
  if (rtmIsMajorTimeStep(TwoTankS11_Owen_v6_M)) {
    if (TwoTankS11_Owen_v6_M->Timing.RateInteraction.TID1_2) {
      TwoTankS11_Owen_v6_B.Storedataeverysecond[0] = TwoTankS11_Owen_v6_B.Clock;
      TwoTankS11_Owen_v6_B.Storedataeverysecond[1] = TwoTankS11_Owen_v6_B.Sum4;
      TwoTankS11_Owen_v6_B.Storedataeverysecond[2] = TwoTankS11_Owen_v6_B.Sum8;
      TwoTankS11_Owen_v6_B.Storedataeverysecond[3] =
        TwoTankS11_Owen_v6_P.Desiredheightofbottomtank_Value;
      TwoTankS11_Owen_v6_B.Storedataeverysecond[4] =
        TwoTankS11_Owen_v6_B.Voltagefromtopsensor;
      TwoTankS11_Owen_v6_B.Storedataeverysecond[5] =
        TwoTankS11_Owen_v6_B.Voltagefrombottomsensor;
      TwoTankS11_Owen_v6_B.Storedataeverysecond[6] = TwoTankS11_Owen_v6_B.Sum3;
      TwoTankS11_Owen_v6_B.Storedataeverysecond[7] = TwoTankS11_Owen_v6_B.Sum7;
    }

    /* S-Function (sldrtao): '<Root>/Voltage out to valve' */
    /* S-Function Block: <Root>/Voltage out to valve */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) TwoTankS11_Owen_v6_P.Voltageouttovalve_RangeMode;
        parm.rangeidx = TwoTankS11_Owen_v6_P.Voltageouttovalve_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &TwoTankS11_Owen_v6_P.Voltageouttovalve_Channels,
                       ((real_T*) (&TwoTankS11_Owen_v6_B.Sum3)), &parm);
      }
    }
  }

  /* End of RateTransition: '<Root>/Store data every second' */
}

/* Model update function for TID0 */
void TwoTankS11_Owen_v6_update0(void)  /* Sample time: [0.0s, 0.0s] */
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative' */
  if (TwoTankS11_Owen_v6_DW.TimeStampA == (rtInf)) {
    TwoTankS11_Owen_v6_DW.TimeStampA = TwoTankS11_Owen_v6_M->Timing.t[0];
    lastU = &TwoTankS11_Owen_v6_DW.LastUAtTimeA;
  } else if (TwoTankS11_Owen_v6_DW.TimeStampB == (rtInf)) {
    TwoTankS11_Owen_v6_DW.TimeStampB = TwoTankS11_Owen_v6_M->Timing.t[0];
    lastU = &TwoTankS11_Owen_v6_DW.LastUAtTimeB;
  } else if (TwoTankS11_Owen_v6_DW.TimeStampA < TwoTankS11_Owen_v6_DW.TimeStampB)
  {
    TwoTankS11_Owen_v6_DW.TimeStampA = TwoTankS11_Owen_v6_M->Timing.t[0];
    lastU = &TwoTankS11_Owen_v6_DW.LastUAtTimeA;
  } else {
    TwoTankS11_Owen_v6_DW.TimeStampB = TwoTankS11_Owen_v6_M->Timing.t[0];
    lastU = &TwoTankS11_Owen_v6_DW.LastUAtTimeB;
  }

  *lastU = TwoTankS11_Owen_v6_B.Sum1;

  /* End of Update for Derivative: '<Root>/Derivative' */
  if (rtmIsMajorTimeStep(TwoTankS11_Owen_v6_M)) {
    rt_ertODEUpdateContinuousStates(&TwoTankS11_Owen_v6_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TwoTankS11_Owen_v6_M->Timing.clockTick0)) {
    ++TwoTankS11_Owen_v6_M->Timing.clockTickH0;
  }

  TwoTankS11_Owen_v6_M->Timing.t[0] = rtsiGetSolverStopTime
    (&TwoTankS11_Owen_v6_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TwoTankS11_Owen_v6_M->Timing.clockTick1)) {
    ++TwoTankS11_Owen_v6_M->Timing.clockTickH1;
  }

  TwoTankS11_Owen_v6_M->Timing.t[1] = TwoTankS11_Owen_v6_M->Timing.clockTick1 *
    TwoTankS11_Owen_v6_M->Timing.stepSize1 +
    TwoTankS11_Owen_v6_M->Timing.clockTickH1 *
    TwoTankS11_Owen_v6_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void TwoTankS11_Owen_v6_derivatives(void)
{
  XDot_TwoTankS11_Owen_v6_T *_rtXdot;
  _rtXdot = ((XDot_TwoTankS11_Owen_v6_T *) TwoTankS11_Owen_v6_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = TwoTankS11_Owen_v6_B.Sum1;
}

/* Model output function for TID2 */
void TwoTankS11_Owen_v6_output2(void)  /* Sample time: [1.0s, 0.0s] */
{
  /* (no output code required) */
}

/* Model update function for TID2 */
void TwoTankS11_Owen_v6_update2(void)  /* Sample time: [1.0s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TwoTankS11_Owen_v6_M->Timing.clockTick2)) {
    ++TwoTankS11_Owen_v6_M->Timing.clockTickH2;
  }

  TwoTankS11_Owen_v6_M->Timing.t[2] = TwoTankS11_Owen_v6_M->Timing.clockTick2 *
    TwoTankS11_Owen_v6_M->Timing.stepSize2 +
    TwoTankS11_Owen_v6_M->Timing.clockTickH2 *
    TwoTankS11_Owen_v6_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void TwoTankS11_Owen_v6_output(int_T tid)
{
  switch (tid) {
   case 0 :
    TwoTankS11_Owen_v6_output0();
    break;

   case 2 :
    TwoTankS11_Owen_v6_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void TwoTankS11_Owen_v6_update(int_T tid)
{
  switch (tid) {
   case 0 :
    TwoTankS11_Owen_v6_update0();
    break;

   case 2 :
    TwoTankS11_Owen_v6_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void TwoTankS11_Owen_v6_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Voltage out to valve' */

  /* S-Function Block: <Root>/Voltage out to valve */

  /* no initial value should be set */

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  TwoTankS11_Owen_v6_X.Integrator_CSTATE = TwoTankS11_Owen_v6_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  TwoTankS11_Owen_v6_DW.TimeStampA = (rtInf);
  TwoTankS11_Owen_v6_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void TwoTankS11_Owen_v6_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Voltage out to valve' */

  /* S-Function Block: <Root>/Voltage out to valve */

  /* no final value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  TwoTankS11_Owen_v6_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  TwoTankS11_Owen_v6_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  TwoTankS11_Owen_v6_initialize();
}

void MdlTerminate(void)
{
  TwoTankS11_Owen_v6_terminate();
}

/* Registration function */
RT_MODEL_TwoTankS11_Owen_v6_T *TwoTankS11_Owen_v6(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)TwoTankS11_Owen_v6_M, 0,
                sizeof(RT_MODEL_TwoTankS11_Owen_v6_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TwoTankS11_Owen_v6_M->solverInfo,
                          &TwoTankS11_Owen_v6_M->Timing.simTimeStep);
    rtsiSetTPtr(&TwoTankS11_Owen_v6_M->solverInfo, &rtmGetTPtr
                (TwoTankS11_Owen_v6_M));
    rtsiSetStepSizePtr(&TwoTankS11_Owen_v6_M->solverInfo,
                       &TwoTankS11_Owen_v6_M->Timing.stepSize0);
    rtsiSetdXPtr(&TwoTankS11_Owen_v6_M->solverInfo,
                 &TwoTankS11_Owen_v6_M->derivs);
    rtsiSetContStatesPtr(&TwoTankS11_Owen_v6_M->solverInfo, (real_T **)
                         &TwoTankS11_Owen_v6_M->contStates);
    rtsiSetNumContStatesPtr(&TwoTankS11_Owen_v6_M->solverInfo,
      &TwoTankS11_Owen_v6_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TwoTankS11_Owen_v6_M->solverInfo,
      &TwoTankS11_Owen_v6_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&TwoTankS11_Owen_v6_M->solverInfo,
      &TwoTankS11_Owen_v6_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&TwoTankS11_Owen_v6_M->solverInfo,
      &TwoTankS11_Owen_v6_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&TwoTankS11_Owen_v6_M->solverInfo, (&rtmGetErrorStatus
      (TwoTankS11_Owen_v6_M)));
    rtsiSetRTModelPtr(&TwoTankS11_Owen_v6_M->solverInfo, TwoTankS11_Owen_v6_M);
  }

  rtsiSetSimTimeStep(&TwoTankS11_Owen_v6_M->solverInfo, MAJOR_TIME_STEP);
  TwoTankS11_Owen_v6_M->intgData.y = TwoTankS11_Owen_v6_M->odeY;
  TwoTankS11_Owen_v6_M->intgData.f[0] = TwoTankS11_Owen_v6_M->odeF[0];
  TwoTankS11_Owen_v6_M->intgData.f[1] = TwoTankS11_Owen_v6_M->odeF[1];
  TwoTankS11_Owen_v6_M->intgData.f[2] = TwoTankS11_Owen_v6_M->odeF[2];
  TwoTankS11_Owen_v6_M->contStates = ((real_T *) &TwoTankS11_Owen_v6_X);
  rtsiSetSolverData(&TwoTankS11_Owen_v6_M->solverInfo, (void *)
                    &TwoTankS11_Owen_v6_M->intgData);
  rtsiSetSolverName(&TwoTankS11_Owen_v6_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = TwoTankS11_Owen_v6_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    TwoTankS11_Owen_v6_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    TwoTankS11_Owen_v6_M->Timing.sampleTimes =
      (&TwoTankS11_Owen_v6_M->Timing.sampleTimesArray[0]);
    TwoTankS11_Owen_v6_M->Timing.offsetTimes =
      (&TwoTankS11_Owen_v6_M->Timing.offsetTimesArray[0]);

    /* task periods */
    TwoTankS11_Owen_v6_M->Timing.sampleTimes[0] = (0.0);
    TwoTankS11_Owen_v6_M->Timing.sampleTimes[1] = (0.1);
    TwoTankS11_Owen_v6_M->Timing.sampleTimes[2] = (1.0);

    /* task offsets */
    TwoTankS11_Owen_v6_M->Timing.offsetTimes[0] = (0.0);
    TwoTankS11_Owen_v6_M->Timing.offsetTimes[1] = (0.0);
    TwoTankS11_Owen_v6_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(TwoTankS11_Owen_v6_M, &TwoTankS11_Owen_v6_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = TwoTankS11_Owen_v6_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      TwoTankS11_Owen_v6_M->Timing.perTaskSampleHitsArray;
    TwoTankS11_Owen_v6_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    TwoTankS11_Owen_v6_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(TwoTankS11_Owen_v6_M, 999.0);
  TwoTankS11_Owen_v6_M->Timing.stepSize0 = 0.1;
  TwoTankS11_Owen_v6_M->Timing.stepSize1 = 0.1;
  TwoTankS11_Owen_v6_M->Timing.stepSize2 = 1.0;

  /* External mode info */
  TwoTankS11_Owen_v6_M->Sizes.checksums[0] = (3002054108U);
  TwoTankS11_Owen_v6_M->Sizes.checksums[1] = (3417541179U);
  TwoTankS11_Owen_v6_M->Sizes.checksums[2] = (1586690770U);
  TwoTankS11_Owen_v6_M->Sizes.checksums[3] = (964100368U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    TwoTankS11_Owen_v6_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TwoTankS11_Owen_v6_M->extModeInfo,
      &TwoTankS11_Owen_v6_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TwoTankS11_Owen_v6_M->extModeInfo,
                        TwoTankS11_Owen_v6_M->Sizes.checksums);
    rteiSetTPtr(TwoTankS11_Owen_v6_M->extModeInfo, rtmGetTPtr
                (TwoTankS11_Owen_v6_M));
  }

  TwoTankS11_Owen_v6_M->solverInfoPtr = (&TwoTankS11_Owen_v6_M->solverInfo);
  TwoTankS11_Owen_v6_M->Timing.stepSize = (0.1);
  rtsiSetFixedStepSize(&TwoTankS11_Owen_v6_M->solverInfo, 0.1);
  rtsiSetSolverMode(&TwoTankS11_Owen_v6_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  TwoTankS11_Owen_v6_M->blockIO = ((void *) &TwoTankS11_Owen_v6_B);
  (void) memset(((void *) &TwoTankS11_Owen_v6_B), 0,
                sizeof(B_TwoTankS11_Owen_v6_T));

  /* parameters */
  TwoTankS11_Owen_v6_M->defaultParam = ((real_T *)&TwoTankS11_Owen_v6_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &TwoTankS11_Owen_v6_X;
    TwoTankS11_Owen_v6_M->contStates = (x);
    (void) memset((void *)&TwoTankS11_Owen_v6_X, 0,
                  sizeof(X_TwoTankS11_Owen_v6_T));
  }

  /* states (dwork) */
  TwoTankS11_Owen_v6_M->dwork = ((void *) &TwoTankS11_Owen_v6_DW);
  (void) memset((void *)&TwoTankS11_Owen_v6_DW, 0,
                sizeof(DW_TwoTankS11_Owen_v6_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    TwoTankS11_Owen_v6_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  TwoTankS11_Owen_v6_M->Sizes.numContStates = (1);/* Number of continuous states */
  TwoTankS11_Owen_v6_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  TwoTankS11_Owen_v6_M->Sizes.numY = (0);/* Number of model outputs */
  TwoTankS11_Owen_v6_M->Sizes.numU = (0);/* Number of model inputs */
  TwoTankS11_Owen_v6_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  TwoTankS11_Owen_v6_M->Sizes.numSampTimes = (3);/* Number of sample times */
  TwoTankS11_Owen_v6_M->Sizes.numBlocks = (38);/* Number of blocks */
  TwoTankS11_Owen_v6_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  TwoTankS11_Owen_v6_M->Sizes.numBlockPrms = (29);/* Sum of parameter "widths" */
  return TwoTankS11_Owen_v6_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
