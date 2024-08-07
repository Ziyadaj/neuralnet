#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float **create_matrix(int n, int m);
void free_matrix(float **matrix, int n);
float **broadcast(float **matrix, int r1, int r2, int c1, int c2,
                  float **result);
void print_matrix(float **matrix, int rows, int cols);
int matrices_equal(float **m1, float **m2, int rows, int cols, float epsilon);
float **add(float **m1, float **m2, float **result, int n, int m);

float **create_matrix(int n, int m) {
  float **matrix = (float **)malloc(n * sizeof(float *));
  if (matrix == NULL)
    return NULL;
  for (int i = 0; i < n; i++) {
    matrix[i] = (float *)malloc(m * sizeof(float));
    if (matrix[i] == NULL) {
      free_matrix(matrix, n);
      return NULL;
    }
  }
  return matrix;
}
void free_matrix(float **matrix, int n) {
  if (matrix == NULL)
    return;
  // Free the allocated memory
  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);
  matrix = NULL;
}
float **broadcast(float **matrix, int r1, int r2, int c1, int c2,
                  float **result) {
  if (r1 > r2) {
    // is this enough? what about c1!=c2
    // result = (float*)realloc(matrix, (r1-r2) * sizeof(float));
    return result;
  }
  // result = (float*)realloc(matrix, (r2-r1) * sizeof(float));
  return result;
}

float **broadcast_add(float **m1, float **m2, float **result, int n, int m) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      result[i][j] = m1[i][j] + m2[j][0];
    }
  }
  return result;
}

void print_matrix(float **matrix, int rows, int cols) {
  printf("[%d, %d]\n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%.6f ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Helper function to check if two matrices are equal within a small epsilon
int matrices_equal(float **m1, float **m2, int rows, int cols, float epsilon) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (fabs(m1[i][j] - m2[i][j]) > epsilon) {
        return 0;
      }
    }
  }
  return 1;
}
