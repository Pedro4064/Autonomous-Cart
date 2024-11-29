/* Include files */

#include "modelInterface.h"
#include "m_HdT3GcH6MrGPtOxGsk4RWF.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  for (i = 0; i < 8; i++) {
    (*moduleInstance->fX_hat_priori)[i] = (*moduleInstance->u0)[i];
  }

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

static void cgxe_mdl_update(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real32_T (*)[8])cgxertGetInputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y0 = (real32_T (*)[16])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real32_T (*)[2])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
  get_fH_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_jacobian);
  get_fH_nonlinear_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_nonlinear);
}

/* CGXE Glue Code */
static void mdlOutputs_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S, int_T tid)
{
  InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *moduleInstance =
    (InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S)
{
  InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *moduleInstance =
    (InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S, int_T tid)
{
  InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *moduleInstance =
    (InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S)
{
  InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *moduleInstance =
    (InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S)
{
  InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *moduleInstance =
    (InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S)
{
  InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *moduleInstance =
    (InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S)
{
  InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *moduleInstance =
    (InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S)
{
  InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *moduleInstance =
    (InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF *)calloc(1, sizeof
    (InstanceStruct_HdT3GcH6MrGPtOxGsk4RWF));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_HdT3GcH6MrGPtOxGsk4RWF);
  ssSetmdlInitializeConditions(S, mdlInitialize_HdT3GcH6MrGPtOxGsk4RWF);
  ssSetmdlUpdate(S, mdlUpdate_HdT3GcH6MrGPtOxGsk4RWF);
  ssSetmdlDerivatives(S, mdlDerivatives_HdT3GcH6MrGPtOxGsk4RWF);
  ssSetmdlTerminate(S, mdlTerminate_HdT3GcH6MrGPtOxGsk4RWF);
  ssSetmdlEnable(S, mdlEnable_HdT3GcH6MrGPtOxGsk4RWF);
  ssSetmdlDisable(S, mdlDisable_HdT3GcH6MrGPtOxGsk4RWF);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S)
{
}

void method_dispatcher_HdT3GcH6MrGPtOxGsk4RWF(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_HdT3GcH6MrGPtOxGsk4RWF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_HdT3GcH6MrGPtOxGsk4RWF(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: HdT3GcH6MrGPtOxGsk4RWF.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_HdT3GcH6MrGPtOxGsk4RWF_BuildInfoUpdate(void)
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

mxArray *cgxe_HdT3GcH6MrGPtOxGsk4RWF_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fH_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
