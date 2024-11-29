#ifndef __OoG3zUpzS0gp0N9WLhgQPG_h__
#define __OoG3zUpzS0gp0N9WLhgQPG_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
#define typedef_InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T (*u0)[8];
  real_T (*b_y0)[16];
  real_T (*b_y1)[2];
  real_T (*fH_jacobian)[2][8];
  real_T (*fH_nonlinear)[2];
  real_T (*fX_hat_priori)[8];
} InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG;

#endif                                 /* typedef_InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S, int_T method,
  void* data);

#endif
