/*
 * DCServoDAC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DCServoDAC".
 *
 * Model version              : 1.45
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Mon Feb  4 16:02:48 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DCServoDAC.h"
#include "DCServoDAC_private.h"
#include "DCServoDAC_dt.h"

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
  0.01, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-MIO-16E-4", 4294967295U, 5, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_DCServoDAC_T DCServoDAC_B;

/* Block states (default storage) */
DW_DCServoDAC_T DCServoDAC_DW;

/* Real-time model */
RT_MODEL_DCServoDAC_T DCServoDAC_M_;
RT_MODEL_DCServoDAC_T *const DCServoDAC_M = &DCServoDAC_M_;

/* Model output function */
void DCServoDAC_output(void)
{
  /* S-Function (sldrtai): '<Root>/Measured generator voltage' */
  /* S-Function Block: <Root>/Measured generator voltage */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) DCServoDAC_P.Measuredgeneratorvoltage_RangeMode;
    parm.rangeidx = DCServoDAC_P.Measuredgeneratorvoltage_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &DCServoDAC_P.Measuredgeneratorvoltage_Channels,
                   &DCServoDAC_B.Measuredgeneratorvoltage, &parm);
  }

  /* Clock: '<Root>/Clock' */
  DCServoDAC_B.Clock = DCServoDAC_M->Timing.t[0];

  /* SignalConversion: '<Root>/TmpSignal ConversionAtTo WorkspaceInport1' */
  DCServoDAC_B.TmpSignalConversionAtToWorkspaceInport1[0] = DCServoDAC_B.Clock;
  DCServoDAC_B.TmpSignalConversionAtToWorkspaceInport1[1] =
    DCServoDAC_B.Measuredgeneratorvoltage;
}

/* Model update function */
void DCServoDAC_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++DCServoDAC_M->Timing.clockTick0)) {
    ++DCServoDAC_M->Timing.clockTickH0;
  }

  DCServoDAC_M->Timing.t[0] = DCServoDAC_M->Timing.clockTick0 *
    DCServoDAC_M->Timing.stepSize0 + DCServoDAC_M->Timing.clockTickH0 *
    DCServoDAC_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DCServoDAC_M->Timing.clockTick1)) {
      ++DCServoDAC_M->Timing.clockTickH1;
    }

    DCServoDAC_M->Timing.t[1] = DCServoDAC_M->Timing.clockTick1 *
      DCServoDAC_M->Timing.stepSize1 + DCServoDAC_M->Timing.clockTickH1 *
      DCServoDAC_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void DCServoDAC_initialize(void)
{
}

/* Model terminate function */
void DCServoDAC_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  DCServoDAC_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  DCServoDAC_update();
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
  DCServoDAC_initialize();
}

void MdlTerminate(void)
{
  DCServoDAC_terminate();
}

/* Registration function */
RT_MODEL_DCServoDAC_T *DCServoDAC(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DCServoDAC_M, 0,
                sizeof(RT_MODEL_DCServoDAC_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DCServoDAC_M->solverInfo,
                          &DCServoDAC_M->Timing.simTimeStep);
    rtsiSetTPtr(&DCServoDAC_M->solverInfo, &rtmGetTPtr(DCServoDAC_M));
    rtsiSetStepSizePtr(&DCServoDAC_M->solverInfo,
                       &DCServoDAC_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&DCServoDAC_M->solverInfo, (&rtmGetErrorStatus
      (DCServoDAC_M)));
    rtsiSetRTModelPtr(&DCServoDAC_M->solverInfo, DCServoDAC_M);
  }

  rtsiSetSimTimeStep(&DCServoDAC_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&DCServoDAC_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = DCServoDAC_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    DCServoDAC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    DCServoDAC_M->Timing.sampleTimes = (&DCServoDAC_M->Timing.sampleTimesArray[0]);
    DCServoDAC_M->Timing.offsetTimes = (&DCServoDAC_M->Timing.offsetTimesArray[0]);

    /* task periods */
    DCServoDAC_M->Timing.sampleTimes[0] = (0.0);
    DCServoDAC_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    DCServoDAC_M->Timing.offsetTimes[0] = (0.0);
    DCServoDAC_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(DCServoDAC_M, &DCServoDAC_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = DCServoDAC_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    DCServoDAC_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(DCServoDAC_M, 5.0);
  DCServoDAC_M->Timing.stepSize0 = 0.01;
  DCServoDAC_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  DCServoDAC_M->Sizes.checksums[0] = (956189422U);
  DCServoDAC_M->Sizes.checksums[1] = (2936755516U);
  DCServoDAC_M->Sizes.checksums[2] = (1337907106U);
  DCServoDAC_M->Sizes.checksums[3] = (2526222174U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    DCServoDAC_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DCServoDAC_M->extModeInfo,
      &DCServoDAC_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DCServoDAC_M->extModeInfo, DCServoDAC_M->Sizes.checksums);
    rteiSetTPtr(DCServoDAC_M->extModeInfo, rtmGetTPtr(DCServoDAC_M));
  }

  DCServoDAC_M->solverInfoPtr = (&DCServoDAC_M->solverInfo);
  DCServoDAC_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&DCServoDAC_M->solverInfo, 0.01);
  rtsiSetSolverMode(&DCServoDAC_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  DCServoDAC_M->blockIO = ((void *) &DCServoDAC_B);

  {
    DCServoDAC_B.Measuredgeneratorvoltage = 0.0;
    DCServoDAC_B.Clock = 0.0;
    DCServoDAC_B.TmpSignalConversionAtToWorkspaceInport1[0] = 0.0;
    DCServoDAC_B.TmpSignalConversionAtToWorkspaceInport1[1] = 0.0;
  }

  /* parameters */
  DCServoDAC_M->defaultParam = ((real_T *)&DCServoDAC_P);

  /* states (dwork) */
  DCServoDAC_M->dwork = ((void *) &DCServoDAC_DW);
  (void) memset((void *)&DCServoDAC_DW, 0,
                sizeof(DW_DCServoDAC_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DCServoDAC_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  DCServoDAC_M->Sizes.numContStates = (0);/* Number of continuous states */
  DCServoDAC_M->Sizes.numY = (0);      /* Number of model outputs */
  DCServoDAC_M->Sizes.numU = (0);      /* Number of model inputs */
  DCServoDAC_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  DCServoDAC_M->Sizes.numSampTimes = (2);/* Number of sample times */
  DCServoDAC_M->Sizes.numBlocks = (6); /* Number of blocks */
  DCServoDAC_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  DCServoDAC_M->Sizes.numBlockPrms = (5);/* Sum of parameter "widths" */
  return DCServoDAC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
