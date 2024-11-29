/* Include files */

#include "modelInterface.h"
#include "m_Y6EQBRvAKrIpoXDYdkEY8B.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->fP_priori)[i][b_i] = (*moduleInstance->u0)[i + (b_i << 3)];
    }

    (*moduleInstance->fX_hat_priori)[i] = (*moduleInstance->u1)[i];
  }

  vEstimationSYstemCalculateK_JDx5nLslLg2PR6bPJ2PDCE();
  for (b_i = 0; b_i < 8; b_i++) {
    for (i = 0; i < 2; i++) {
      (*moduleInstance->b_y0)[i + (b_i << 1)] = (*moduleInstance->fH_jacobian)[i]
        [b_i];
    }
  }

  for (b_i = 0; b_i < 2; b_i++) {
    for (i = 0; i < 8; i++) {
      (*moduleInstance->b_y1)[i + (b_i << 3)] = (*moduleInstance->fK)[i][b_i];
    }
  }
}

static void cgxe_mdl_update(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T (*)[64])cgxertGetInputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->u1 = (real_T (*)[8])cgxertGetInputPortSignal(moduleInstance->S,
    1);
  moduleInstance->b_y0 = (real_T (*)[16])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real_T (*)[16])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
  get_fH_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_jacobian);
  get_fK_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fK);
}

/* CGXE Glue Code */
static void mdlOutputs_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S, int_T tid)
{
  InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *moduleInstance =
    (InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S)
{
  InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *moduleInstance =
    (InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S, int_T tid)
{
  InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *moduleInstance =
    (InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S)
{
  InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *moduleInstance =
    (InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S)
{
  InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *moduleInstance =
    (InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S)
{
  InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *moduleInstance =
    (InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S)
{
  InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *moduleInstance =
    (InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S)
{
  InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *moduleInstance =
    (InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B *)calloc(1, sizeof
    (InstanceStruct_Y6EQBRvAKrIpoXDYdkEY8B));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_Y6EQBRvAKrIpoXDYdkEY8B);
  ssSetmdlInitializeConditions(S, mdlInitialize_Y6EQBRvAKrIpoXDYdkEY8B);
  ssSetmdlUpdate(S, mdlUpdate_Y6EQBRvAKrIpoXDYdkEY8B);
  ssSetmdlDerivatives(S, mdlDerivatives_Y6EQBRvAKrIpoXDYdkEY8B);
  ssSetmdlTerminate(S, mdlTerminate_Y6EQBRvAKrIpoXDYdkEY8B);
  ssSetmdlEnable(S, mdlEnable_Y6EQBRvAKrIpoXDYdkEY8B);
  ssSetmdlDisable(S, mdlDisable_Y6EQBRvAKrIpoXDYdkEY8B);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S)
{
}

void method_dispatcher_Y6EQBRvAKrIpoXDYdkEY8B(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_Y6EQBRvAKrIpoXDYdkEY8B(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_Y6EQBRvAKrIpoXDYdkEY8B(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: Y6EQBRvAKrIpoXDYdkEY8B.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_Y6EQBRvAKrIpoXDYdkEY8B_BuildInfoUpdate(void)
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

mxArray *cgxe_Y6EQBRvAKrIpoXDYdkEY8B_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fP_priori");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
