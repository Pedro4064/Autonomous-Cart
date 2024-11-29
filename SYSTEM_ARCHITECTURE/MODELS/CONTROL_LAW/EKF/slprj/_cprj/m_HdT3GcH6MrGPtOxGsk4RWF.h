#ifndef __HdT3GcH6MrGPtOxGsk4RWF_h__
#define __HdT3GcH6MrGPtOxGsk4RWF_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
#define typedef_InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real32_T (*u0)[8];
  real32_T (*b_y0)[16];
  real32_T (*b_y1)[2];
  real32_T (*fX_hat_priori)[8];
  real32_T (*fH_jacobian)[2][8];
  real32_T (*fH_nonlinear)[2];
} InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF;

#endif                                 /* typedef_InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S, int_T method,
  void* data);

#endif
