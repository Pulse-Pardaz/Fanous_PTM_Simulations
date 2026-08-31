/*
 * File: truck_cabin_sim.c
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

#include "truck_cabin_sim.h"
#include "rtwtypes.h"
#include <math.h>
#include "math.h"

/* Named constants for Chart: '<Root>/Central_Controller_FSM' */
#define IN_CONTROL                     ((uint8_T)1U)
#define IN_FAULT                       ((uint8_T)2U)
#define IN_INIT                        ((uint8_T)3U)
#define IN_MANUAL                      ((uint8_T)4U)
#define IN_NORMAL                      ((uint8_T)5U)
#define IN_WARNING                     ((uint8_T)6U)

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Continuous states */
X rtX;

/* Disabled State Vector */
XDis rtXDis;

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
static real_T look2_binfca(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
static void Sensor_Preprocessor_1(real_T rtu_T_raw, real_T rtu_RH_raw, real_T
  *rty_T_filtered, real_T *rty_RH_filtered, boolean_T *rty_T_valid,
  DW_Sensor_Preprocessor_1 *localDW);

/* private model entry point functions */
extern void truck_cabin_sim_derivatives(void);

/* Forward declaration for local functions */
static void merge(int32_T idx[5], real_T x[5], int32_T offset, int32_T np,
                  int32_T nq, int32_T iwork[5], real_T xwork[5]);
static void sort(real_T x[5]);

/* Forward declaration for local functions */
static void INIT(const boolean_T *DataValid, const real_T *HSI_2D_Lookup);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
real_T rtNaN = -(real_T)NAN;
real_T rtInf = (real_T)INFINITY;
real_T rtMinusInf = -(real_T)INFINITY;
real32_T rtNaNF = -(real32_T)NAN;
real32_T rtInfF = (real32_T)INFINITY;
real32_T rtMinusInfF = -(real32_T)INFINITY;

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)isinf(value);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)isinf(value);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

static real_T look2_binfca(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Flat'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index only
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }
  } else {
    iLeft = maxIndex[0U];
  }

  bpIndices[0U] = iLeft;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }
  } else {
    iLeft = maxIndex[1U];
  }

  return table[iLeft * stride + bpIndices[0]];
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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  truck_cabin_sim_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  truck_cabin_sim_step();
  truck_cabin_sim_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  truck_cabin_sim_step();
  truck_cabin_sim_derivatives();

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

