#ifndef __zpJmhMACFGKnoTBNONX1eE_h__
#define __zpJmhMACFGKnoTBNONX1eE_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_zpJmhMACFGKnoTBNONX1eE
#define typedef_InstanceStruct_zpJmhMACFGKnoTBNONX1eE

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real32_T *u0;
  real32_T *u1;
  real32_T (*u2)[2];
  real32_T (*u3)[16];
  real32_T (*u4)[8];
  real32_T (*b_y0)[8];
  real32_T (*fK)[8][2];
  real32_T (*fH_nonlinear)[2];
  real32_T (*fX_hat_priori)[8];
  real32_T (*fStateVector)[8];
} InstanceStruct_zpJmhMACFGKnoTBNONX1eE;

#endif                                 /* typedef_InstanceStruct_zpJmhMACFGKnoTBNONX1eE */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_zpJmhMACFGKnoTBNONX1eE(SimStruct *S, int_T method,
  void* data);

#endif
