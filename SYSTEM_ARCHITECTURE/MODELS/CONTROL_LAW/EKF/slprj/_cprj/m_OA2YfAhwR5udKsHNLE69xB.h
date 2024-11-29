#ifndef __OA2YfAhwR5udKsHNLE69xB_h__
#define __OA2YfAhwR5udKsHNLE69xB_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_OA2YfAhwR5udKsHNLE69xB
#define typedef_InstanceStruct_OA2YfAhwR5udKsHNLE69xB

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  real_T *u1;
  real_T (*u2)[16];
  real_T (*u3)[64];
  real_T (*u4)[8];
  real_T (*b_y0)[16];
  real_T (*b_y1)[64];
  real_T (*y2)[8];
  real_T (*fK)[8][2];
  real_T (*fP_priori)[8][8];
  real_T (*fX_hat_priori)[8];
  real_T (*fH_jacobian)[2][8];
  real_T (*fP_posteriori)[8][8];
  real_T (*fStateVector)[8];
} InstanceStruct_OA2YfAhwR5udKsHNLE69xB;

#endif                                 /* typedef_InstanceStruct_OA2YfAhwR5udKsHNLE69xB */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_OA2YfAhwR5udKsHNLE69xB(SimStruct *S, int_T method,
  void* data);

#endif
