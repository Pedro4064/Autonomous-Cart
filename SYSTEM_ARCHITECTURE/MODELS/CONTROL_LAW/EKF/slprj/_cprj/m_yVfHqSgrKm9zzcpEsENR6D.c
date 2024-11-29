/* Include files */

#include "modelInterface.h"
#include "m_yVfHqSgrKm9zzcpEsENR6D.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
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
      (*moduleInstance->b_y0)[b_i + (i << 3)] = (*moduleInstance->fF_P)[b_i][i];
      (*moduleInstance->b_y1)[b_i + (i << 3)] = (*moduleInstance->fF_jacobian)
        [b_i][i];
      (*moduleInstance->y2)[b_i + (i << 3)] = (*moduleInstance->fP_priori)[b_i]
        [i];
    }

    (*moduleInstance->y3)[i] = (*moduleInstance->fX_hat_priori)[i];
  }
}

static void cgxe_mdl_update(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_yVfHqSgrKm9zzcpEsENR6D
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
  moduleInstance->y2 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->y3 = (real_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 3);
  get_fP_posteriori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_posteriori);
  get_fStateVector_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fStateVector);
  get_fF_P_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fF_P);
  get_fF_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fF_jacobian);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
}

/* CGXE Glue Code */
static void mdlOutputs_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S, int_T tid)
{
  InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *moduleInstance =
    (InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S)
{
  InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *moduleInstance =
    (InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S, int_T tid)
{
  InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *moduleInstance =
    (InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S)
{
  InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *moduleInstance =
    (InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S)
{
  InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *moduleInstance =
    (InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S)
{
  InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *moduleInstance =
    (InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S)
{
  InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *moduleInstance =
    (InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S)
{
  InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *moduleInstance =
    (InstanceStruct_yVfHqSgrKm9zzcpEsENR6D *)calloc(1, sizeof
    (InstanceStruct_yVfHqSgrKm9zzcpEsENR6D));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_yVfHqSgrKm9zzcpEsENR6D);
  ssSetmdlInitializeConditions(S, mdlInitialize_yVfHqSgrKm9zzcpEsENR6D);
  ssSetmdlUpdate(S, mdlUpdate_yVfHqSgrKm9zzcpEsENR6D);
  ssSetmdlDerivatives(S, mdlDerivatives_yVfHqSgrKm9zzcpEsENR6D);
  ssSetmdlTerminate(S, mdlTerminate_yVfHqSgrKm9zzcpEsENR6D);
  ssSetmdlEnable(S, mdlEnable_yVfHqSgrKm9zzcpEsENR6D);
  ssSetmdlDisable(S, mdlDisable_yVfHqSgrKm9zzcpEsENR6D);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S)
{
}

void method_dispatcher_yVfHqSgrKm9zzcpEsENR6D(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_yVfHqSgrKm9zzcpEsENR6D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_yVfHqSgrKm9zzcpEsENR6D(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: yVfHqSgrKm9zzcpEsENR6D.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_yVfHqSgrKm9zzcpEsENR6D_BuildInfoUpdate(void)
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

mxArray *cgxe_yVfHqSgrKm9zzcpEsENR6D_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fP_posteriori");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
