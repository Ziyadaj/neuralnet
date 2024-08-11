#include "matmul.h"
#include "matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(x, y) ((x) > (y) ? (x) : (y))
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
void forward(float **x, int n, int k, int m);

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
float relu(float output) { return max(0, output); } // fmaxf
float sigmoid(float z) { return 1 / (1 + exp(-z)); }

void forward(float **x, int n, int k, int m) {
  // weight and bias initialization
  float **weights = rand_init(n, m);
  float **bias = rand_init(m, 1);

  printf("bias:\n");
  print_matrix(bias, m, 1);

  // forward pass
  float **output = create_matrix(n, m);
  output = matmul_naive(x, weights, output, k, n, n, m);
  printf("matmul:\n");
  print_matrix(output, n, m);
  float **tr = transpose(bias, m, 1);
  if (tr == NULL) {
    // Handle error
    printf("Null ptr at tr");
    return;
  }
  float **bias_br = broadcast(tr, m, n, 1, m);
  if (bias_br == NULL) {
    // Handle error
    printf("Null ptr at bias_br");
    return;
  }
  printf("bias broadcast:\n");
  print_matrix(bias_br, m, n);
  output = matadd(output, bias_br, n, m);
  printf("output:\n");
  print_matrix(output, n, m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      output[i][j] = sigmoid(output[i][j]);
    }
  }
  printf("output:\n");
  print_matrix(output, n, m);
}
void read_file(char name[]) {}

int main() {
  srand(time(NULL)); // random seed
  // dim setting
  int features = 4, samples = 3, hidden_size = 5;

  // float --> 32bit decimal

  float **x = rand_init(samples, features);
  forward(x, samples, features, hidden_size);
  return 0;
}
