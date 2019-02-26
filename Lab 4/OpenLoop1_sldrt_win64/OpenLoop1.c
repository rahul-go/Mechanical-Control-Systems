/*
 * OpenLoop1.c
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
#include "OpenLoop1_dt.h"

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
B_OpenLoop1_T OpenLoop1_B;

/* Block states (default storage) */
DW_OpenLoop1_T OpenLoop1_DW;

/* Real-time model */
RT_MODEL_OpenLoop1_T OpenLoop1_M_;
RT_MODEL_OpenLoop1_T *const OpenLoop1_M = &OpenLoop1_M_;

/* Model output function */
void OpenLoop1_output(void)
{
  /* Saturate: '<Root>/-10<V<10' incorporates:
   *  Constant: '<Root>/Voltage out to servo valve'
   */
  if (OpenLoop1_P.Voltageouttoservovalve_Value > OpenLoop1_P.u0V10_UpperSat) {
    OpenLoop1_B.u0V10 = OpenLoop1_P.u0V10_UpperSat;
  } else if (OpenLoop1_P.Voltageouttoservovalve_Value <
             OpenLoop1_P.u0V10_LowerSat) {
    OpenLoop1_B.u0V10 = OpenLoop1_P.u0V10_LowerSat;
  } else {
    OpenLoop1_B.u0V10 = OpenLoop1_P.Voltageouttoservovalve_Value;
  }

  /* End of Saturate: '<Root>/-10<V<10' */

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) OpenLoop1_P.AnalogOutput_RangeMode;
      parm.rangeidx = OpenLoop1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &OpenLoop1_P.AnalogOutput_Channels, ((real_T*)
        (&OpenLoop1_B.u0V10)), &parm);
    }
  }

  /* S-Function (sldrtai): '<Root>/Voltage in from potentiometer' */
  /* S-Function Block: <Root>/Voltage in from potentiometer */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) OpenLoop1_P.Voltageinfrompotentiometer_RangeMode;
    parm.rangeidx = OpenLoop1_P.Voltageinfrompotentiometer_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &OpenLoop1_P.Voltageinfrompotentiometer_Channels,
                   &OpenLoop1_B.Voltageinfrompotentiometer, &parm);
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Offset'
   *  Gain: '<Root>/Gain'
   */
  OpenLoop1_B.Sum = OpenLoop1_P.Gain_Gain *
    OpenLoop1_B.Voltageinfrompotentiometer + OpenLoop1_P.Offset_Value;
}

/* Model update function */
void OpenLoop1_update(void)
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
  if (!(++OpenLoop1_M->Timing.clockTick0)) {
    ++OpenLoop1_M->Timing.clockTickH0;
  }

  OpenLoop1_M->Timing.t[0] = OpenLoop1_M->Timing.clockTick0 *
    OpenLoop1_M->Timing.stepSize0 + OpenLoop1_M->Timing.clockTickH0 *
    OpenLoop1_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void OpenLoop1_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) OpenLoop1_P.AnalogOutput_RangeMode;
      parm.rangeidx = OpenLoop1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &OpenLoop1_P.AnalogOutput_Channels,
                     &OpenLoop1_P.AnalogOutput_InitialValue, &parm);
    }
  }
}

/* Model terminate function */
void OpenLoop1_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) OpenLoop1_P.AnalogOutput_RangeMode;
      parm.rangeidx = OpenLoop1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &OpenLoop1_P.AnalogOutput_Channels,
                     &OpenLoop1_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  OpenLoop1_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  OpenLoop1_update();
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
  OpenLoop1_initialize();
}

void MdlTerminate(void)
{
  OpenLoop1_terminate();
}

/* Registration function */
RT_MODEL_OpenLoop1_T *OpenLoop1(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)OpenLoop1_M, 0,
                sizeof(RT_MODEL_OpenLoop1_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = OpenLoop1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    OpenLoop1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    OpenLoop1_M->Timing.sampleTimes = (&OpenLoop1_M->Timing.sampleTimesArray[0]);
    OpenLoop1_M->Timing.offsetTimes = (&OpenLoop1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    OpenLoop1_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    OpenLoop1_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(OpenLoop1_M, &OpenLoop1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = OpenLoop1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    OpenLoop1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(OpenLoop1_M, 300.0);
  OpenLoop1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  OpenLoop1_M->Sizes.checksums[0] = (3147267025U);
  OpenLoop1_M->Sizes.checksums[1] = (2607824914U);
  OpenLoop1_M->Sizes.checksums[2] = (1993109496U);
  OpenLoop1_M->Sizes.checksums[3] = (3768450901U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    OpenLoop1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(OpenLoop1_M->extModeInfo,
      &OpenLoop1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(OpenLoop1_M->extModeInfo, OpenLoop1_M->Sizes.checksums);
    rteiSetTPtr(OpenLoop1_M->extModeInfo, rtmGetTPtr(OpenLoop1_M));
  }

  OpenLoop1_M->solverInfoPtr = (&OpenLoop1_M->solverInfo);
  OpenLoop1_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&OpenLoop1_M->solverInfo, 0.01);
  rtsiSetSolverMode(&OpenLoop1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  OpenLoop1_M->blockIO = ((void *) &OpenLoop1_B);

  {
    OpenLoop1_B.u0V10 = 0.0;
    OpenLoop1_B.Voltageinfrompotentiometer = 0.0;
    OpenLoop1_B.Sum = 0.0;
  }

  /* parameters */
  OpenLoop1_M->defaultParam = ((real_T *)&OpenLoop1_P);

  /* states (dwork) */
  OpenLoop1_M->dwork = ((void *) &OpenLoop1_DW);
  (void) memset((void *)&OpenLoop1_DW, 0,
                sizeof(DW_OpenLoop1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    OpenLoop1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  OpenLoop1_M->Sizes.numContStates = (0);/* Number of continuous states */
  OpenLoop1_M->Sizes.numY = (0);       /* Number of model outputs */
  OpenLoop1_M->Sizes.numU = (0);       /* Number of model inputs */
  OpenLoop1_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  OpenLoop1_M->Sizes.numSampTimes = (1);/* Number of sample times */
  OpenLoop1_M->Sizes.numBlocks = (12); /* Number of blocks */
  OpenLoop1_M->Sizes.numBlockIO = (3); /* Number of block outputs */
  OpenLoop1_M->Sizes.numBlockPrms = (17);/* Sum of parameter "widths" */
  return OpenLoop1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
