/* Include files */

#include "modelInterface.h"
#include "m_zpJmhMACFGKnoTBNONX1eE.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_zpJmhMACFGKnoTBNONX1eE *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_zpJmhMACFGKnoTBNONX1eE *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  for (i = 0; i < 2; i++) {
    (*moduleInstance->fH_nonlinear)[i] = (*moduleInstance->u2)[i];
  }

  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 2; b_i++) {
      (*moduleInstance->fK)[i][b_i] = (*moduleInstance->u3)[i + (b_i << 3)];
    }

    (*moduleInstance->fX_hat_priori)[i] = (*moduleInstance->u4)[i];
  }

  vEstimationSystemCalculateXposteriori_JDx5nLslLg2PR6bPJ2PDCE
    (*moduleInstance->u0, *moduleInstance->u1);
  for (i = 0; i < 8; i++) {
    (*moduleInstance->b_y0)[i] = (*moduleInstance->fStateVector)[i];
  }
}

static void cgxe_mdl_update(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_zpJmhMACFGKnoTBNONX1eE
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real32_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real32_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real32_T (*)[2])cgxertGetInputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->u3 = (real32_T (*)[16])cgxertGetInputPortSignal
    (moduleInstance->S, 3);
  moduleInstance->u4 = (real32_T (*)[8])cgxertGetInputPortSignal
    (moduleInstance->S, 4);
  moduleInstance->b_y0 = (real32_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  get_fK_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fK);
  get_fH_nonlinear_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_nonlinear);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
  get_fStateVector_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fStateVector);
}

/* CGXE Glue Code */
static void mdlOutputs_zpJmhMACFGKnoTBNONX1eE(SimStruct *S, int_T tid)
{
  InstanceStruct_zpJmhMACFGKnoTBNONX1eE *moduleInstance =
    (InstanceStruct_zpJmhMACFGKnoTBNONX1eE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_zpJmhMACFGKnoTBNONX1eE(SimStruct *S)
{
  InstanceStruct_zpJmhMACFGKnoTBNONX1eE *moduleInstance =
    (InstanceStruct_zpJmhMACFGKnoTBNONX1eE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_zpJmhMACFGKnoTBNONX1eE(SimStruct *S, int_T tid)
{
  InstanceStruct_zpJmhMACFGKnoTBNONX1eE *moduleInstance =
    (InstanceStruct_zpJmhMACFGKnoTBNONX1eE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_zpJmhMACFGKnoTBNONX1eE(SimStruct *S)
{
  InstanceStruct_zpJmhMACFGKnoTBNONX1eE *moduleInstance =
    (InstanceStruct_zpJmhMACFGKnoTBNONX1eE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_zpJmhMACFGKnoTBNONX1eE(SimStruct *S)
{
  InstanceStruct_zpJmhMACFGKnoTBNONX1eE *moduleInstance =
    (InstanceStruct_zpJmhMACFGKnoTBNONX1eE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_zpJmhMACFGKnoTBNONX1eE(SimStruct *S)
{
  InstanceStruct_zpJmhMACFGKnoTBNONX1eE *moduleInstance =
    (InstanceStruct_zpJmhMACFGKnoTBNONX1eE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_zpJmhMACFGKnoTBNONX1eE(SimStruct *S)
{
  InstanceStruct_zpJmhMACFGKnoTBNONX1eE *moduleInstance =
    (InstanceStruct_zpJmhMACFGKnoTBNONX1eE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_zpJmhMACFGKnoTBNONX1eE(SimStruct *S)
{
  InstanceStruct_zpJmhMACFGKnoTBNONX1eE *moduleInstance =
    (InstanceStruct_zpJmhMACFGKnoTBNONX1eE *)calloc(1, sizeof
    (InstanceStruct_zpJmhMACFGKnoTBNONX1eE));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_zpJmhMACFGKnoTBNONX1eE);
  ssSetmdlInitializeConditions(S, mdlInitialize_zpJmhMACFGKnoTBNONX1eE);
  ssSetmdlUpdate(S, mdlUpdate_zpJmhMACFGKnoTBNONX1eE);
  ssSetmdlDerivatives(S, mdlDerivatives_zpJmhMACFGKnoTBNONX1eE);
  ssSetmdlTerminate(S, mdlTerminate_zpJmhMACFGKnoTBNONX1eE);
  ssSetmdlEnable(S, mdlEnable_zpJmhMACFGKnoTBNONX1eE);
  ssSetmdlDisable(S, mdlDisable_zpJmhMACFGKnoTBNONX1eE);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_zpJmhMACFGKnoTBNONX1eE(SimStruct *S)
{
}

void method_dispatcher_zpJmhMACFGKnoTBNONX1eE(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_zpJmhMACFGKnoTBNONX1eE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_zpJmhMACFGKnoTBNONX1eE(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: zpJmhMACFGKnoTBNONX1eE.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_zpJmhMACFGKnoTBNONX1eE_BuildInfoUpdate(void)
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

mxArray *cgxe_zpJmhMACFGKnoTBNONX1eE_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fK");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
