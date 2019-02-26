/*
 * PIDPositionerF141.c
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
#include "PIDPositionerF141_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-MIO-16E-4", 4294967295U, 5, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_PIDPositionerF141_T PIDPositionerF141_B;

/* Continuous states */
X_PIDPositionerF141_T PIDPositionerF141_X;

/* Block states (default storage) */
DW_PIDPositionerF141_T PIDPositionerF141_DW;

/* Real-time model */
RT_MODEL_PIDPositionerF141_T PIDPositionerF141_M_;
RT_MODEL_PIDPositionerF141_T *const PIDPositionerF141_M = &PIDPositionerF141_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PIDPositionerF141_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  PIDPositionerF141_output();
  PIDPositionerF141_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  PIDPositionerF141_output();
  PIDPositionerF141_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  PIDPositionerF141_output();
  PIDPositionerF141_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = fabs(u0 / u1);
      if (fabs(u1_0 - floor(u1_0 + 0.5)) <= DBL_EPSILON * u1_0) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void PIDPositionerF141_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput;
  real_T rtb_Sum;
  if (rtmIsMajorTimeStep(PIDPositionerF141_M)) {
    /* set solver stop time */
    if (!(PIDPositionerF141_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PIDPositionerF141_M->solverInfo,
                            ((PIDPositionerF141_M->Timing.clockTickH0 + 1) *
        PIDPositionerF141_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PIDPositionerF141_M->solverInfo,
                            ((PIDPositionerF141_M->Timing.clockTick0 + 1) *
        PIDPositionerF141_M->Timing.stepSize0 +
        PIDPositionerF141_M->Timing.clockTickH0 *
        PIDPositionerF141_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PIDPositionerF141_M)) {
    PIDPositionerF141_M->Timing.t[0] = rtsiGetT(&PIDPositionerF141_M->solverInfo);
  }

  /* SignalConversion: '<S2>/Output' incorporates:
   *  Clock: '<S2>/Clock'
   *  Constant: '<S2>/Constant'
   *  Lookup_n-D: '<S2>/Look-Up Table1'
   *  Math: '<S2>/Math Function'
   *  S-Function (sfun_tstart): '<S2>/startTime'
   *  Sum: '<S2>/Sum'
   */
  PIDPositionerF141_B.Output = look1_binlxpw(rt_remd_snf
    (PIDPositionerF141_M->Timing.t[0] - (0.0),
     PIDPositionerF141_P.Constant_Value),
    PIDPositionerF141_P.LookUpTable1_bp01Data,
    PIDPositionerF141_P.RepeatingSequence_rep_seq_y, 4U);
  if (rtmIsMajorTimeStep(PIDPositionerF141_M)) {
    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) PIDPositionerF141_P.AnalogInput_RangeMode;
      parm.rangeidx = PIDPositionerF141_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &PIDPositionerF141_P.AnalogInput_Channels, &rtb_AnalogInput,
                     &parm);
    }

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Potentiometer Offset (inches)'
     *  Gain: '<Root>/Feedback Sensor Gain (in//V)'
     */
    PIDPositionerF141_B.Sum1 = PIDPositionerF141_P.FeedbackSensorGaininV_Gain *
      rtb_AnalogInput + PIDPositionerF141_P.PotentiometerOffsetinches_Value;
  }

  /* Sum: '<Root>/Sum' */
  rtb_Sum = PIDPositionerF141_B.Output - PIDPositionerF141_B.Sum1;

  /* Gain: '<S1>/Derivative Divisor' incorporates:
   *  Gain: '<S1>/Derivative Gain'
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/Sum1'
   */
  PIDPositionerF141_B.DerivativeDivisor = (PIDPositionerF141_P.PIDController_D *
    rtb_Sum - PIDPositionerF141_X.Filter_CSTATE) *
    PIDPositionerF141_P.PIDController_N;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Proportional Gain'
   *  Integrator: '<S1>/Integrator'
   */
  PIDPositionerF141_B.Sum = (PIDPositionerF141_P.PIDController_P * rtb_Sum +
    PIDPositionerF141_X.Integrator_CSTATE) +
    PIDPositionerF141_B.DerivativeDivisor;
  if (rtmIsMajorTimeStep(PIDPositionerF141_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) PIDPositionerF141_P.AnalogOutput_RangeMode;
        parm.rangeidx = PIDPositionerF141_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &PIDPositionerF141_P.AnalogOutput_Channels, ((real_T*)
          (&PIDPositionerF141_B.Sum)), &parm);
      }
    }
  }

  /* Gain: '<S1>/Integral Gain' */
  PIDPositionerF141_B.IntegralGain = PIDPositionerF141_P.PIDController_I *
    rtb_Sum;
}

