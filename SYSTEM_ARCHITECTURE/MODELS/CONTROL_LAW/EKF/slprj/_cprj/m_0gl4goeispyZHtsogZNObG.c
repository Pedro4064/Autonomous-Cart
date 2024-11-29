/* Include files */

#include "modelInterface.h"
#include "m_0gl4goeispyZHtsogZNObG.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_0gl4goeispyZHtsogZNObG *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_0gl4goeispyZHtsogZNObG *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance)
{
  int32_T i;
  int32_T i1;
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->fH_jacobian)[i][i1] = (*moduleInstance->u0)[i + (i1 << 1)];
    }
  }

  for (i = 0; i < 8; i++) {
    for (i1 = 0; i1 < 2; i1++) {
      (*moduleInstance->fK)[i][i1] = (*moduleInstance->u1)[i + (i1 << 3)];
    }

    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->fP_priori)[i][i1] = (*moduleInstance->u2)[i + (i1 << 3)];
    }
  }

  vEstimationSystemCalculatePposteriori_JDx5nLslLg2PR6bPJ2PDCE();
  for (i = 0; i < 8; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->b_y0)[i1 + (i << 3)] = (*moduleInstance->fP_posteriori)
        [i1][i];
    }
  }
}

static void cgxe_mdl_update(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_0gl4goeispyZHtsogZNObG
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real32_T (*)[16])cgxertGetInputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->u1 = (real32_T (*)[16])cgxertGetInputPortSignal
    (moduleInstance->S, 1);
  moduleInstance->u2 = (real32_T (*)[64])cgxertGetInputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->b_y0 = (real32_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  get_fH_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_jacobian);
  get_fK_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fK);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fP_posteriori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_posteriori);
}

/* CGXE Glue Code */
static void mdlOutputs_0gl4goeispyZHtsogZNObG(SimStruct *S, int_T tid)
{
  InstanceStruct_0gl4goeispyZHtsogZNObG *moduleInstance =
    (InstanceStruct_0gl4goeispyZHtsogZNObG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_0gl4goeispyZHtsogZNObG(SimStruct *S)
{
  InstanceStruct_0gl4goeispyZHtsogZNObG *moduleInstance =
    (InstanceStruct_0gl4goeispyZHtsogZNObG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_0gl4goeispyZHtsogZNObG(SimStruct *S, int_T tid)
{
  InstanceStruct_0gl4goeispyZHtsogZNObG *moduleInstance =
    (InstanceStruct_0gl4goeispyZHtsogZNObG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_0gl4goeispyZHtsogZNObG(SimStruct *S)
{
  InstanceStruct_0gl4goeispyZHtsogZNObG *moduleInstance =
    (InstanceStruct_0gl4goeispyZHtsogZNObG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_0gl4goeispyZHtsogZNObG(SimStruct *S)
{
  InstanceStruct_0gl4goeispyZHtsogZNObG *moduleInstance =
    (InstanceStruct_0gl4goeispyZHtsogZNObG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_0gl4goeispyZHtsogZNObG(SimStruct *S)
{
  InstanceStruct_0gl4goeispyZHtsogZNObG *moduleInstance =
    (InstanceStruct_0gl4goeispyZHtsogZNObG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_0gl4goeispyZHtsogZNObG(SimStruct *S)
{
  InstanceStruct_0gl4goeispyZHtsogZNObG *moduleInstance =
    (InstanceStruct_0gl4goeispyZHtsogZNObG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_0gl4goeispyZHtsogZNObG(SimStruct *S)
{
  InstanceStruct_0gl4goeispyZHtsogZNObG *moduleInstance =
    (InstanceStruct_0gl4goeispyZHtsogZNObG *)calloc(1, sizeof
    (InstanceStruct_0gl4goeispyZHtsogZNObG));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_0gl4goeispyZHtsogZNObG);
  ssSetmdlInitializeConditions(S, mdlInitialize_0gl4goeispyZHtsogZNObG);
  ssSetmdlUpdate(S, mdlUpdate_0gl4goeispyZHtsogZNObG);
  ssSetmdlDerivatives(S, mdlDerivatives_0gl4goeispyZHtsogZNObG);
  ssSetmdlTerminate(S, mdlTerminate_0gl4goeispyZHtsogZNObG);
  ssSetmdlEnable(S, mdlEnable_0gl4goeispyZHtsogZNObG);
  ssSetmdlDisable(S, mdlDisable_0gl4goeispyZHtsogZNObG);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_0gl4goeispyZHtsogZNObG(SimStruct *S)
{
}

void method_dispatcher_0gl4goeispyZHtsogZNObG(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_0gl4goeispyZHtsogZNObG(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_0gl4goeispyZHtsogZNObG(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: 0gl4goeispyZHtsogZNObG.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_0gl4goeispyZHtsogZNObG_BuildInfoUpdate(void)
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

mxArray *cgxe_0gl4goeispyZHtsogZNObG_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fH_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
