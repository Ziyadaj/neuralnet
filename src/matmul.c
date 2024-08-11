#include <stdio.h>
float **matmul_naive(float **A, float **B, float **result, int R1, int R2,
                     int C1, int C2) {
  if (R2 != C1) {
    printf("unable to multiply: [%d, %d] * [%d, %d]\n", R1, C1, R2, C2);
    return NULL;
  }
  printf("matrix mul [%d, %d] * [%d, %d]\n", R1, C1, R2, C2);
  for (int i = 0; i < R1; i++) {
    for (int j = 0; j < C2; j++) {
      result[i][j] = 0;

      for (int k = 0; k < R2; k++) {
        result[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return result;
}
