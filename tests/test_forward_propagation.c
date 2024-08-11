#include "../include/matrix.h"
#include "../include/neural_network.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Test rand_init function
void test_rand_init() {
  int rows = 3, cols = 4;
  float **result = rand_init(rows, cols);
  assert(result != NULL);
  // Check if values are within expected range (e.g., 0 to 1)
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      assert(result[i][j] >= 0 && result[i][j] <= 1);
    }
  }
  // Free memory
  for (int i = 0; i < rows; i++) {
    free(result[i]);
  }
  free(result);
  printf("test_rand_init passed\n");
}

// Test matmul_naive function
void test_matmul_naive() {
  float **a = create_matrix(2, 3);
  float **b = create_matrix(3, 2);
  float **c = create_matrix(2, 2);
  float **expected = create_matrix(2, 2);

  // Initialize matrices
  a[0][0] = 1;
  a[0][1] = 2;
  a[0][2] = 3;
  a[1][0] = 4;
  a[1][1] = 5;
  a[1][2] = 6;

  b[0][0] = 7;
  b[0][1] = 8;
  b[1][0] = 9;
  b[1][1] = 10;
  b[2][0] = 11;
  b[2][1] = 12;

  expected[0][0] = 58;
  expected[0][1] = 64;
  expected[1][0] = 139;
  expected[1][1] = 154;

  c = matmul_naive(a, b, c, 2, 3, 3, 2);
  assert(matrices_equal(c, expected, 2, 2, 1e-6));

  // Free memory
  for (int i = 0; i < 2; i++) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
    free(expected[i]);
  }
  free(a);
  free(b);
  free(c);
  free(expected);
  printf("test_matmul_naive passed\n");
}

// Test broadcast function
void test_broadcast() {
  float **original = create_matrix(1, 2);
  original[0][0] = 1;
  original[0][1] = 2;

  float **result = broadcast(original, 1, 3, 2, 2);
  assert(result != NULL);

  float **expected = create_matrix(3, 2);
  for (int i = 0; i < 3; i++) {
    expected[i][0] = 1;
    expected[i][1] = 2;
  }

  assert(matrices_equal(result, expected, 3, 2, 1e-6));

  // Free memory
  free(original[0]);
  free(original);
  for (int i = 0; i < 3; i++) {
    free(result[i]);
    free(expected[i]);
  }
  free(result);
  free(expected);
  printf("test_broadcast passed\n");
}

// Test matadd function
void test_matadd() {
  float **a = create_matrix(2, 2);
  float **b = create_matrix(2, 2);
  float **expected = create_matrix(2, 2);

  a[0][0] = 1;
  a[0][1] = 2;
  a[1][0] = 3;
  a[1][1] = 4;

  b[0][0] = 5;
  b[0][1] = 6;
  b[1][0] = 7;
  b[1][1] = 8;

  expected[0][0] = 6;
  expected[0][1] = 8;
  expected[1][0] = 10;
  expected[1][1] = 12;

  float **result = matadd(a, b, 2, 2);
  assert(matrices_equal(result, expected, 2, 2, 1e-6));

  // Free memory
  for (int i = 0; i < 2; i++) {
    free(a[i]);
    free(b[i]);
    free(result[i]);
    free(expected[i]);
  }
  free(a);
  free(b);
  free(result);
  free(expected);
  printf("test_matadd passed\n");
}

// Test sigmoid function
void test_sigmoid() {
  assert(fabs(sigmoid(0) - 0.5) < 1e-6);
  assert(fabs(sigmoid(1) - 0.7310585786300049) < 1e-6);
  assert(fabs(sigmoid(-1) - 0.2689414213699951) < 1e-6);
  printf("test_sigmoid passed\n");
}

// Main function to run all tests
int main() {
  test_rand_init();
  test_matmul_naive();
  test_broadcast();
  test_matadd();
  test_sigmoid();
  printf("All tests passed!\n");
  return 0;
}
