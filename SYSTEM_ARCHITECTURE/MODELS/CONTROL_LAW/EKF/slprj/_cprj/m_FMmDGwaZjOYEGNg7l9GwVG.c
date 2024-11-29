/* Include files */

#include "modelInterface.h"
#include "m_FMmDGwaZjOYEGNg7l9GwVG.h"
#include <string.h>

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
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

static void cgxe_mdl_update(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG
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
static void mdlOutputs_FMmDGwaZjOYEGNg7l9GwVG(SimStruct *S, int_T tid)
{
  InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *moduleInstance =
    (InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_FMmDGwaZjOYEGNg7l9GwVG(SimStruct *S)
{
  InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *moduleInstance =
    (InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_FMmDGwaZjOYEGNg7l9GwVG(SimStruct *S, int_T tid)
{
  InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *moduleInstance =
    (InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_FMmDGwaZjOYEGNg7l9GwVG(SimStruct *S)
{
  InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *moduleInstance =
    (InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_FMmDGwaZjOYEGNg7l9GwVG(SimStruct *S)
{
  InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *moduleInstance =
    (InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_FMmDGwaZjOYEGNg7l9GwVG(SimStruct *S)
{
  InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *moduleInstance =
    (InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_FMmDGwaZjOYEGNg7l9GwVG(SimStruct *S)
{
  InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *moduleInstance =
    (InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_FMmDGwaZjOYEGNg7l9GwVG(SimStruct *S)
{
  InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *moduleInstance =
    (InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG *)calloc(1, sizeof
    (InstanceStruct_FMmDGwaZjOYEGNg7l9GwVG));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_FMmDGwaZjOYEGNg7l9GwVG);
  ssSetmdlInitializeConditions(S, mdlInitialize_FMmDGwaZjOYEGNg7l9GwVG);
  ssSetmdlUpdate(S, mdlUpdate_FMmDGwaZjOYEGNg7l9GwVG);
  ssSetmdlDerivatives(S, mdlDerivatives_FMmDGwaZjOYEGNg7l9GwVG);
  ssSetmdlTerminate(S, mdlTerminate_FMmDGwaZjOYEGNg7l9GwVG);
  ssSetmdlEnable(S, mdlEnable_FMmDGwaZjOYEGNg7l9GwVG);
  ssSetmdlDisable(S, mdlDisable_FMmDGwaZjOYEGNg7l9GwVG);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_FMmDGwaZjOYEGNg7l9GwVG(SimStruct *S)
{
}

void method_dispatcher_FMmDGwaZjOYEGNg7l9GwVG(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_FMmDGwaZjOYEGNg7l9GwVG(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_FMmDGwaZjOYEGNg7l9GwVG(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: FMmDGwaZjOYEGNg7l9GwVG.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_FMmDGwaZjOYEGNg7l9GwVG_BuildInfoUpdate(void)
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

mxArray *cgxe_FMmDGwaZjOYEGNg7l9GwVG_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fF_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
