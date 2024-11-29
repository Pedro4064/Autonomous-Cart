#ifndef __Y6EQBRvAKrIpoXDYdkEY8B_h__
#define __Y6EQBRvAKrIpoXDYdkEY8B_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
#define typedef_InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T (*u0)[64];
  real_T (*u1)[8];
  real_T (*b_y0)[16];
  real_T (*b_y1)[16];
  real_T (*fP_priori)[8][8];
  real_T (*fX_hat_priori)[8];
  real_T (*fH_jacobian)[2][8];
  real_T (*fK)[8][2];
} InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B;

#endif                                 /* typedef_InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S, int_T method,
  void* data);

#endif
