#ifndef __Ze0n7lUAeQvOMOemfzM33F_h__
#define __Ze0n7lUAeQvOMOemfzM33F_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_Ze0n7lUAeQvOMOemfzM33F
#define typedef_InstanceStruct_Ze0n7lUAeQvOMOemfzM33F

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  real_T *u1;
  real_T (*u2)[64];
  real_T (*u3)[8];
  real_T (*b_y0)[64];
  real_T (*b_y1)[8];
  real_T (*fP_priori)[8][8];
  real_T (*fX_hat_priori)[8];
  real_T (*fP_posteriori)[8][8];
  real_T (*fStateVector)[8];
} InstanceStruct_Ze0n7lUAeQvOMOemfzM33F;

#endif                                 /* typedef_InstanceStruct_Ze0n7lUAeQvOMOemfzM33F */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_Ze0n7lUAeQvOMOemfzM33F(SimStruct *S, int_T method,
  void* data);

#endif
