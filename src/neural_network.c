#include "matmul.h"
#include "matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// can I make transformer? --> learn llm.c from karpathy

// [] input
// [] loss fun
// [] grads
// [x] vectors for handling weights and bias

float rand_float();
float **zero_init(int n, int m);
float **rand_init(int n, int m);
float relu(float output);
float sigmoid(float z);
int layers(float **input, float **weights, float **bias, int input_shape,
           int hidden_size);

float rand_float() { return ((float)rand() / (float)RAND_MAX); }

float **zero_init(int n, int m) {
  float **matrix = create_matrix(n, m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = 0;
    }
  }
  return matrix;
}
float **rand_init(int n, int m) {
  float **matrix = create_matrix(n, m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = rand_float();
    }
  }
  return matrix;
}
// activation function
float relu(float output) { return fmaxf(0, output); }
float sigmoid(float z) { return 1 / (1 + exp(-z)); }

int layers(float **input, float **weights, float **bias, int input_shape,
           int hidden_size) {
  float **output = create_matrix(input_shape, hidden_size);

  printf("Bias:\n");
  print_matrix(bias, hidden_size, 1);

  output = matmul_naive(input, weights, output, input_shape, input_shape,
                        input_shape, hidden_size);
  printf("Matmul:\n");
  print_matrix(output, input_shape, hidden_size);
  output = broadcast_add(output, bias, output, input_shape, hidden_size);
  printf("Bias + matmul:\n");
  print_matrix(output, input_shape, hidden_size);
  // m x k * k x n = m x n + n x 1

  for (int i = 0; i < input_shape; i++) {
    for (int j = 0; j < hidden_size; j++) {
      output[i][j] = sigmoid(output[i][j]);
    }
  }
  printf("sigmoid:\n");
  print_matrix(output, input_shape, hidden_size);
  // Free the allocated memory
  free_matrix(weights, input_shape);
  free_matrix(bias, hidden_size);
  return 0;
}
int main() {
  // dim setting
  int input_shape = 3, hidden_size = 4;

  // float --> 32bit decimal

  srand(time(NULL)); // random seed

  // hidden_size = neuron count
  float **weights = rand_init(input_shape, hidden_size);
  float **bias = zero_init(hidden_size, 1);
  float **input = rand_init(input_shape, input_shape);
  print_matrix(input, input_shape, input_shape);
  print_matrix(weights, input_shape, hidden_size);
  printf("\n");
  layers(input, weights, bias, input_shape, hidden_size);
  return 0;
}
