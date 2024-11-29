#ifndef __I2XsiLP1Qy6uHMRldLoCnG_h__
#define __I2XsiLP1Qy6uHMRldLoCnG_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
#define typedef_InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T (*u0)[64];
  real_T (*u1)[64];
  real_T (*b_y0)[64];
  real_T (*fF_jacobian)[8][8];
  real_T (*fP_posteriori)[8][8];
  real_T (*fP_priori)[8][8];
} InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG;

#endif                                 /* typedef_InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S, int_T method,
  void* data);

#endif
