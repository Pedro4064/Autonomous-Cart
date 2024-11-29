#ifndef __CwtKrCRvkqmSRSMd0i2Y3G_h__
#define __CwtKrCRvkqmSRSMd0i2Y3G_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_CwtKrCRvkqmSRSMd0i2Y3G
#define typedef_InstanceStruct_CwtKrCRvkqmSRSMd0i2Y3G

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real32_T *u0;
  real32_T *u1;
  real32_T *u2;
  real32_T *u3;
  real32_T (*b_y0)[64];
  real32_T (*b_y1)[64];
  real32_T (*y2)[64];
  real32_T (*y3)[8];
  real32_T (*y4)[8];
  real32_T (*fF_jacobian)[8][8];
  real32_T (*fP_posteriori)[8][8];
  real32_T (*fP_priori)[8][8];
  real32_T (*fStateVector)[8];
  real32_T (*fX_hat_priori)[8];
} InstanceStruct_CwtKrCRvkqmSRSMd0i2Y3G;

#endif                                 /* typedef_InstanceStruct_CwtKrCRvkqmSRSMd0i2Y3G */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_CwtKrCRvkqmSRSMd0i2Y3G(SimStruct *S, int_T method,
  void* data);

#endif
