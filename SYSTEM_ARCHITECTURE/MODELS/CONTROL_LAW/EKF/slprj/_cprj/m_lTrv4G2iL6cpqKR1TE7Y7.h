#ifndef __lTrv4G2iL6cpqKR1TE7Y7_h__
#define __lTrv4G2iL6cpqKR1TE7Y7_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_lTrv4G2iL6cpqKR1TE7Y7
#define typedef_InstanceStruct_lTrv4G2iL6cpqKR1TE7Y7

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
} InstanceStruct_lTrv4G2iL6cpqKR1TE7Y7;

#endif                                 /* typedef_InstanceStruct_lTrv4G2iL6cpqKR1TE7Y7 */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_lTrv4G2iL6cpqKR1TE7Y7(SimStruct *S, int_T method,
  void* data);

#endif
