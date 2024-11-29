/* Include files */

#include "modelInterface.h"
#include "m_XOC21bhpwkWkJBMRA4OdAD.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  vEstimationSystemComputeEstimate_JDx5nLslLg2PR6bPJ2PDCE(*moduleInstance->u0,
    *moduleInstance->u1, *moduleInstance->u2, *moduleInstance->u3);
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->b_y0)[b_i + (i << 3)] = (*moduleInstance->fP_posteriori)
        [b_i][i];
      (*moduleInstance->b_y1)[b_i + (i << 3)] = (*moduleInstance->fP_priori)[b_i]
        [i];
    }

    (*moduleInstance->y2)[i] = (*moduleInstance->fStateVector)[i];
    (*moduleInstance->y3)[i] = (*moduleInstance->fX_hat_priori)[i];
  }
}

static void cgxe_mdl_update(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_XOC21bhpwkWkJBMRA4OdAD
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real32_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real32_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real32_T *)cgxertGetInputPortSignal(moduleInstance->S, 2);
  moduleInstance->u3 = (real32_T *)cgxertGetInputPortSignal(moduleInstance->S, 3);
  moduleInstance->b_y0 = (real32_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real32_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  moduleInstance->y2 = (real32_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->y3 = (real32_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 3);
  get_fP_posteriori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_posteriori);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fStateVector_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fStateVector);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
}

/* CGXE Glue Code */
static void mdlOutputs_XOC21bhpwkWkJBMRA4OdAD(SimStruct *S, int_T tid)
{
  InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *moduleInstance =
    (InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_XOC21bhpwkWkJBMRA4OdAD(SimStruct *S)
{
  InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *moduleInstance =
    (InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_XOC21bhpwkWkJBMRA4OdAD(SimStruct *S, int_T tid)
{
  InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *moduleInstance =
    (InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_XOC21bhpwkWkJBMRA4OdAD(SimStruct *S)
{
  InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *moduleInstance =
    (InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_XOC21bhpwkWkJBMRA4OdAD(SimStruct *S)
{
  InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *moduleInstance =
    (InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_XOC21bhpwkWkJBMRA4OdAD(SimStruct *S)
{
  InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *moduleInstance =
    (InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_XOC21bhpwkWkJBMRA4OdAD(SimStruct *S)
{
  InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *moduleInstance =
    (InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_XOC21bhpwkWkJBMRA4OdAD(SimStruct *S)
{
  InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *moduleInstance =
    (InstanceStruct_XOC21bhpwkWkJBMRA4OdAD *)calloc(1, sizeof
    (InstanceStruct_XOC21bhpwkWkJBMRA4OdAD));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_XOC21bhpwkWkJBMRA4OdAD);
  ssSetmdlInitializeConditions(S, mdlInitialize_XOC21bhpwkWkJBMRA4OdAD);
  ssSetmdlUpdate(S, mdlUpdate_XOC21bhpwkWkJBMRA4OdAD);
  ssSetmdlDerivatives(S, mdlDerivatives_XOC21bhpwkWkJBMRA4OdAD);
  ssSetmdlTerminate(S, mdlTerminate_XOC21bhpwkWkJBMRA4OdAD);
  ssSetmdlEnable(S, mdlEnable_XOC21bhpwkWkJBMRA4OdAD);
  ssSetmdlDisable(S, mdlDisable_XOC21bhpwkWkJBMRA4OdAD);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_XOC21bhpwkWkJBMRA4OdAD(SimStruct *S)
{
}

void method_dispatcher_XOC21bhpwkWkJBMRA4OdAD(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_XOC21bhpwkWkJBMRA4OdAD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_XOC21bhpwkWkJBMRA4OdAD(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: XOC21bhpwkWkJBMRA4OdAD.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_XOC21bhpwkWkJBMRA4OdAD_BuildInfoUpdate(void)
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

mxArray *cgxe_XOC21bhpwkWkJBMRA4OdAD_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fP_posteriori");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
