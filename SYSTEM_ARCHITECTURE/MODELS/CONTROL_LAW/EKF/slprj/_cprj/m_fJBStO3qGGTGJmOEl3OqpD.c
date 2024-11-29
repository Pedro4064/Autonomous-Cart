/* Include files */

#include "modelInterface.h"
#include "m_fJBStO3qGGTGJmOEl3OqpD.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
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
    for (i1 = 0; i1 < 2; i1++) {
      (*moduleInstance->fK)[i][i1] = (*moduleInstance->u1)[i + (i1 << 3)];
    }

    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->fP_priori)[i][i1] = (*moduleInstance->u2)[i + (i1 << 3)];
    }
  }

  vEstimationSystemCalculatePposteriori_JDx5nLslLg2PR6bPJ2PDCE();
  for (i = 0; i < 8; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      (*moduleInstance->b_y0)[i1 + (i << 3)] = (*moduleInstance->fP_posteriori)
        [i1][i];
    }
  }
}

static void cgxe_mdl_update(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_fJBStO3qGGTGJmOEl3OqpD
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T (*)[16])cgxertGetInputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->u1 = (real_T (*)[16])cgxertGetInputPortSignal
    (moduleInstance->S, 1);
  moduleInstance->u2 = (real_T (*)[64])cgxertGetInputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->b_y0 = (real_T (*)[64])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  get_fH_jacobian_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fH_jacobian);
  get_fK_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fK);
  get_fP_priori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_priori);
  get_fP_posteriori_addr_JDx5nLslLg2PR6bPJ2PDCE(&moduleInstance->fP_posteriori);
}

/* CGXE Glue Code */
static void mdlOutputs_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S, int_T tid)
{
  InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *moduleInstance =
    (InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S)
{
  InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *moduleInstance =
    (InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S, int_T tid)
{
  InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *moduleInstance =
    (InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S)
{
  InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *moduleInstance =
    (InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S)
{
  InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *moduleInstance =
    (InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S)
{
  InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *moduleInstance =
    (InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S)
{
  InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *moduleInstance =
    (InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S)
{
  InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *moduleInstance =
    (InstanceStruct_fJBStO3qGGTGJmOEl3OqpD *)calloc(1, sizeof
    (InstanceStruct_fJBStO3qGGTGJmOEl3OqpD));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_fJBStO3qGGTGJmOEl3OqpD);
  ssSetmdlInitializeConditions(S, mdlInitialize_fJBStO3qGGTGJmOEl3OqpD);
  ssSetmdlUpdate(S, mdlUpdate_fJBStO3qGGTGJmOEl3OqpD);
  ssSetmdlDerivatives(S, mdlDerivatives_fJBStO3qGGTGJmOEl3OqpD);
  ssSetmdlTerminate(S, mdlTerminate_fJBStO3qGGTGJmOEl3OqpD);
  ssSetmdlEnable(S, mdlEnable_fJBStO3qGGTGJmOEl3OqpD);
  ssSetmdlDisable(S, mdlDisable_fJBStO3qGGTGJmOEl3OqpD);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S)
{
}

void method_dispatcher_fJBStO3qGGTGJmOEl3OqpD(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_fJBStO3qGGTGJmOEl3OqpD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_fJBStO3qGGTGJmOEl3OqpD(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: fJBStO3qGGTGJmOEl3OqpD.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_fJBStO3qGGTGJmOEl3OqpD_BuildInfoUpdate(void)
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

mxArray *cgxe_fJBStO3qGGTGJmOEl3OqpD_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleVar");
  mxArray* incompatibleSymbol = mxCreateString("Outputs: fH_jacobian");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
