#ifndef __e1B1X6sj4Mr9kUopt69soC_h__
#define __e1B1X6sj4Mr9kUopt69soC_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_e1B1X6sj4Mr9kUopt69soC
#define typedef_InstanceStruct_e1B1X6sj4Mr9kUopt69soC

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real32_T (*u0)[16];
  real32_T (*u1)[64];
  real32_T (*b_y0)[4];
  real32_T (*b_y1)[16];
  real32_T (*y2)[64];
  real32_T (*fH_jacobian)[2][8];
  real32_T (*fP_priori)[8][8];
  real32_T (*fHPH_t)[2][2];
  real32_T (*fK)[8][2];
} InstanceStruct_e1B1X6sj4Mr9kUopt69soC;

#endif                                 /* typedef_InstanceStruct_e1B1X6sj4Mr9kUopt69soC */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_e1B1X6sj4Mr9kUopt69soC(SimStruct *S, int_T method,
  void* data);

#endif
