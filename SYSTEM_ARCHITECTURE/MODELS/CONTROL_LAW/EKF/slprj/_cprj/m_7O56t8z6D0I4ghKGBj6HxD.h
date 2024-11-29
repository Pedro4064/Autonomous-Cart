#ifndef __7O56t8z6D0I4ghKGBj6HxD_h__
#define __7O56t8z6D0I4ghKGBj6HxD_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_7O56t8z6D0I4ghKGBj6HxD
#define typedef_InstanceStruct_7O56t8z6D0I4ghKGBj6HxD

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
} InstanceStruct_7O56t8z6D0I4ghKGBj6HxD;

#endif                                 /* typedef_InstanceStruct_7O56t8z6D0I4ghKGBj6HxD */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_7O56t8z6D0I4ghKGBj6HxD(SimStruct *S, int_T method,
  void* data);

#endif
