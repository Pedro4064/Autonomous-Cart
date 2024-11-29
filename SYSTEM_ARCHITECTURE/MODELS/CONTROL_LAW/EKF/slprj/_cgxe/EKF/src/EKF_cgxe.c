/* Include files */

#include "EKF_cgxe.h"
#include "m_27wqBI6QE46o806cHajbQD.h"

unsigned int cgxe_EKF_method_dispatcher(SimStruct* S, int_T method, void* data)
{
  if (ssGetChecksum0(S) == 249213380 &&
      ssGetChecksum1(S) == 3844013012 &&
      ssGetChecksum2(S) == 3640423531 &&
      ssGetChecksum3(S) == 1253660043) {
    method_dispatcher_27wqBI6QE46o806cHajbQD(S, method, data);
    return 1;
  }

  return 0;
}
