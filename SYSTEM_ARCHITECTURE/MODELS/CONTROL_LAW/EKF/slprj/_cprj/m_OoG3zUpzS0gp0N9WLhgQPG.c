/* Include files */

#include "modelInterface.h"
#include "m_OoG3zUpzS0gp0N9WLhgQPG.h"
#include <string.h>

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  memcpy(&(*moduleInstance->fX_hat_priori)[0], &(*moduleInstance->u0)[0], sizeof
         (real_T) << 3);
  vEstimationSystemComputeObservation_JDx5nLslLg2PR6bPJ2PDCE();
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 2; b_i++) {
      (*moduleInstance->b_y0)[b_i + (i << 1)] = (*moduleInstance->fH_jacobian)
        [b_i][i];
    }
  }

  for (i = 0; i < 2; i++) {
    (*moduleInstance->b_y1)[i] = (*moduleInstance->fH_nonlinear)[i];
  }
}

static void cgxe_mdl_update(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T (*)[8])cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->b_y0 = (real_T (*)[16])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real_T (*)[2])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  get_fH_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_jacobian);
  get_fH_nonlinear_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_nonlinear);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
}

/* CGXE Glue Code */
static void mdlOutputs_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S, int_T tid)
{
  InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *moduleInstance =
    (InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S)
{
  InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *moduleInstance =
    (InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S, int_T tid)
{
  InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *moduleInstance =
    (InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S)
{
  InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *moduleInstance =
    (InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S)
{
  InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *moduleInstance =
    (InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S)
{
  InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *moduleInstance =
    (InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S)
{
  InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *moduleInstance =
    (InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S)
{
  InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *moduleInstance =
    (InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG *)calloc(1, sizeof
    (InstanceStruct_OoG3zUpzS0gp0N9WLhgQPG));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_OoG3zUpzS0gp0N9WLhgQPG);
  ssSetmdlInitializeConditions(S, mdlInitialize_OoG3zUpzS0gp0N9WLhgQPG);
  ssSetmdlUpdate(S, mdlUpdate_OoG3zUpzS0gp0N9WLhgQPG);
  ssSetmdlDerivatives(S, mdlDerivatives_OoG3zUpzS0gp0N9WLhgQPG);
  ssSetmdlTerminate(S, mdlTerminate_OoG3zUpzS0gp0N9WLhgQPG);
  ssSetmdlEnable(S, mdlEnable_OoG3zUpzS0gp0N9WLhgQPG);
  ssSetmdlDisable(S, mdlDisable_OoG3zUpzS0gp0N9WLhgQPG);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S)
{
}

void method_dispatcher_OoG3zUpzS0gp0N9WLhgQPG(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_OoG3zUpzS0gp0N9WLhgQPG(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_OoG3zUpzS0gp0N9WLhgQPG(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: OoG3zUpzS0gp0N9WLhgQPG.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_OoG3zUpzS0gp0N9WLhgQPG_BuildInfoUpdate(void)
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

mxArray *cgxe_OoG3zUpzS0gp0N9WLhgQPG_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fH_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
