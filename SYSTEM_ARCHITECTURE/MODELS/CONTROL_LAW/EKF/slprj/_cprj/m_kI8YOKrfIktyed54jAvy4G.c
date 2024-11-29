/* Include files */

#include "modelInterface.h"
#include "m_kI8YOKrfIktyed54jAvy4G.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_kI8YOKrfIktyed54jAvy4G *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_kI8YOKrfIktyed54jAvy4G *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->fP_posteriori)[i][b_i] = (*moduleInstance->u2)[i + (b_i <<
        3)];
    }

    (*moduleInstance->fStateVector)[i] = (*moduleInstance->u3)[i];
  }

  PredictionStep_JDx5nLslLg2PR6bPJ2PDCE(*moduleInstance->u0, *moduleInstance->u1);
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->b_y0)[b_i + (i << 3)] = (*moduleInstance->fF_jacobian)
        [b_i][i];
      (*moduleInstance->b_y1)[b_i + (i << 3)] = (*moduleInstance->fP_priori)[b_i]
        [i];
    }

    (*moduleInstance->y2)[i] = (*moduleInstance->fX_hat_priori)[i];
  }
}

static void cgxe_mdl_update(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_kI8YOKrfIktyed54jAvy4G
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real_T (*)[64])cgxertGetInputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->u3 = (real_T (*)[8])cgxertGetInputPortSignal(moduleInstance->S,
    3);
  moduleInstance->b_y0 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  moduleInstance->y2 = (real_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 2);
  get_fP_posteriori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_posteriori);
  get_fStateVector_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fStateVector);
  get_fF_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fF_jacobian);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
}

/* CGXE Glue Code */
static void mdlOutputs_kI8YOKrfIktyed54jAvy4G(SimStruct *S, int_T tid)
{
  InstanceStruct_kI8YOKrfIktyed54jAvy4G *moduleInstance =
    (InstanceStruct_kI8YOKrfIktyed54jAvy4G *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_kI8YOKrfIktyed54jAvy4G(SimStruct *S)
{
  InstanceStruct_kI8YOKrfIktyed54jAvy4G *moduleInstance =
    (InstanceStruct_kI8YOKrfIktyed54jAvy4G *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_kI8YOKrfIktyed54jAvy4G(SimStruct *S, int_T tid)
{
  InstanceStruct_kI8YOKrfIktyed54jAvy4G *moduleInstance =
    (InstanceStruct_kI8YOKrfIktyed54jAvy4G *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_kI8YOKrfIktyed54jAvy4G(SimStruct *S)
{
  InstanceStruct_kI8YOKrfIktyed54jAvy4G *moduleInstance =
    (InstanceStruct_kI8YOKrfIktyed54jAvy4G *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_kI8YOKrfIktyed54jAvy4G(SimStruct *S)
{
  InstanceStruct_kI8YOKrfIktyed54jAvy4G *moduleInstance =
    (InstanceStruct_kI8YOKrfIktyed54jAvy4G *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_kI8YOKrfIktyed54jAvy4G(SimStruct *S)
{
  InstanceStruct_kI8YOKrfIktyed54jAvy4G *moduleInstance =
    (InstanceStruct_kI8YOKrfIktyed54jAvy4G *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_kI8YOKrfIktyed54jAvy4G(SimStruct *S)
{
  InstanceStruct_kI8YOKrfIktyed54jAvy4G *moduleInstance =
    (InstanceStruct_kI8YOKrfIktyed54jAvy4G *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_kI8YOKrfIktyed54jAvy4G(SimStruct *S)
{
  InstanceStruct_kI8YOKrfIktyed54jAvy4G *moduleInstance =
    (InstanceStruct_kI8YOKrfIktyed54jAvy4G *)calloc(1, sizeof
    (InstanceStruct_kI8YOKrfIktyed54jAvy4G));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_kI8YOKrfIktyed54jAvy4G);
  ssSetmdlInitializeConditions(S, mdlInitialize_kI8YOKrfIktyed54jAvy4G);
  ssSetmdlUpdate(S, mdlUpdate_kI8YOKrfIktyed54jAvy4G);
  ssSetmdlDerivatives(S, mdlDerivatives_kI8YOKrfIktyed54jAvy4G);
  ssSetmdlTerminate(S, mdlTerminate_kI8YOKrfIktyed54jAvy4G);
  ssSetmdlEnable(S, mdlEnable_kI8YOKrfIktyed54jAvy4G);
  ssSetmdlDisable(S, mdlDisable_kI8YOKrfIktyed54jAvy4G);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_kI8YOKrfIktyed54jAvy4G(SimStruct *S)
{
}

void method_dispatcher_kI8YOKrfIktyed54jAvy4G(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_kI8YOKrfIktyed54jAvy4G(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_kI8YOKrfIktyed54jAvy4G(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: kI8YOKrfIktyed54jAvy4G.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_kI8YOKrfIktyed54jAvy4G_BuildInfoUpdate(void)
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

mxArray *cgxe_kI8YOKrfIktyed54jAvy4G_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fP_posteriori");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
