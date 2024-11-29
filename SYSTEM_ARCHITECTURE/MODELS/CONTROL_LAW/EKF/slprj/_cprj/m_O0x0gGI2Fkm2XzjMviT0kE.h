#ifndef __O0x0gGI2Fkm2XzjMviT0kE_h__
#define __O0x0gGI2Fkm2XzjMviT0kE_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
#define typedef_InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real32_T *u0;
  real32_T *u1;
  real32_T (*u2)[8];
  real32_T (*b_y0)[64];
  real32_T (*b_y1)[8];
  real32_T (*fStateVector)[8];
  real32_T (*fF_jacobian)[8][8];
  real32_T (*fX_hat_priori)[8];
} InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE;

#endif                                 /* typedef_InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S, int_T method,
  void* data);

#endif
