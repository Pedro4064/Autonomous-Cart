#ifndef __nnkfxkMM6n4smgWpCqYOkE_h__
#define __nnkfxkMM6n4smgWpCqYOkE_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_nnkfxkMM6n4smgWpCqYOkE
#define typedef_InstanceStruct_nnkfxkMM6n4smgWpCqYOkE

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real32_T (*u0)[16];
  real32_T (*u1)[64];
  real32_T (*b_y0)[16];
  real32_T (*b_y1)[64];
  real32_T (*fH_jacobian)[2][8];
  real32_T (*fP_priori)[8][8];
  real32_T (*fK)[8][2];
} InstanceStruct_nnkfxkMM6n4smgWpCqYOkE;

#endif                                 /* typedef_InstanceStruct_nnkfxkMM6n4smgWpCqYOkE */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_nnkfxkMM6n4smgWpCqYOkE(SimStruct *S, int_T method,
  void* data);

#endif
