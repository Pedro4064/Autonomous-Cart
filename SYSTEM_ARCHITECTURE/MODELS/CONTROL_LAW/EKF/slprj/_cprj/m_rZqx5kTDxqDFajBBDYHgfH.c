/* Include files */

#include "modelInterface.h"
#include "m_rZqx5kTDxqDFajBBDYHgfH.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  vEstimationSystemComputeEstimate_JDx5nLslLg2PR6bPJ2PDCE(*moduleInstance->u0,
    *moduleInstance->u1, *moduleInstance->u2, *moduleInstance->u3);
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->b_y0)[b_i + (i << 3)] = (*moduleInstance->fF_P)[b_i][i];
      (*moduleInstance->b_y1)[b_i + (i << 3)] = (*moduleInstance->fF_jacobian)
        [b_i][i];
    }

    for (b_i = 0; b_i < 2; b_i++) {
      (*moduleInstance->y2)[b_i + (i << 1)] = (*moduleInstance->fH_jacobian)[b_i]
        [i];
    }
  }

  for (b_i = 0; b_i < 2; b_i++) {
    (*moduleInstance->y3)[b_i] = (*moduleInstance->fH_nonlinear)[b_i];
    for (i = 0; i < 8; i++) {
      (*moduleInstance->y4)[i + (b_i << 3)] = (*moduleInstance->fK)[i][b_i];
    }
  }

  for (b_i = 0; b_i < 8; b_i++) {
    for (i = 0; i < 8; i++) {
      (*moduleInstance->y5)[i + (b_i << 3)] = (*moduleInstance->fP_posteriori)[i]
        [b_i];
      (*moduleInstance->y6)[i + (b_i << 3)] = (*moduleInstance->fP_priori)[i]
        [b_i];
    }

    (*moduleInstance->y7)[b_i] = (*moduleInstance->fStateVector)[b_i];
    (*moduleInstance->y8)[b_i] = (*moduleInstance->fX_hat_priori)[b_i];
  }
}

static void cgxe_mdl_update(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_rZqx5kTDxqDFajBBDYHgfH
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 2);
  moduleInstance->u3 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 3);
  moduleInstance->b_y0 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  moduleInstance->y2 = (real_T (*)[16])cgxertGetOutputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->y3 = (real_T (*)[2])cgxertGetOutputPortSignal
    (moduleInstance->S, 3);
  moduleInstance->y4 = (real_T (*)[16])cgxertGetOutputPortSignal
    (moduleInstance->S, 4);
  moduleInstance->y5 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 5);
  moduleInstance->y6 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 6);
  moduleInstance->y7 = (real_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 7);
  moduleInstance->y8 = (real_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 8);
  get_fF_P_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fF_P);
  get_fF_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fF_jacobian);
  get_fH_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_jacobian);
  get_fK_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fK);
  get_fH_nonlinear_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_nonlinear);
  get_fP_posteriori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_posteriori);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fStateVector_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fStateVector);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
}

/* CGXE Glue Code */
static void mdlOutputs_rZqx5kTDxqDFajBBDYHgfH(SimStruct *S, int_T tid)
{
  InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *moduleInstance =
    (InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_rZqx5kTDxqDFajBBDYHgfH(SimStruct *S)
{
  InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *moduleInstance =
    (InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_rZqx5kTDxqDFajBBDYHgfH(SimStruct *S, int_T tid)
{
  InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *moduleInstance =
    (InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_rZqx5kTDxqDFajBBDYHgfH(SimStruct *S)
{
  InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *moduleInstance =
    (InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_rZqx5kTDxqDFajBBDYHgfH(SimStruct *S)
{
  InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *moduleInstance =
    (InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_rZqx5kTDxqDFajBBDYHgfH(SimStruct *S)
{
  InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *moduleInstance =
    (InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_rZqx5kTDxqDFajBBDYHgfH(SimStruct *S)
{
  InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *moduleInstance =
    (InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_rZqx5kTDxqDFajBBDYHgfH(SimStruct *S)
{
  InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *moduleInstance =
    (InstanceStruct_rZqx5kTDxqDFajBBDYHgfH *)calloc(1, sizeof
    (InstanceStruct_rZqx5kTDxqDFajBBDYHgfH));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_rZqx5kTDxqDFajBBDYHgfH);
  ssSetmdlInitializeConditions(S, mdlInitialize_rZqx5kTDxqDFajBBDYHgfH);
  ssSetmdlUpdate(S, mdlUpdate_rZqx5kTDxqDFajBBDYHgfH);
  ssSetmdlDerivatives(S, mdlDerivatives_rZqx5kTDxqDFajBBDYHgfH);
  ssSetmdlTerminate(S, mdlTerminate_rZqx5kTDxqDFajBBDYHgfH);
  ssSetmdlEnable(S, mdlEnable_rZqx5kTDxqDFajBBDYHgfH);
  ssSetmdlDisable(S, mdlDisable_rZqx5kTDxqDFajBBDYHgfH);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_rZqx5kTDxqDFajBBDYHgfH(SimStruct *S)
{
}

void method_dispatcher_rZqx5kTDxqDFajBBDYHgfH(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_rZqx5kTDxqDFajBBDYHgfH(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_rZqx5kTDxqDFajBBDYHgfH(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: rZqx5kTDxqDFajBBDYHgfH.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_rZqx5kTDxqDFajBBDYHgfH_BuildInfoUpdate(void)
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

mxArray *cgxe_rZqx5kTDxqDFajBBDYHgfH_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fF_P");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}