#ifndef __nV5COsOmba99CNjlC6ekUH_h__
#define __nV5COsOmba99CNjlC6ekUH_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_nV5COsOmba99CNjlC6ekUH
#define typedef_InstanceStruct_nV5COsOmba99CNjlC6ekUH

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  real_T *u1;
  real_T (*u2)[8];
  real_T (*b_y0)[64];
  real_T (*b_y1)[8];
  real_T (*fF_jacobian)[8][8];
  real_T (*fX_hat_priori)[8];
  real_T (*fStateVector)[8];
} InstanceStruct_nV5COsOmba99CNjlC6ekUH;

#endif                                 /* typedef_InstanceStruct_nV5COsOmba99CNjlC6ekUH */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_nV5COsOmba99CNjlC6ekUH(SimStruct *S, int_T method,
  void* data);

#endif
