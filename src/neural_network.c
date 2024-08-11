#include "../include/matrix.h"
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
__attribute__((unused))

float relu(float output) {
  return max(0, output);
} // fmaxf
float sigmoid(float z) { return 1 / (1 + exp(-z)); }

// log loss
__attribute__((unused)) float loss_func(float **output, float **real, int n,
                                        int m) {
  float loss = 0.0f;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      loss += real[i][j] * log(output[i][j]) +
              (1 - real[i][j]) * log(1 - output[i][j]);
    }
  }
  return loss;
}
float **grads(float **A, int n, int m) {
  // get grads from chain rule
}
// need derivatives of dw, db
// log loss -> w or b
// dL/dw and dL/db and f'(z)
// y*log(yhat) + * (1-y) * log(1-yhat)
// yhat = f(z) = f(a * w + b)
// f'(z) = 1-f(z) * f(z) (sigmoid)
//
// chain rule dL/da = dL/dz * dz/da
// dL/da =
void backprop(float **weights, float **bias, float lr, int n, int k, int m) {
  float **dw = create_matrix(n, m);
  float **db = create_matrix(1, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; i++) {

      weights[i][j] -= lr * dw;
      bias[0][j] -= lr * db;
    }
  }
}

void forward(float **x, int n, int k, int m) {
  // weight and bias initialization
  float **weights = rand_init(n, m);
  float **bias = zero_init(1, m);

  // forward pass
  float **output = create_matrix(k, m);
  output = matmul_naive(x, weights, output, k, n, n, m);
  float **bias_br = broadcast(bias, 1, k, m, m);
  output = matadd(output, bias_br, k, m);

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      output[i][j] = sigmoid(output[i][j]);
    }
  }
}
__attribute__((unused)) void read_file(char name[]) {}

#ifndef TESTING
int main() {
  srand(time(NULL)); // random seed
  // dim setting
  int features = 4, samples = 7, hidden_size = 5;

  // float --> 32bit decimal

  float **x = rand_init(samples, features);
  forward(x, features, samples, hidden_size);
  return 0;
}
#endif
