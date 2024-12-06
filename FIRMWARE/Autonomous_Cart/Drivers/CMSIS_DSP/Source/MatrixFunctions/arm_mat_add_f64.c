#include "arm_math.h"

arm_status arm_mat_add_f64(const arm_matrix_instance_f64 * pSrcA, const arm_matrix_instance_f64 * pSrcB, arm_matrix_instance_f64 * pDst){

float64_t *pInA = pSrcA->pData; /* input data matrix pointer A */
float64_t *pInB = pSrcB->pData; /* input data matrix pointer B */
float64_t *pOut = pDst->pData;  /* output data matrix pointer  */

uint64_t numSamples; /* total number of elements in the matrix */
uint64_t blkCnt;     /* loop counters */
arm_status status;   /* status of matrix addition */

#ifdef ARM_MATH_MATRIX_CHECK

/* Check for matrix mismatch condition */
if ((pSrcA->numRows != pSrcB->numRows) || (pSrcA->numCols != pSrcB->numCols) || (pSrcA->numRows != pDst->numRows) || (pSrcA->numCols != pDst->numCols)) {
status = ARM_MATH_SIZE_MISMATCH;
}
else

#endif /* #ifdef ARM_MATH_MATRIX_CHECK */

{
/* Total number of samples in input matrix */
numSamples = (uint64_t) pSrcA->numRows * pSrcA->numCols;

#if defined (ARM_MATH_LOOPUNROLL)

/* Loop unrolling: Compute 4 outputs at a time */
blkCnt = numSamples >> 2U;

while (blkCnt > 0U)
{
  /* C(m,n) = A(m,n) + B(m,n) */

  /* Add and store result in destination buffer. */
  *pOut++ = (*pInA++) + (*pInB++);
  *pOut++ = (*pInA++) + (*pInB++);
  *pOut++ = (*pInA++) + (*pInB++);
  *pOut++ = (*pInA++) + (*pInB++);

  /* Decrement loop counter */
  blkCnt--;
}

/* Loop unrolling: Compute remaining outputs */
blkCnt = numSamples % 0x4U;
#else

/* Initialize blkCnt with number of samples */
blkCnt = numSamples;
#endif /* #if defined (ARM_MATH_LOOPUNROLL) */

while (blkCnt > 0U)
{
  /* C(m,n) = A(m,n) + B(m,n) */

  /* Add and store result in destination buffer. */
  *pOut++ = (*pInA++) + (*pInB++);

  /* Decrement loop counter */
  blkCnt--;
}

/* Set status as ARM_MATH_SUCCESS */
status = ARM_MATH_SUCCESS;
}

/* Return to application */
return (status);
}

