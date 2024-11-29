/* Include files */

#include "modelInterface.h"
#include "m_4SmufPcCasiL6eRHBQwKOF.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_4SmufPcCasiL6eRHBQwKOF *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_4SmufPcCasiL6eRHBQwKOF *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
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
    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->fP_priori)[i][i1] = (*moduleInstance->u1)[i + (i1 << 3)];
    }
  }

  vEstimationSYstemCalculateK_JDx5nLslLg2PR6bPJ2PDCE();
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->b_y0)[i1 + (i << 3)] = (*moduleInstance->fK)[i1][i];
    }
  }

  for (i = 0; i < 8; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->b_y1)[i1 + (i << 3)] = (*moduleInstance->fP_priori)[i1]
        [i];
    }
  }
}

static void cgxe_mdl_update(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_4SmufPcCasiL6eRHBQwKOF
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real32_T (*)[16])cgxertGetInputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->u1 = (real32_T (*)[64])cgxertGetInputPortSignal
    (moduleInstance->S, 1);
  moduleInstance->b_y0 = (real32_T (*)[16])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real32_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
  get_fH_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_jacobian);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fK_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fK);
}

/* CGXE Glue Code */
static void mdlOutputs_4SmufPcCasiL6eRHBQwKOF(SimStruct *S, int_T tid)
{
  InstanceStruct_4SmufPcCasiL6eRHBQwKOF *moduleInstance =
    (InstanceStruct_4SmufPcCasiL6eRHBQwKOF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_4SmufPcCasiL6eRHBQwKOF(SimStruct *S)
{
  InstanceStruct_4SmufPcCasiL6eRHBQwKOF *moduleInstance =
    (InstanceStruct_4SmufPcCasiL6eRHBQwKOF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_4SmufPcCasiL6eRHBQwKOF(SimStruct *S, int_T tid)
{
  InstanceStruct_4SmufPcCasiL6eRHBQwKOF *moduleInstance =
    (InstanceStruct_4SmufPcCasiL6eRHBQwKOF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_4SmufPcCasiL6eRHBQwKOF(SimStruct *S)
{
  InstanceStruct_4SmufPcCasiL6eRHBQwKOF *moduleInstance =
    (InstanceStruct_4SmufPcCasiL6eRHBQwKOF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_4SmufPcCasiL6eRHBQwKOF(SimStruct *S)
{
  InstanceStruct_4SmufPcCasiL6eRHBQwKOF *moduleInstance =
    (InstanceStruct_4SmufPcCasiL6eRHBQwKOF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_4SmufPcCasiL6eRHBQwKOF(SimStruct *S)
{
  InstanceStruct_4SmufPcCasiL6eRHBQwKOF *moduleInstance =
    (InstanceStruct_4SmufPcCasiL6eRHBQwKOF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_4SmufPcCasiL6eRHBQwKOF(SimStruct *S)
{
  InstanceStruct_4SmufPcCasiL6eRHBQwKOF *moduleInstance =
    (InstanceStruct_4SmufPcCasiL6eRHBQwKOF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_4SmufPcCasiL6eRHBQwKOF(SimStruct *S)
{
  InstanceStruct_4SmufPcCasiL6eRHBQwKOF *moduleInstance =
    (InstanceStruct_4SmufPcCasiL6eRHBQwKOF *)calloc(1, sizeof
    (InstanceStruct_4SmufPcCasiL6eRHBQwKOF));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_4SmufPcCasiL6eRHBQwKOF);
  ssSetmdlInitializeConditions(S, mdlInitialize_4SmufPcCasiL6eRHBQwKOF);
  ssSetmdlUpdate(S, mdlUpdate_4SmufPcCasiL6eRHBQwKOF);
  ssSetmdlDerivatives(S, mdlDerivatives_4SmufPcCasiL6eRHBQwKOF);
  ssSetmdlTerminate(S, mdlTerminate_4SmufPcCasiL6eRHBQwKOF);
  ssSetmdlEnable(S, mdlEnable_4SmufPcCasiL6eRHBQwKOF);
  ssSetmdlDisable(S, mdlDisable_4SmufPcCasiL6eRHBQwKOF);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_4SmufPcCasiL6eRHBQwKOF(SimStruct *S)
{
}

void method_dispatcher_4SmufPcCasiL6eRHBQwKOF(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_4SmufPcCasiL6eRHBQwKOF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_4SmufPcCasiL6eRHBQwKOF(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: 4SmufPcCasiL6eRHBQwKOF.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_4SmufPcCasiL6eRHBQwKOF_BuildInfoUpdate(void)
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

mxArray *cgxe_4SmufPcCasiL6eRHBQwKOF_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fH_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
