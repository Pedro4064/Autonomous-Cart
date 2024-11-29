#ifndef __fJBStO3qGGTGJmOEl3OqpD_h__
#define __fJBStO3qGGTGJmOEl3OqpD_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
#define typedef_InstanceStruct_fJBStO3qGGTGJmOEl3OqpD

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T (*u0)[16];
  real_T (*u1)[16];
  real_T (*u2)[64];
  real_T (*b_y0)[64];
  real_T (*fH_jacobian)[2][8];
  real_T (*fK)[8][2];
  real_T (*fP_priori)[8][8];
  real_T (*fP_posteriori)[8][8];
} InstanceStruct_fJBStO3qGGTGJmOEl3OqpD;

#endif                                 /* typedef_InstanceStruct_fJBStO3qGGTGJmOEl3OqpD */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S, int_T method,
  void* data);

#endif