/* Function for MATLAB Function: '<Root>/Sensor_Preprocessor_1' */
static void merge(int32_T idx[5], real_T x[5], int32_T offset, int32_T np,
                  int32_T nq, int32_T iwork[5], real_T xwork[5])
{
  int32_T q;
  if ((np != 0) && (nq != 0)) {
    int32_T iout;
    int32_T n;
    int32_T qend;
    qend = np + nq;
    for (q = 0; q < qend; q++) {
      iout = offset + q;
      iwork[q] = idx[iout];
      xwork[q] = x[iout];
    }

    n = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[n] <= xwork[q]) {
        idx[iout] = iwork[n];
        x[iout] = xwork[n];
        if (n + 1 < np) {
          n++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < qend) {
          q++;
        } else {
          qend = iout - n;
          for (q = n + 1; q <= np; q++) {
            iout = qend + q;
            idx[iout] = iwork[q - 1];
            x[iout] = xwork[q - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* Function for MATLAB Function: '<Root>/Sensor_Preprocessor_1' */
static void sort(real_T x[5])
{
  real_T xwork[5];
  real_T x4[4];
  real_T tmp;
  real_T tmp_0;
  int32_T idx[5];
  int32_T iwork[5];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T ib;
  int32_T idx_tmp;
  int32_T nNaNs;
  int32_T perm_0;
  int32_T perm_1;
  int8_T idx4[4];
  int8_T perm[4];
  for (i = 0; i < 5; i++) {
    idx[i] = 0;
  }

  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  nNaNs = 0;
  ib = -1;
  for (i = 0; i < 5; i++) {
    if (rtIsNaN(x[i])) {
      idx[4 - nNaNs] = i + 1;
      xwork[4 - nNaNs] = x[i];
      nNaNs++;
    } else {
      ib++;
      idx4[ib] = (int8_T)(i + 1);
      x4[ib] = x[i];
      if (ib + 1 == 4) {
        ib = i - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        tmp = x4[i1 - 1];
        tmp_0 = x4[i3 - 1];
        if (tmp <= tmp_0) {
          if (x4[i2 - 1] <= tmp_0) {
            perm_0 = i1;
            perm_1 = i2;
            i1 = i3;
            i2 = i4;
          } else if (x4[i2 - 1] <= x4[i4 - 1]) {
            perm_0 = i1;
            perm_1 = i3;
            i1 = i2;
            i2 = i4;
          } else {
            perm_0 = i1;
            perm_1 = i3;
            i1 = i4;
          }
        } else if (tmp <= x4[i4 - 1]) {
          if (x4[i2 - 1] <= x4[i4 - 1]) {
            perm_0 = i3;
            perm_1 = i1;
            i1 = i2;
            i2 = i4;
          } else {
            perm_0 = i3;
            perm_1 = i1;
            i1 = i4;
          }
        } else {
          perm_0 = i3;
          perm_1 = i4;
        }

        idx[ib - 3] = idx4[perm_0 - 1];
        idx[ib - 2] = idx4[perm_1 - 1];
        idx[ib - 1] = idx4[i1 - 1];
        idx[ib] = idx4[i2 - 1];
        x[ib - 3] = x4[perm_0 - 1];
        x[ib - 2] = x4[perm_1 - 1];
        x[ib - 1] = x4[i1 - 1];
        x[ib] = x4[i2 - 1];
        ib = -1;
      }
    }
  }

  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (ib + 1) {
     case 1:
      perm[0] = 1;
      break;

     case 2:
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
      break;

     default:
      if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      break;
    }

    i1 = ((ib + 1) / 4) << 2;
    i2 = i1 - 4;
    for (i = 0; i <= i2; i += 4) {
      i3 = (i - nNaNs) - ib;
      i4 = perm[i] - 1;
      idx[i3 + 4] = idx4[i4];
      perm_0 = perm[i + 1] - 1;
      idx[i3 + 5] = idx4[perm_0];
      perm_1 = perm[i + 2] - 1;
      idx[i3 + 6] = idx4[perm_1];
      idx_tmp = perm[i + 3] - 1;
      idx[i3 + 7] = idx4[idx_tmp];
      x[i3 + 4] = x4[i4];
      x[i3 + 5] = x4[perm_0];
      x[i3 + 6] = x4[perm_1];
      x[i3 + 7] = x4[idx_tmp];
    }

    for (i = i1; i <= ib; i++) {
      i3 = perm[i] - 1;
      i4 = ((i - nNaNs) - ib) + 4;
      idx[i4] = idx4[i3];
      x[i4] = x4[i3];
    }
  }

  ib = (nNaNs >> 1) + 5;
  for (i = 0; i <= ib - 6; i++) {
    i2 = (i - nNaNs) + 5;
    i1 = idx[i2];
    idx[i2] = idx[4 - i];
    idx[4 - i] = i1;
    x[i2] = xwork[4 - i];
    x[4 - i] = xwork[i2];
  }

  if (((uint32_T)nNaNs & 1U) != 0U) {
    i = ib - nNaNs;
    x[i] = xwork[i];
  }

  if (5 - nNaNs > 1) {
    for (i = 0; i < 5; i++) {
      iwork[i] = 0;
    }

    if (5 - nNaNs > 4) {
      merge(idx, x, 0, 4, 1 - nNaNs, iwork, xwork);
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<Root>/Sensor_Preprocessor_1'
 *    '<Root>/Sensor_Preprocessor_2'
 */
static void Sensor_Preprocessor_1(real_T rtu_T_raw, real_T rtu_RH_raw, real_T
  *rty_T_filtered, real_T *rty_RH_filtered, boolean_T *rty_T_valid,
  DW_Sensor_Preprocessor_1 *localDW)
{
  real_T b[5];
  real_T AcceptedT;
  int32_T i;
  if (!localDW->T_buffer_not_empty) {
    localDW->T_buffer_not_empty = true;
    for (i = 0; i < 5; i++) {
      localDW->T_buffer[i] = rtu_T_raw;
      localDW->RH_buffer[i] = rtu_RH_raw;
    }

    localDW->PreviousAcceptedT = rtu_T_raw;
  }

  if (fabs(rtu_T_raw - localDW->PreviousAcceptedT) > 3.0) {
    *rty_T_valid = false;
    AcceptedT = localDW->PreviousAcceptedT;
  } else {
    *rty_T_valid = true;
    AcceptedT = rtu_T_raw;
    localDW->PreviousAcceptedT = rtu_T_raw;
  }

  localDW->T_buffer[0] = localDW->T_buffer[1];
  localDW->T_buffer[1] = localDW->T_buffer[2];
  localDW->T_buffer[2] = localDW->T_buffer[3];
  localDW->T_buffer[3] = localDW->T_buffer[4];
  localDW->T_buffer[4] = AcceptedT;
  localDW->RH_buffer[0] = localDW->RH_buffer[1];
  localDW->RH_buffer[1] = localDW->RH_buffer[2];
  localDW->RH_buffer[2] = localDW->RH_buffer[3];
  localDW->RH_buffer[3] = localDW->RH_buffer[4];
  localDW->RH_buffer[4] = rtu_RH_raw;
  for (i = 0; i < 5; i++) {
    b[i] = localDW->T_buffer[i];
  }

  sort(b);
  *rty_T_filtered = b[2];
  for (i = 0; i < 5; i++) {
    b[i] = localDW->RH_buffer[i];
  }

  sort(b);
  *rty_RH_filtered = b[2];
}

/* Function for Chart: '<Root>/Central_Controller_FSM' */
static void INIT(const boolean_T *DataValid, const real_T *HSI_2D_Lookup)
{
  if (!*DataValid) {
    rtDW.is_c5_truck_cabin_sim = IN_FAULT;
    rtDW.Fan_Command = 0.0;
  } else if ((*DataValid) && (*HSI_2D_Lookup == 0.0)) {
    rtDW.is_c5_truck_cabin_sim = IN_NORMAL;
    rtDW.Fan_Command = 0.0;
  } else if ((*DataValid) && (*HSI_2D_Lookup == 1.0)) {
    rtDW.is_c5_truck_cabin_sim = IN_WARNING;
    rtDW.Fan_Command = 1.0;
  } else if ((*DataValid) && (*HSI_2D_Lookup >= 2.0)) {
    rtDW.is_c5_truck_cabin_sim = IN_CONTROL;
    rtDW.Fan_Command = 1.0;
  }
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void truck_cabin_sim_step(void)
{
  real_T rtb_RH_filtered;
  real_T rtb_RH_filtered_c;
  real_T rtb_T_filtered;
  real_T rtb_T_filtered_i;
  real_T sumRH;
  real_T sumT;
  real_T sumW;
  boolean_T rtb_T_valid;
  boolean_T rtb_T_valid_p;
  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  if (rtmIsMajorTimeStep(rtM)) {
    /* MATLAB Function: '<Root>/Sensor_Preprocessor_1' incorporates:
     *  Bias: '<S8>/Bias'
     *  Integrator: '<S1>/RH_initial'
     *  Integrator: '<S1>/T_initial'
     *  RandomNumber: '<S8>/Random Number'
     *  Sum: '<S8>/Sum'
     */
    Sensor_Preprocessor_1((rtX.T_initial_CSTATE + 0.5) + rtDW.NextOutput,
                          rtX.RH_initial_CSTATE, &rtb_T_filtered_i,
                          &rtb_RH_filtered_c, &rtb_T_valid_p,
                          &rtDW.sf_Sensor_Preprocessor_1);

    /* MATLAB Function: '<Root>/Sensor_Preprocessor_2' incorporates:
     *  Bias: '<S9>/Bias'
     *  Integrator: '<S1>/RH_initial'
     *  Integrator: '<S1>/T_initial'
     *  RandomNumber: '<S9>/Random Number'
     *  Sum: '<S9>/Sum'
     */
    Sensor_Preprocessor_1((rtX.T_initial_CSTATE - 0.5) + rtDW.NextOutput_j,
                          rtX.RH_initial_CSTATE, &rtb_T_filtered,
                          &rtb_RH_filtered, &rtb_T_valid,
                          &rtDW.sf_Sensor_Preprocessor_2);

    /* MATLAB Function: '<Root>/Sensor_Fusion' */
    sumT = 0.0;
    sumRH = 0.0;
    sumW = 0.0;
    if (rtb_T_valid_p) {
      sumT = 0.5 * rtb_T_filtered_i;
      sumRH = 0.5 * rtb_RH_filtered_c;
      sumW = 0.5;
    }

    if (rtb_T_valid) {
      sumT += 0.5 * rtb_T_filtered;
      sumRH += 0.5 * rtb_RH_filtered;
      sumW += 0.5;
    }

    if (sumW > 0.0) {
      rtb_T_filtered = sumT / sumW;
      sumRH /= sumW;
      rtb_T_valid = true;
    } else {
      rtb_T_filtered = 0.0;
      sumRH = 0.0;
      rtb_T_valid = false;
    }

    /* End of MATLAB Function: '<Root>/Sensor_Fusion' */

    /* Lookup_n-D: '<Root>/HSI_2D_Lookup' */
    sumRH = look2_binfca(rtb_T_filtered, sumRH, rtConstP.HSI_2D_Lookup_bp01Data,
                         rtConstP.HSI_2D_Lookup_bp02Data,
                         rtConstP.HSI_2D_Lookup_tableData,
                         rtConstP.HSI_2D_Lookup_maxIndex, 20U);

    /* Chart: '<Root>/Central_Controller_FSM' incorporates:
     *  Constant: '<Root>/ManualFanCommand_Test'
     *  Constant: '<S3>/Constant'
     *  RelationalOperator: '<S3>/Compare'
     */
    if (rtDW.is_active_c5_truck_cabin_sim == 0) {
      rtDW.is_active_c5_truck_cabin_sim = 1U;
      rtDW.is_c5_truck_cabin_sim = IN_INIT;
      rtDW.Fan_Command = 0.0;
    } else {
      switch (rtDW.is_c5_truck_cabin_sim) {
       case IN_CONTROL:
        if (sumRH == 0.0) {
          rtDW.is_c5_truck_cabin_sim = IN_NORMAL;
          rtDW.Fan_Command = 0.0;
        } else if (!rtb_T_valid) {
          rtDW.is_c5_truck_cabin_sim = IN_FAULT;
          rtDW.Fan_Command = 0.0;
        } else if (sumRH == 1.0) {
          rtDW.is_c5_truck_cabin_sim = IN_WARNING;
          rtDW.Fan_Command = 1.0;
        }
        break;

       case IN_FAULT:
        if (rtb_T_valid && (sumRH == 0.0)) {
          rtDW.is_c5_truck_cabin_sim = IN_NORMAL;
          rtDW.Fan_Command = 0.0;
        } else if (rtb_T_valid && (sumRH == 1.0)) {
          rtDW.is_c5_truck_cabin_sim = IN_WARNING;
          rtDW.Fan_Command = 1.0;
        } else if (rtb_T_valid && (sumRH >= 2.0)) {
          rtDW.is_c5_truck_cabin_sim = IN_CONTROL;
          rtDW.Fan_Command = 1.0;
        }
        break;

       case IN_INIT:
        INIT(&rtb_T_valid, &sumRH);
        break;

       case IN_MANUAL:
        if (rtb_T_valid && (sumRH == 0.0)) {
          rtDW.is_c5_truck_cabin_sim = IN_NORMAL;
          rtDW.Fan_Command = 0.0;
        } else if (rtb_T_valid && (sumRH == 1.0)) {
          rtDW.is_c5_truck_cabin_sim = IN_WARNING;
          rtDW.Fan_Command = 1.0;
        } else if (rtb_T_valid && (sumRH == 2.0)) {
          rtDW.is_c5_truck_cabin_sim = IN_CONTROL;
          rtDW.Fan_Command = 1.0;
        } else if (!rtb_T_valid) {
          rtDW.is_c5_truck_cabin_sim = IN_FAULT;
          rtDW.Fan_Command = 0.0;
        } else {
          rtDW.Fan_Command = 0.0;
        }
        break;

       case IN_NORMAL:
        if (sumRH >= 2.0) {
          rtDW.is_c5_truck_cabin_sim = IN_CONTROL;
          rtDW.Fan_Command = 1.0;
        } else if (!rtb_T_valid) {
          rtDW.is_c5_truck_cabin_sim = IN_FAULT;
          rtDW.Fan_Command = 0.0;
        } else if (sumRH == 1.0) {
          rtDW.is_c5_truck_cabin_sim = IN_WARNING;
          rtDW.Fan_Command = 1.0;
        }
        break;

       default:
        /* case IN_WARNING: */
        if (!rtb_T_valid) {
          rtDW.is_c5_truck_cabin_sim = IN_FAULT;
          rtDW.Fan_Command = 0.0;
        } else if (sumRH >= 2.0) {
          rtDW.is_c5_truck_cabin_sim = IN_CONTROL;
          rtDW.Fan_Command = 1.0;
        } else if ((sumRH == 0.0) && (rtb_T_filtered <= 20.0)) {
          rtDW.is_c5_truck_cabin_sim = IN_NORMAL;
          rtDW.Fan_Command = 0.0;
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Central_Controller_FSM' */

    /* Product: '<S1>/Fan cooling' incorporates:
     *  Constant: '<S1>/Qcool'
     */
    rtDW.Fancooling = 3000.0 * rtDW.Fan_Command;

    /* Step: '<Root>/T_ambient_test' */
    if (((rtM->Timing.clockTick1) * 1.0) < 60.0) {
      /* Step: '<Root>/T_ambient_test' */
      rtDW.T_ambient_test = 20.0;
    } else {
      /* Step: '<Root>/T_ambient_test' */
      rtDW.T_ambient_test = 35.0;
    }

    /* End of Step: '<Root>/T_ambient_test' */
  }

  /* Gain: '<S1>/Thermal mass' incorporates:
   *  Constant: '<Root>/Q_birds_Test'
   *  Gain: '<S1>/Thermal conduction'
   *  Integrator: '<S1>/T_initial'
   *  Sum: '<S1>/Heat Gain'
   *  Sum: '<S1>/Qnet'
   *  Sum: '<S1>/Temperature differential'
   */
  rtDW.Thermalmass = (((rtDW.T_ambient_test - rtX.T_initial_CSTATE) * 100.0 +
                       500.0) - rtDW.Fancooling) * 2.0E-5;
  if (rtmIsMajorTimeStep(rtM)) {
    if (rtmIsMajorTimeStep(rtM)) {
      /* Update for RandomNumber: '<S8>/Random Number' */
      rtDW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed) * 0.2;

      /* Update for RandomNumber: '<S9>/Random Number' */
      rtDW.NextOutput_j = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_m) * 0.2;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      rtM->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void truck_cabin_sim_derivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  /* Derivatives for Integrator: '<S1>/T_initial' */
  _rtXdot->T_initial_CSTATE = rtDW.Thermalmass;

  /* Derivatives for Integrator: '<S1>/RH_initial' */
  _rtXdot->RH_initial_CSTATE = 0.0;
}

/* Model initialize function */
void truck_cabin_sim_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&rtM->solverInfo, (boolean_T**)
      &rtM->contStateDisabled);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&rtM->solverInfo, false);
  rtsiSetIsContModeFrozen(&rtM->solverInfo, false);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtM->contStateDisabled = ((XDis *) &rtXDis);
  rtM->Timing.tStart = (0.0);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 1.0;

  /* InitializeConditions for Integrator: '<S1>/T_initial' */
  rtX.T_initial_CSTATE = 25.0;

  /* InitializeConditions for RandomNumber: '<S8>/Random Number' */
  rtDW.RandSeed = 1144108930U;
  rtDW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed) * 0.2;

  /* InitializeConditions for Integrator: '<S1>/RH_initial' */
  rtX.RH_initial_CSTATE = 60.0;

  /* InitializeConditions for RandomNumber: '<S9>/Random Number' */
  rtDW.RandSeed_m = 1144108930U;
  rtDW.NextOutput_j = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_m) * 0.2;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
