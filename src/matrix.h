float** create_matrix(int n, int m);
void free_matrix(float** matrix, int n);
float** broadcast(float** matrix, int r1, int r2, int c1, int c2, float** result);
void print_matrix(float** matrix, int rows, int cols);
int matrices_equal(float** m1, float** m2, int rows, int cols, float epsilon);
float** add(float** m1, float** m2, float** result, int n, int m);
