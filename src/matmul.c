#include <stdio.h>
float** matmul_naive(float** m1, float** m2, float** result, int r1, int r2, int c1, int c2){
    if (r2 != c1) {
        printf("unable to multiply: [%d, %d] * [%d, %d]\n", r1,c1,r2,c2);
        return NULL;      
    }
    printf("matrix mul [%d, %d] * [%d, %d]\n", r1,c1,r2,c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
                result[i][j] = 0;
 
            for (int k = 0; k < r2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}
