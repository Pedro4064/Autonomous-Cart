/* Include files */

#include "modelInterface.h"
#include "m_YSxjq7RuYTmorY5oxgCAoB.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
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
}

static void cgxe_mdl_update(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_YSxjq7RuYTmorY5oxgCAoB
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
  get_fH_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_jacobian);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fK_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fK);
}

/* CGXE Glue Code */
static void mdlOutputs_YSxjq7RuYTmorY5oxgCAoB(SimStruct *S, int_T tid)
{
  InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *moduleInstance =
    (InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_YSxjq7RuYTmorY5oxgCAoB(SimStruct *S)
{
  InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *moduleInstance =
    (InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_YSxjq7RuYTmorY5oxgCAoB(SimStruct *S, int_T tid)
{
  InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *moduleInstance =
    (InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_YSxjq7RuYTmorY5oxgCAoB(SimStruct *S)
{
  InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *moduleInstance =
    (InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_YSxjq7RuYTmorY5oxgCAoB(SimStruct *S)
{
  InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *moduleInstance =
    (InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_YSxjq7RuYTmorY5oxgCAoB(SimStruct *S)
{
  InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *moduleInstance =
    (InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_YSxjq7RuYTmorY5oxgCAoB(SimStruct *S)
{
  InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *moduleInstance =
    (InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_YSxjq7RuYTmorY5oxgCAoB(SimStruct *S)
{
  InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *moduleInstance =
    (InstanceStruct_YSxjq7RuYTmorY5oxgCAoB *)calloc(1, sizeof
    (InstanceStruct_YSxjq7RuYTmorY5oxgCAoB));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_YSxjq7RuYTmorY5oxgCAoB);
  ssSetmdlInitializeConditions(S, mdlInitialize_YSxjq7RuYTmorY5oxgCAoB);
  ssSetmdlUpdate(S, mdlUpdate_YSxjq7RuYTmorY5oxgCAoB);
  ssSetmdlDerivatives(S, mdlDerivatives_YSxjq7RuYTmorY5oxgCAoB);
  ssSetmdlTerminate(S, mdlTerminate_YSxjq7RuYTmorY5oxgCAoB);
  ssSetmdlEnable(S, mdlEnable_YSxjq7RuYTmorY5oxgCAoB);
  ssSetmdlDisable(S, mdlDisable_YSxjq7RuYTmorY5oxgCAoB);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_YSxjq7RuYTmorY5oxgCAoB(SimStruct *S)
{
}

void method_dispatcher_YSxjq7RuYTmorY5oxgCAoB(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_YSxjq7RuYTmorY5oxgCAoB(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_YSxjq7RuYTmorY5oxgCAoB(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: YSxjq7RuYTmorY5oxgCAoB.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_YSxjq7RuYTmorY5oxgCAoB_BuildInfoUpdate(void)
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

mxArray *cgxe_YSxjq7RuYTmorY5oxgCAoB_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fH_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