/* Model update function */
void PIDPositionerF141_update(void)
{
  if (rtmIsMajorTimeStep(PIDPositionerF141_M)) {
    rt_ertODEUpdateContinuousStates(&PIDPositionerF141_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PIDPositionerF141_M->Timing.clockTick0)) {
    ++PIDPositionerF141_M->Timing.clockTickH0;
  }

  PIDPositionerF141_M->Timing.t[0] = rtsiGetSolverStopTime
    (&PIDPositionerF141_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++PIDPositionerF141_M->Timing.clockTick1)) {
      ++PIDPositionerF141_M->Timing.clockTickH1;
    }

    PIDPositionerF141_M->Timing.t[1] = PIDPositionerF141_M->Timing.clockTick1 *
      PIDPositionerF141_M->Timing.stepSize1 +
      PIDPositionerF141_M->Timing.clockTickH1 *
      PIDPositionerF141_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void PIDPositionerF141_derivatives(void)
{
  XDot_PIDPositionerF141_T *_rtXdot;
  _rtXdot = ((XDot_PIDPositionerF141_T *) PIDPositionerF141_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = PIDPositionerF141_B.IntegralGain;

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE = PIDPositionerF141_B.DerivativeDivisor;
}

/* Model initialize function */
void PIDPositionerF141_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) PIDPositionerF141_P.AnalogOutput_RangeMode;
      parm.rangeidx = PIDPositionerF141_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &PIDPositionerF141_P.AnalogOutput_Channels,
                     &PIDPositionerF141_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  PIDPositionerF141_X.Integrator_CSTATE = PIDPositionerF141_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  PIDPositionerF141_X.Filter_CSTATE = PIDPositionerF141_P.Filter_IC;
}

/* Model terminate function */
void PIDPositionerF141_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) PIDPositionerF141_P.AnalogOutput_RangeMode;
      parm.rangeidx = PIDPositionerF141_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &PIDPositionerF141_P.AnalogOutput_Channels,
                     &PIDPositionerF141_P.AnalogOutput_FinalValue, &parm);
    }
  }
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
  PIDPositionerF141_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  PIDPositionerF141_update();
  UNUSED_PARAMETER(tid);
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
  PIDPositionerF141_initialize();
}

void MdlTerminate(void)
{
  PIDPositionerF141_terminate();
}

