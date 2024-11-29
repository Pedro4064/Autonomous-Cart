/* Include files */

#include "modelInterface.h"
#include "m_O0x0gGI2Fkm2XzjMviT0kE.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance)
{
  int32_T b_i;
  int32_T i;
  for (i = 0; i < 8; i++) {
    (*moduleInstance->fStateVector)[i] = (*moduleInstance->u2)[i];
  }

  vEstimationSystemComputeDynamicModel_JDx5nLslLg2PR6bPJ2PDCE
    (*moduleInstance->u0, *moduleInstance->u1);
  for (i = 0; i < 8; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      (*moduleInstance->b_y0)[b_i + (i << 3)] = (*moduleInstance->fF_jacobian)
        [b_i][i];
    }

    (*moduleInstance->b_y1)[i] = (*moduleInstance->fX_hat_priori)[i];
  }
}

static void cgxe_mdl_update(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real32_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real32_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real32_T (*)[8])cgxertGetInputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->b_y0 = (real32_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real32_T (*)[8])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  get_fStateVector_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fStateVector);
  get_fF_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fF_jacobian);
  get_fX_hat_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fX_hat_priori);
}

/* CGXE Glue Code */
static void mdlOutputs_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S, int_T tid)
{
  InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *moduleInstance =
    (InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S)
{
  InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *moduleInstance =
    (InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S, int_T tid)
{
  InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *moduleInstance =
    (InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S)
{
  InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *moduleInstance =
    (InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S)
{
  InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *moduleInstance =
    (InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S)
{
  InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *moduleInstance =
    (InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S)
{
  InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *moduleInstance =
    (InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S)
{
  InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *moduleInstance =
    (InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE *)calloc(1, sizeof
    (InstanceStruct_O0x0gGI2Fkm2XzjMviT0kE));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_O0x0gGI2Fkm2XzjMviT0kE);
  ssSetmdlInitializeConditions(S, mdlInitialize_O0x0gGI2Fkm2XzjMviT0kE);
  ssSetmdlUpdate(S, mdlUpdate_O0x0gGI2Fkm2XzjMviT0kE);
  ssSetmdlDerivatives(S, mdlDerivatives_O0x0gGI2Fkm2XzjMviT0kE);
  ssSetmdlTerminate(S, mdlTerminate_O0x0gGI2Fkm2XzjMviT0kE);
  ssSetmdlEnable(S, mdlEnable_O0x0gGI2Fkm2XzjMviT0kE);
  ssSetmdlDisable(S, mdlDisable_O0x0gGI2Fkm2XzjMviT0kE);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S)
{
}

void method_dispatcher_O0x0gGI2Fkm2XzjMviT0kE(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_O0x0gGI2Fkm2XzjMviT0kE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_O0x0gGI2Fkm2XzjMviT0kE(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: O0x0gGI2Fkm2XzjMviT0kE.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_O0x0gGI2Fkm2XzjMviT0kE_BuildInfoUpdate(void)
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

mxArray *cgxe_O0x0gGI2Fkm2XzjMviT0kE_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fF_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
