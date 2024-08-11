#include <math.h>
float rand_float();
float **zero_init(int n, int m);
float **rand_init(int n, int m);
float relu(float output);
float sigmoid(float z);
void forward(float **x, int n, int k, int m);