/* Registration function */
RT_MODEL_PIDPositionerF141_T *PIDPositionerF141(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PIDPositionerF141_M, 0,
                sizeof(RT_MODEL_PIDPositionerF141_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PIDPositionerF141_M->solverInfo,
                          &PIDPositionerF141_M->Timing.simTimeStep);
    rtsiSetTPtr(&PIDPositionerF141_M->solverInfo, &rtmGetTPtr
                (PIDPositionerF141_M));
    rtsiSetStepSizePtr(&PIDPositionerF141_M->solverInfo,
                       &PIDPositionerF141_M->Timing.stepSize0);
    rtsiSetdXPtr(&PIDPositionerF141_M->solverInfo, &PIDPositionerF141_M->derivs);
    rtsiSetContStatesPtr(&PIDPositionerF141_M->solverInfo, (real_T **)
                         &PIDPositionerF141_M->contStates);
    rtsiSetNumContStatesPtr(&PIDPositionerF141_M->solverInfo,
      &PIDPositionerF141_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PIDPositionerF141_M->solverInfo,
      &PIDPositionerF141_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PIDPositionerF141_M->solverInfo,
      &PIDPositionerF141_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PIDPositionerF141_M->solverInfo,
      &PIDPositionerF141_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PIDPositionerF141_M->solverInfo, (&rtmGetErrorStatus
      (PIDPositionerF141_M)));
    rtsiSetRTModelPtr(&PIDPositionerF141_M->solverInfo, PIDPositionerF141_M);
  }

  rtsiSetSimTimeStep(&PIDPositionerF141_M->solverInfo, MAJOR_TIME_STEP);
  PIDPositionerF141_M->intgData.y = PIDPositionerF141_M->odeY;
  PIDPositionerF141_M->intgData.f[0] = PIDPositionerF141_M->odeF[0];
  PIDPositionerF141_M->intgData.f[1] = PIDPositionerF141_M->odeF[1];
  PIDPositionerF141_M->intgData.f[2] = PIDPositionerF141_M->odeF[2];
  PIDPositionerF141_M->intgData.f[3] = PIDPositionerF141_M->odeF[3];
  PIDPositionerF141_M->contStates = ((real_T *) &PIDPositionerF141_X);
  rtsiSetSolverData(&PIDPositionerF141_M->solverInfo, (void *)
                    &PIDPositionerF141_M->intgData);
  rtsiSetSolverName(&PIDPositionerF141_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PIDPositionerF141_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    PIDPositionerF141_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PIDPositionerF141_M->Timing.sampleTimes =
      (&PIDPositionerF141_M->Timing.sampleTimesArray[0]);
    PIDPositionerF141_M->Timing.offsetTimes =
      (&PIDPositionerF141_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PIDPositionerF141_M->Timing.sampleTimes[0] = (0.0);
    PIDPositionerF141_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    PIDPositionerF141_M->Timing.offsetTimes[0] = (0.0);
    PIDPositionerF141_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(PIDPositionerF141_M, &PIDPositionerF141_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PIDPositionerF141_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    PIDPositionerF141_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PIDPositionerF141_M, 3.0);
  PIDPositionerF141_M->Timing.stepSize0 = 0.001;
  PIDPositionerF141_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  PIDPositionerF141_M->Sizes.checksums[0] = (2446853958U);
  PIDPositionerF141_M->Sizes.checksums[1] = (1018056209U);
  PIDPositionerF141_M->Sizes.checksums[2] = (1009614229U);
  PIDPositionerF141_M->Sizes.checksums[3] = (826859772U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    PIDPositionerF141_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PIDPositionerF141_M->extModeInfo,
      &PIDPositionerF141_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PIDPositionerF141_M->extModeInfo,
                        PIDPositionerF141_M->Sizes.checksums);
    rteiSetTPtr(PIDPositionerF141_M->extModeInfo, rtmGetTPtr(PIDPositionerF141_M));
  }

  PIDPositionerF141_M->solverInfoPtr = (&PIDPositionerF141_M->solverInfo);
  PIDPositionerF141_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&PIDPositionerF141_M->solverInfo, 0.001);
  rtsiSetSolverMode(&PIDPositionerF141_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  PIDPositionerF141_M->blockIO = ((void *) &PIDPositionerF141_B);

  {
    PIDPositionerF141_B.Output = 0.0;
    PIDPositionerF141_B.Sum1 = 0.0;
    PIDPositionerF141_B.DerivativeDivisor = 0.0;
    PIDPositionerF141_B.Sum = 0.0;
    PIDPositionerF141_B.IntegralGain = 0.0;
  }

  /* parameters */
  PIDPositionerF141_M->defaultParam = ((real_T *)&PIDPositionerF141_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PIDPositionerF141_X;
    PIDPositionerF141_M->contStates = (x);
    (void) memset((void *)&PIDPositionerF141_X, 0,
                  sizeof(X_PIDPositionerF141_T));
  }

  /* states (dwork) */
  PIDPositionerF141_M->dwork = ((void *) &PIDPositionerF141_DW);
  (void) memset((void *)&PIDPositionerF141_DW, 0,
                sizeof(DW_PIDPositionerF141_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PIDPositionerF141_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  PIDPositionerF141_M->Sizes.numContStates = (2);/* Number of continuous states */
  PIDPositionerF141_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  PIDPositionerF141_M->Sizes.numY = (0);/* Number of model outputs */
  PIDPositionerF141_M->Sizes.numU = (0);/* Number of model inputs */
  PIDPositionerF141_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PIDPositionerF141_M->Sizes.numSampTimes = (2);/* Number of sample times */
  PIDPositionerF141_M->Sizes.numBlocks = (22);/* Number of blocks */
  PIDPositionerF141_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  PIDPositionerF141_M->Sizes.numBlockPrms = (31);/* Sum of parameter "widths" */
  return PIDPositionerF141_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
