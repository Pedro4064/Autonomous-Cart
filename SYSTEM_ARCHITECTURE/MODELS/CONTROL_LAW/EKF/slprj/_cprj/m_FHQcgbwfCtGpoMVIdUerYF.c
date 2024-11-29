/* Include files */

#include "modelInterface.h"
#include "m_FHQcgbwfCtGpoMVIdUerYF.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->fP_priori)[i][b_i] = (*moduleInstance->u2)[i + (b_i << 3)];
    }

    (*moduleInstance->fX_hat_priori)[i] = (*moduleInstance->u3)[i];
  }

  EstimationStep_JDx5nLslLg2PR6bPJ2PDCE(*moduleInstance->u0, *moduleInstance->u1);
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

  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->y2)[b_i + (i << 3)] = (*moduleInstance->fP_posteriori)
        [b_i][i];
    }

    (*moduleInstance->y3)[i] = (*moduleInstance->fStateVector)[i];
  }
}

static void cgxe_mdl_update(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_FHQcgbwfCtGpoMVIdUerYF
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
  moduleInstance->b_y0 = (real_T (*)[16])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real_T (*)[16])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  moduleInstance->y2 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->y3 = (real_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 3);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
  get_fH_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_jacobian);
  get_fK_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fK);
  get_fP_posteriori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_posteriori);
  get_fStateVector_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fStateVector);
}

/* CGXE Glue Code */
static void mdlOutputs_FHQcgbwfCtGpoMVIdUerYF(SimStruct *S, int_T tid)
{
  InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *moduleInstance =
    (InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_FHQcgbwfCtGpoMVIdUerYF(SimStruct *S)
{
  InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *moduleInstance =
    (InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_FHQcgbwfCtGpoMVIdUerYF(SimStruct *S, int_T tid)
{
  InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *moduleInstance =
    (InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_FHQcgbwfCtGpoMVIdUerYF(SimStruct *S)
{
  InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *moduleInstance =
    (InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_FHQcgbwfCtGpoMVIdUerYF(SimStruct *S)
{
  InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *moduleInstance =
    (InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_FHQcgbwfCtGpoMVIdUerYF(SimStruct *S)
{
  InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *moduleInstance =
    (InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_FHQcgbwfCtGpoMVIdUerYF(SimStruct *S)
{
  InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *moduleInstance =
    (InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_FHQcgbwfCtGpoMVIdUerYF(SimStruct *S)
{
  InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *moduleInstance =
    (InstanceStruct_FHQcgbwfCtGpoMVIdUerYF *)calloc(1, sizeof
    (InstanceStruct_FHQcgbwfCtGpoMVIdUerYF));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_FHQcgbwfCtGpoMVIdUerYF);
  ssSetmdlInitializeConditions(S, mdlInitialize_FHQcgbwfCtGpoMVIdUerYF);
  ssSetmdlUpdate(S, mdlUpdate_FHQcgbwfCtGpoMVIdUerYF);
  ssSetmdlDerivatives(S, mdlDerivatives_FHQcgbwfCtGpoMVIdUerYF);
  ssSetmdlTerminate(S, mdlTerminate_FHQcgbwfCtGpoMVIdUerYF);
  ssSetmdlEnable(S, mdlEnable_FHQcgbwfCtGpoMVIdUerYF);
  ssSetmdlDisable(S, mdlDisable_FHQcgbwfCtGpoMVIdUerYF);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_FHQcgbwfCtGpoMVIdUerYF(SimStruct *S)
{
}

void method_dispatcher_FHQcgbwfCtGpoMVIdUerYF(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_FHQcgbwfCtGpoMVIdUerYF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_FHQcgbwfCtGpoMVIdUerYF(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: FHQcgbwfCtGpoMVIdUerYF.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_FHQcgbwfCtGpoMVIdUerYF_BuildInfoUpdate(void)
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

mxArray *cgxe_FHQcgbwfCtGpoMVIdUerYF_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fP_priori");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
