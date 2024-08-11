float **create_matrix(int n, int m);
void free_matrix(float **matrix, int n);
float **broadcast(float **A, int from_rows, int to_rows, int from_cols,
                  int to_cols);
void print_matrix(float **matrix, int rows, int cols);
int matrices_equal(float **m1, float **m2, int rows, int cols, float epsilon);
float **matadd(float **m1, float **m2, int n, int m);
float **matmul_naive(float **m1, float **m2, float **result, int R1, int R2,
                     int C1, int C2);
