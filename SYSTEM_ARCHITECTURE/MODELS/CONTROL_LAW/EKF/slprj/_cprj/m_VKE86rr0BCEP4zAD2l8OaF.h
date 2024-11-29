#ifndef __VKE86rr0BCEP4zAD2l8OaF_h__
#define __VKE86rr0BCEP4zAD2l8OaF_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
#define typedef_InstanceStruct_VKE86rr0BCEP4zAD2l8OaF

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  real_T *u1;
  real_T (*u2)[8];
  real_T (*b_y0)[64];
  real_T (*fF_jacobian)[8][8];
  real_T (*fStateVector)[8];
} InstanceStruct_VKE86rr0BCEP4zAD2l8OaF;

#endif                                 /* typedef_InstanceStruct_VKE86rr0BCEP4zAD2l8OaF */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S, int_T method,
  void* data);

#endif
