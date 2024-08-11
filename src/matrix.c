#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float **create_matrix(int n, int m);
void free_matrix(float **A, int n);
float **broadcast(float **A, int from_rows, int to_rows, int from_cols,
                  int to_cols);
float **transpose(float **A, int rows, int cols);
void print_matrix(float **A, int rows, int cols);
int matrices_equal(float **m1, float **m2, int rows, int cols, float epsilon);
float **matadd(float **m1, float **m2, int n, int m);

float **create_matrix(int n, int m) {
  float **A = (float **)malloc(n * sizeof(float *));
  if (A == NULL)
    return NULL;
  for (int i = 0; i < n; i++) {
    A[i] = (float *)malloc(m * sizeof(float));
    if (A[i] == NULL) {
      free_matrix(A, n);
      return NULL;
    }
  }
  return A;
}
void free_matrix(float **A, int n) {
  if (A == NULL)
    return;
  // Free the allocated memory
  for (int i = 0; i < n; i++) {
    free(A[i]);
  }
  free(A);
  A = NULL;
}
float **transpose(float **A, int rows, int cols) {
  float **ptr = create_matrix(cols, rows);
  if (ptr == NULL) {
    return NULL;
  }
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      ptr[j][i] = A[i][j];
    }
  }
  print_matrix(A, rows, cols);
  print_matrix(ptr, rows, cols);
  return ptr;
}
float **broadcast(float **A, int from_rows, int to_rows, int from_cols,
                  int to_cols) {
  // If no broadcasting is needed, return the original array
  if (from_rows == to_rows && from_cols == to_cols) {
    return A;
  }

  float **B = create_matrix(to_rows, to_cols);
  if (B == NULL) {
    printf("NULL");
    return NULL;
  }
  // Check if broadcasting is possible
  if ((from_rows != 1 && from_rows != to_rows) ||
      (from_cols != 1 && from_cols != to_cols)) {
    printf("Error: Cannot broadcast from (%d,%d) to (%d,%d)\n", from_rows,
           from_cols, to_rows, to_cols);
    free_matrix(B, to_rows);
    return NULL;
  }
  for (int i = 0; i < to_rows; i++) {
    int row_index = i % from_rows;
    for (int j = 0; j < to_cols; j++) {
      int col_index = j % from_cols;
      B[i][j] = A[row_index][col_index];
    }
  }
  return B;
}

float **matadd(float **A, float **B, int rows, int cols) {
  float **C = create_matrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  return C;
}
void print_matrix(float **A, int rows, int cols) {
  printf("[%d, %d]\n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%.3f ", A[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Helper function to check if two matrices are equal within a small epsilon
int matrices_equal(float **A, float **B, int rows, int cols, float epsilon) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (fabs(A[i][j] - B[i][j]) > epsilon) {
        return 0;
      }
    }
  }
  return 1;
}
