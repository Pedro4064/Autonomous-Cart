/* Include files */

#include "modelInterface.h"
#include "m_nV5COsOmba99CNjlC6ekUH.h"
#include <string.h>

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_nV5COsOmba99CNjlC6ekUH *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_nV5COsOmba99CNjlC6ekUH *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  memcpy(&(*moduleInstance->fStateVector)[0], &(*moduleInstance->u2)[0], sizeof
         (real_T) << 3);
  vEstimationSystemComputeDynamicModel_JDx5nLslLg2PR6bPJ2PDCE
    (*moduleInstance->u0, *moduleInstance->u1);
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->b_y0)[b_i + (i << 3)] = (*moduleInstance->fF_jacobian)
        [b_i][i];
    }

    (*moduleInstance->b_y1)[i] = (*moduleInstance->fX_hat_priori)[i];
  }
}

static void cgxe_mdl_update(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_nV5COsOmba99CNjlC6ekUH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_nV5COsOmba99CNjlC6ekUH
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
  moduleInstance->b_y1 = (real_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  get_fF_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fF_jacobian);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
  get_fStateVector_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fStateVector);
}

/* CGXE Glue Code */
static void mdlOutputs_nV5COsOmba99CNjlC6ekUH(SimStruct *S, int_T tid)
{
  InstanceStruct_nV5COsOmba99CNjlC6ekUH *moduleInstance =
    (InstanceStruct_nV5COsOmba99CNjlC6ekUH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_nV5COsOmba99CNjlC6ekUH(SimStruct *S)
{
  InstanceStruct_nV5COsOmba99CNjlC6ekUH *moduleInstance =
    (InstanceStruct_nV5COsOmba99CNjlC6ekUH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_nV5COsOmba99CNjlC6ekUH(SimStruct *S, int_T tid)
{
  InstanceStruct_nV5COsOmba99CNjlC6ekUH *moduleInstance =
    (InstanceStruct_nV5COsOmba99CNjlC6ekUH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_nV5COsOmba99CNjlC6ekUH(SimStruct *S)
{
  InstanceStruct_nV5COsOmba99CNjlC6ekUH *moduleInstance =
    (InstanceStruct_nV5COsOmba99CNjlC6ekUH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_nV5COsOmba99CNjlC6ekUH(SimStruct *S)
{
  InstanceStruct_nV5COsOmba99CNjlC6ekUH *moduleInstance =
    (InstanceStruct_nV5COsOmba99CNjlC6ekUH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_nV5COsOmba99CNjlC6ekUH(SimStruct *S)
{
  InstanceStruct_nV5COsOmba99CNjlC6ekUH *moduleInstance =
    (InstanceStruct_nV5COsOmba99CNjlC6ekUH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_nV5COsOmba99CNjlC6ekUH(SimStruct *S)
{
  InstanceStruct_nV5COsOmba99CNjlC6ekUH *moduleInstance =
    (InstanceStruct_nV5COsOmba99CNjlC6ekUH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_nV5COsOmba99CNjlC6ekUH(SimStruct *S)
{
  InstanceStruct_nV5COsOmba99CNjlC6ekUH *moduleInstance =
    (InstanceStruct_nV5COsOmba99CNjlC6ekUH *)calloc(1, sizeof
    (InstanceStruct_nV5COsOmba99CNjlC6ekUH));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_nV5COsOmba99CNjlC6ekUH);
  ssSetmdlInitializeConditions(S, mdlInitialize_nV5COsOmba99CNjlC6ekUH);
  ssSetmdlUpdate(S, mdlUpdate_nV5COsOmba99CNjlC6ekUH);
  ssSetmdlDerivatives(S, mdlDerivatives_nV5COsOmba99CNjlC6ekUH);
  ssSetmdlTerminate(S, mdlTerminate_nV5COsOmba99CNjlC6ekUH);
  ssSetmdlEnable(S, mdlEnable_nV5COsOmba99CNjlC6ekUH);
  ssSetmdlDisable(S, mdlDisable_nV5COsOmba99CNjlC6ekUH);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_nV5COsOmba99CNjlC6ekUH(SimStruct *S)
{
}

void method_dispatcher_nV5COsOmba99CNjlC6ekUH(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_nV5COsOmba99CNjlC6ekUH(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_nV5COsOmba99CNjlC6ekUH(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: nV5COsOmba99CNjlC6ekUH.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_nV5COsOmba99CNjlC6ekUH_BuildInfoUpdate(void)
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

mxArray *cgxe_nV5COsOmba99CNjlC6ekUH_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fF_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
