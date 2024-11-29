#ifndef __0gl4goeispyZHtsogZNObG_h__
#define __0gl4goeispyZHtsogZNObG_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_0gl4goeispyZHtsogZNObG
#define typedef_InstanceStruct_0gl4goeispyZHtsogZNObG

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real32_T (*u0)[16];
  real32_T (*u1)[16];
  real32_T (*u2)[64];
  real32_T (*b_y0)[64];
  real32_T (*fH_jacobian)[2][8];
  real32_T (*fK)[8][2];
  real32_T (*fP_priori)[8][8];
  real32_T (*fP_posteriori)[8][8];
} InstanceStruct_0gl4goeispyZHtsogZNObG;

#endif                                 /* typedef_InstanceStruct_0gl4goeispyZHtsogZNObG */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_0gl4goeispyZHtsogZNObG(SimStruct *S, int_T method,
  void* data);

#endif
