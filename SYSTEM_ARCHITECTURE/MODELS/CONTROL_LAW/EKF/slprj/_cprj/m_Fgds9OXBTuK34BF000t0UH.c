/* Include files */

#include "modelInterface.h"
#include "m_Fgds9OXBTuK34BF000t0UH.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_Fgds9OXBTuK34BF000t0UH *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_Fgds9OXBTuK34BF000t0UH *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->fF_jacobian)[i][b_i] = (*moduleInstance->u2)[i + (b_i <<
        3)];
      (*moduleInstance->fP_posteriori)[i][b_i] = (*moduleInstance->u3)[i + (b_i <<
        3)];
    }

    (*moduleInstance->fStateVector)[i] = (*moduleInstance->u4)[i];
  }

  PredictionStep_JDx5nLslLg2PR6bPJ2PDCE(*moduleInstance->u0, *moduleInstance->u1);
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->b_y0)[b_i + (i << 3)] = (*moduleInstance->fP_priori)[b_i]
        [i];
    }

    (*moduleInstance->b_y1)[i] = (*moduleInstance->fX_hat_priori)[i];
  }
}

static void cgxe_mdl_update(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_Fgds9OXBTuK34BF000t0UH
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real_T (*)[64])cgxertGetInputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->u3 = (real_T (*)[64])cgxertGetInputPortSignal
    (moduleInstance->S, 3);
  moduleInstance->u4 = (real_T (*)[8])cgxertGetInputPortSignal(moduleInstance->S,
    4);
  moduleInstance->b_y0 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  get_fF_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fF_jacobian);
  get_fP_posteriori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_posteriori);
  get_fStateVector_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fStateVector);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
}

/* CGXE Glue Code */
static void mdlOutputs_Fgds9OXBTuK34BF000t0UH(SimStruct *S, int_T tid)
{
  InstanceStruct_Fgds9OXBTuK34BF000t0UH *moduleInstance =
    (InstanceStruct_Fgds9OXBTuK34BF000t0UH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_Fgds9OXBTuK34BF000t0UH(SimStruct *S)
{
  InstanceStruct_Fgds9OXBTuK34BF000t0UH *moduleInstance =
    (InstanceStruct_Fgds9OXBTuK34BF000t0UH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_Fgds9OXBTuK34BF000t0UH(SimStruct *S, int_T tid)
{
  InstanceStruct_Fgds9OXBTuK34BF000t0UH *moduleInstance =
    (InstanceStruct_Fgds9OXBTuK34BF000t0UH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_Fgds9OXBTuK34BF000t0UH(SimStruct *S)
{
  InstanceStruct_Fgds9OXBTuK34BF000t0UH *moduleInstance =
    (InstanceStruct_Fgds9OXBTuK34BF000t0UH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_Fgds9OXBTuK34BF000t0UH(SimStruct *S)
{
  InstanceStruct_Fgds9OXBTuK34BF000t0UH *moduleInstance =
    (InstanceStruct_Fgds9OXBTuK34BF000t0UH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_Fgds9OXBTuK34BF000t0UH(SimStruct *S)
{
  InstanceStruct_Fgds9OXBTuK34BF000t0UH *moduleInstance =
    (InstanceStruct_Fgds9OXBTuK34BF000t0UH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_Fgds9OXBTuK34BF000t0UH(SimStruct *S)
{
  InstanceStruct_Fgds9OXBTuK34BF000t0UH *moduleInstance =
    (InstanceStruct_Fgds9OXBTuK34BF000t0UH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_Fgds9OXBTuK34BF000t0UH(SimStruct *S)
{
  InstanceStruct_Fgds9OXBTuK34BF000t0UH *moduleInstance =
    (InstanceStruct_Fgds9OXBTuK34BF000t0UH *)calloc(1, sizeof
    (InstanceStruct_Fgds9OXBTuK34BF000t0UH));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_Fgds9OXBTuK34BF000t0UH);
  ssSetmdlInitializeConditions(S, mdlInitialize_Fgds9OXBTuK34BF000t0UH);
  ssSetmdlUpdate(S, mdlUpdate_Fgds9OXBTuK34BF000t0UH);
  ssSetmdlDerivatives(S, mdlDerivatives_Fgds9OXBTuK34BF000t0UH);
  ssSetmdlTerminate(S, mdlTerminate_Fgds9OXBTuK34BF000t0UH);
  ssSetmdlEnable(S, mdlEnable_Fgds9OXBTuK34BF000t0UH);
  ssSetmdlDisable(S, mdlDisable_Fgds9OXBTuK34BF000t0UH);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_Fgds9OXBTuK34BF000t0UH(SimStruct *S)
{
}

void method_dispatcher_Fgds9OXBTuK34BF000t0UH(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_Fgds9OXBTuK34BF000t0UH(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_Fgds9OXBTuK34BF000t0UH(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: Fgds9OXBTuK34BF000t0UH.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_Fgds9OXBTuK34BF000t0UH_BuildInfoUpdate(void)
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

mxArray *cgxe_Fgds9OXBTuK34BF000t0UH_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fF_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
