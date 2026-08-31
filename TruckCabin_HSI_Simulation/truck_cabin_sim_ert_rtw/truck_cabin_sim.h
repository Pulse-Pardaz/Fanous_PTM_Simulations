/*
 * File: truck_cabin_sim.h
 *
 * Code generated for Simulink model 'truck_cabin_sim'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Aug 31 19:39:29 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef truck_cabin_sim_h_
#define truck_cabin_sim_h_
#ifndef truck_cabin_sim_COMMON_INCLUDES_
#define truck_cabin_sim_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* truck_cabin_sim_COMMON_INCLUDES_ */

#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>/Sensor_Preprocessor_1' */
typedef struct {
  real_T T_buffer[5];                  /* '<Root>/Sensor_Preprocessor_1' */
  real_T RH_buffer[5];                 /* '<Root>/Sensor_Preprocessor_1' */
  real_T PreviousAcceptedT;            /* '<Root>/Sensor_Preprocessor_1' */
  boolean_T T_buffer_not_empty;        /* '<Root>/Sensor_Preprocessor_1' */
} DW_Sensor_Preprocessor_1;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_Sensor_Preprocessor_1 sf_Sensor_Preprocessor_2;/* '<Root>/Sensor_Preprocessor_2' */
  DW_Sensor_Preprocessor_1 sf_Sensor_Preprocessor_1;/* '<Root>/Sensor_Preprocessor_1' */
  real_T Fancooling;                   /* '<S1>/Fan cooling' */
  real_T T_ambient_test;               /* '<Root>/T_ambient_test' */
  real_T Thermalmass;                  /* '<S1>/Thermal mass' */
  real_T Fan_Command;                  /* '<Root>/Central_Controller_FSM' */
  real_T NextOutput;                   /* '<S8>/Random Number' */
  real_T NextOutput_j;                 /* '<S9>/Random Number' */
  uint32_T RandSeed;                   /* '<S8>/Random Number' */
  uint32_T RandSeed_m;                 /* '<S9>/Random Number' */
  uint8_T is_active_c5_truck_cabin_sim;/* '<Root>/Central_Controller_FSM' */
  uint8_T is_c5_truck_cabin_sim;       /* '<Root>/Central_Controller_FSM' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T T_initial_CSTATE;             /* '<S1>/T_initial' */
  real_T RH_initial_CSTATE;            /* '<S1>/RH_initial' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T T_initial_CSTATE;             /* '<S1>/T_initial' */
  real_T RH_initial_CSTATE;            /* '<S1>/RH_initial' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T T_initial_CSTATE;          /* '<S1>/T_initial' */
  boolean_T RH_initial_CSTATE;         /* '<S1>/RH_initial' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: HSI_Table
   * Referenced by: '<Root>/HSI_2D_Lookup'
   */
  real_T HSI_2D_Lookup_tableData[200];

  /* Expression: HSI_T_bp
   * Referenced by: '<Root>/HSI_2D_Lookup'
   */
  real_T HSI_2D_Lookup_bp01Data[20];

  /* Expression: HSI_RH_bp
   * Referenced by: '<Root>/HSI_2D_Lookup'
   */
  real_T HSI_2D_Lookup_bp02Data[10];

  /* Computed Parameter: HSI_2D_Lookup_maxIndex
   * Referenced by: '<Root>/HSI_2D_Lookup'
   */
  uint32_T HSI_2D_Lookup_maxIndex[2];
} ConstP;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Disabled states (default storage) */
extern XDis rtXDis;

/* Block signals and states (default storage) */
extern DW rtDW;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void truck_cabin_sim_initialize(void);
extern void truck_cabin_sim_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/DataValid' : Unused code path elimination
 * Block '<Root>/FSM_State' : Unused code path elimination
 * Block '<Root>/Fan_Command' : Unused code path elimination
 * Block '<Root>/HSI_state' : Unused code path elimination
 * Block '<Root>/LowTemp' : Unused code path elimination
 * Block '<S4>/Manual_Temp_Hysteresis' : Unused code path elimination
 * Block '<S4>/Manual_Temp_Hysteresis1' : Unused code path elimination
 * Block '<S4>/Manual_Temp_Setpoint' : Unused code path elimination
 * Block '<S4>/Sum1' : Unused code path elimination
 * Block '<S4>/Sum2' : Unused code path elimination
 * Block '<Root>/RH_cabin' : Unused code path elimination
 * Block '<Root>/T_cabin' : Unused code path elimination
 * Block '<Root>/T_fused' : Unused code path elimination
 * Block '<Root>/T_raw_1' : Unused code path elimination
 * Block '<Root>/T_raw_2' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'truck_cabin_sim'
 * '<S1>'   : 'truck_cabin_sim/Cabin_Thermal_Plant'
 * '<S2>'   : 'truck_cabin_sim/Central_Controller_FSM'
 * '<S3>'   : 'truck_cabin_sim/Compare To Constant1'
 * '<S4>'   : 'truck_cabin_sim/Manual_Temp_Mode'
 * '<S5>'   : 'truck_cabin_sim/Sensor_Fusion'
 * '<S6>'   : 'truck_cabin_sim/Sensor_Preprocessor_1'
 * '<S7>'   : 'truck_cabin_sim/Sensor_Preprocessor_2'
 * '<S8>'   : 'truck_cabin_sim/T_sensor_1'
 * '<S9>'   : 'truck_cabin_sim/T_sensor_2'
 */
#endif                                 /* truck_cabin_sim_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
