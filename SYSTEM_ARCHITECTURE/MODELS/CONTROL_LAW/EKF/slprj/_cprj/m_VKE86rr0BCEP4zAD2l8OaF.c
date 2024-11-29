/* Include files */

#include "modelInterface.h"
#include "m_VKE86rr0BCEP4zAD2l8OaF.h"
#include <string.h>

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance)
{
  int32_T i;
  int32_T i1;
  memcpy(&(*moduleInstance->fStateVector)[0], &(*moduleInstance->u2)[0], sizeof
         (real_T) << 3);
  CalculateFjacobian_JDx5nLslLg2PR6bPJ2PDCE(*moduleInstance->u0,
    *moduleInstance->u1);
  for (i = 0; i < 8; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->b_y0)[i1 + (i << 3)] = (*moduleInstance->fF_jacobian)[i1]
        [i];
    }
  }
}

static void cgxe_mdl_update(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_VKE86rr0BCEP4zAD2l8OaF
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real_T (*)[8])cgxertGetInputPortSignal(moduleInstance->S,
    2);
  moduleInstance->b_y0 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  get_fF_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fF_jacobian);
  get_fStateVector_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fStateVector);
}

/* CGXE Glue Code */
static void mdlOutputs_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S, int_T tid)
{
  InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *moduleInstance =
    (InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S)
{
  InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *moduleInstance =
    (InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S, int_T tid)
{
  InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *moduleInstance =
    (InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S)
{
  InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *moduleInstance =
    (InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S)
{
  InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *moduleInstance =
    (InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S)
{
  InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *moduleInstance =
    (InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S)
{
  InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *moduleInstance =
    (InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S)
{
  InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *moduleInstance =
    (InstanceStruct_VKE86rr0BCEP4zAD2l8OaF *)calloc(1, sizeof
    (InstanceStruct_VKE86rr0BCEP4zAD2l8OaF));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_VKE86rr0BCEP4zAD2l8OaF);
  ssSetmdlInitializeConditions(S, mdlInitialize_VKE86rr0BCEP4zAD2l8OaF);
  ssSetmdlUpdate(S, mdlUpdate_VKE86rr0BCEP4zAD2l8OaF);
  ssSetmdlDerivatives(S, mdlDerivatives_VKE86rr0BCEP4zAD2l8OaF);
  ssSetmdlTerminate(S, mdlTerminate_VKE86rr0BCEP4zAD2l8OaF);
  ssSetmdlEnable(S, mdlEnable_VKE86rr0BCEP4zAD2l8OaF);
  ssSetmdlDisable(S, mdlDisable_VKE86rr0BCEP4zAD2l8OaF);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S)
{
}

void method_dispatcher_VKE86rr0BCEP4zAD2l8OaF(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_VKE86rr0BCEP4zAD2l8OaF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_VKE86rr0BCEP4zAD2l8OaF(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: VKE86rr0BCEP4zAD2l8OaF.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_VKE86rr0BCEP4zAD2l8OaF_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  double * pointer;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateDoubleMatrix(0,0, mxREAL);
  pointer = mxGetPr(elem_1);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_2 = mxCreateDoubleMatrix(0,0, mxREAL);
  pointer = mxGetPr(elem_2);
  mxSetCell(mxBIArgs,1,elem_2);
  elem_3 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_3);
  return mxBIArgs;
}

mxArray *cgxe_VKE86rr0BCEP4zAD2l8OaF_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fF_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
