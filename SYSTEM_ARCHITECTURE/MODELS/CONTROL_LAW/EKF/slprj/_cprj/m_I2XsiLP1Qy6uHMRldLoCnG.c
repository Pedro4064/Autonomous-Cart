/* Include files */

#include "modelInterface.h"
#include "m_I2XsiLP1Qy6uHMRldLoCnG.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance)
{
  int32_T i;
  int32_T i1;
  for (i = 0; i < 8; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->fF_jacobian)[i][i1] = (*moduleInstance->u0)[i + (i1 << 3)];
      (*moduleInstance->fP_posteriori)[i][i1] = (*moduleInstance->u1)[i + (i1 <<
        3)];
    }
  }

  vEstimationSystemEkfPredict_JDx5nLslLg2PR6bPJ2PDCE();
  for (i = 0; i < 8; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->b_y0)[i1 + (i << 3)] = (*moduleInstance->fP_priori)[i1]
        [i];
    }
  }
}

static void cgxe_mdl_update(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T (*)[64])cgxertGetInputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->u1 = (real_T (*)[64])cgxertGetInputPortSignal
    (moduleInstance->S, 1);
  moduleInstance->b_y0 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  get_fF_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fF_jacobian);
  get_fP_posteriori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_posteriori);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
}

/* CGXE Glue Code */
static void mdlOutputs_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S, int_T tid)
{
  InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *moduleInstance =
    (InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S)
{
  InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *moduleInstance =
    (InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S, int_T tid)
{
  InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *moduleInstance =
    (InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S)
{
  InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *moduleInstance =
    (InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S)
{
  InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *moduleInstance =
    (InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S)
{
  InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *moduleInstance =
    (InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S)
{
  InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *moduleInstance =
    (InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S)
{
  InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *moduleInstance =
    (InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG *)calloc(1, sizeof
    (InstanceStruct_I2XsiLP1Qy6uHMRldLoCnG));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_I2XsiLP1Qy6uHMRldLoCnG);
  ssSetmdlInitializeConditions(S, mdlInitialize_I2XsiLP1Qy6uHMRldLoCnG);
  ssSetmdlUpdate(S, mdlUpdate_I2XsiLP1Qy6uHMRldLoCnG);
  ssSetmdlDerivatives(S, mdlDerivatives_I2XsiLP1Qy6uHMRldLoCnG);
  ssSetmdlTerminate(S, mdlTerminate_I2XsiLP1Qy6uHMRldLoCnG);
  ssSetmdlEnable(S, mdlEnable_I2XsiLP1Qy6uHMRldLoCnG);
  ssSetmdlDisable(S, mdlDisable_I2XsiLP1Qy6uHMRldLoCnG);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S)
{
}

void method_dispatcher_I2XsiLP1Qy6uHMRldLoCnG(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_I2XsiLP1Qy6uHMRldLoCnG(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_I2XsiLP1Qy6uHMRldLoCnG(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: I2XsiLP1Qy6uHMRldLoCnG.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_I2XsiLP1Qy6uHMRldLoCnG_BuildInfoUpdate(void)
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

mxArray *cgxe_I2XsiLP1Qy6uHMRldLoCnG_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fF_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
