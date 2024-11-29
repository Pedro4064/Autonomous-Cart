#ifndef __XcCVGp3rm5D0mOUxlqUarG_h__
#define __XcCVGp3rm5D0mOUxlqUarG_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_XcCVGp3rm5D0mOUxlqUarG
#define typedef_InstanceStruct_XcCVGp3rm5D0mOUxlqUarG

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  real_T *u1;
  real_T *u2;
  real_T *u3;
  real_T (*b_y0)[64];
  real_T (*b_y1)[16];
  real_T (*y2)[64];
  real_T (*y3)[64];
  real_T (*y4)[8];
  real_T (*y5)[8];
  real_T (*fF_jacobian)[8][8];
  real_T (*fH_jacobian)[2][8];
  real_T (*fP_posteriori)[8][8];
  real_T (*fP_priori)[8][8];
  real_T (*fStateVector)[8];
  real_T (*fX_hat_priori)[8];
} InstanceStruct_XcCVGp3rm5D0mOUxlqUarG;

#endif                                 /* typedef_InstanceStruct_XcCVGp3rm5D0mOUxlqUarG */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_XcCVGp3rm5D0mOUxlqUarG(SimStruct *S, int_T method,
  void* data);

#endif
