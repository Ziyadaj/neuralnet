#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// can I make transformer? --> learn llm.c from karpathy


// input
// loss fun
// grads
// vectors for handling weights and bias 


float rand_float(){
    return ((float) rand() / (float)RAND_MAX);
}

float** matrix(int n, int m){
    float** arr = (float**)malloc(n * sizeof(float*));

    for(int i = 0; i < n; i++){
        arr[i] = (float*)malloc(m * sizeof(float));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = rand_float();
        }
    }
    return arr;
}

int main(){
    // dim setting
    // float --> 32bit decimal
    
    srand(time(NULL)); // random seed

    int n = 3, m = 4;
    float** weights = matrix(n, m);
    float** bias = matrix(n, m);
    
    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%f ", weights[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(weights[i]);
    }
    free(weights);

    return 0;
}
