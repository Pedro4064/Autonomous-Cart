#ifndef __yVfHqSgrKm9zzcpEsENR6D_h__
#define __yVfHqSgrKm9zzcpEsENR6D_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
#define typedef_InstanceStruct_yVfHqSgrKm9zzcpEsENR6D

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  real_T *u1;
  real_T (*u2)[64];
  real_T (*u3)[8];
  real_T (*b_y0)[64];
  real_T (*b_y1)[64];
  real_T (*y2)[64];
  real_T (*y3)[8];
  real_T (*fP_posteriori)[8][8];
  real_T (*fStateVector)[8];
  real_T (*fF_P)[8][8];
  real_T (*fF_jacobian)[8][8];
  real_T (*fP_priori)[8][8];
  real_T (*fX_hat_priori)[8];
} InstanceStruct_yVfHqSgrKm9zzcpEsENR6D;

#endif                                 /* typedef_InstanceStruct_yVfHqSgrKm9zzcpEsENR6D */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S, int_T method,
  void* data);

#endif
