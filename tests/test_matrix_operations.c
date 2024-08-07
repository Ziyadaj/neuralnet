// Test case 1: Multiply two 2x2 matrices
static void test_2x2_multiplication() {
    float** m1 = matrix(2, 2);
    float** m2 = matrix(2, 2);
    float** result = matrix(2, 2);
    float** expected = matrix(2, 2);

    // Set known values
    m1[0][0] = 1; m1[0][1] = 2; m1[1][0] = 3; m1[1][1] = 4;
    m2[0][0] = 2; m2[0][1] = 0; m2[1][0] = 1; m2[1][1] = 3;

    // Expected result
    expected[0][0] = 4; expected[0][1] = 6; expected[1][0] = 10; expected[1][1] = 12;

    matmul_naive(m1, m2, result, 2, 2, 2, 2);

    printf("Test 2x2 Multiplication:\n");
    print_matrix(result, 2, 2);

    if (matrices_equal(result, expected, 2, 2, 0.000001)) {
        printf("Test Passed!\n\n");
    } else {
        printf("Test Failed!\n\n");
    }

    free_matrix(m1, 2);
    free_matrix(m2, 2);
    free_matrix(result, 2);
    free_matrix(expected, 2);
}

// Test case 2: Multiply a 2x3 matrix with a 3x2 matrix
static void test_2x3_3x2_multiplication() {
    float** m1 = matrix(2, 3);
    float** m2 = matrix(3, 2);
    float** result = matrix(2, 2);
    float** expected = matrix(2, 2);

    // Set known values
    m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
    m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;

    m2[0][0] = 7; m2[0][1] = 8;
    m2[1][0] = 9; m2[1][1] = 10;
    m2[2][0] = 11; m2[2][1] = 12;

    // Expected result
    expected[0][0] = 58; expected[0][1] = 64;
    expected[1][0] = 139; expected[1][1] = 154;

    matmul_naive(m1, m2, result, 2, 3, 3, 2);

    printf("Test 2x3 * 3x2 Multiplication:\n");
    print_matrix(result, 2, 2);

    if (matrices_equal(result, expected, 2, 2, 0.000001)) {
        printf("Test Passed!\n\n");
    } else {
        printf("Test Failed!\n\n");
    }

    free_matrix(m1, 2);
    free_matrix(m2, 3);
    free_matrix(result, 2);
    free_matrix(expected, 2);
}

// Test case 3: Attempt to multiply incompatible matrices
static void test_incompatible_matrices() {
    float** m1 = matrix(2, 3);
    float** m2 = matrix(2, 2);
    float** result = matrix(2, 2);

    printf("Test Incompatible Matrices:\n");
    float** res = matmul_naive(m1, m2, result, 2, 2, 3, 2);

    if (res == NULL) {
        printf("Test Passed! Correctly identified incompatible matrices.\n\n");
    } else {
        printf("Test Failed! Did not correctly handle incompatible matrices.\n\n");
    }

    free_matrix(m1, 2);
    free_matrix(m2, 2);
    free_matrix(result, 2);
}

// Test 1: Basic functionality
static void test_basic_add() {
    float** m1 = matrix(2, 2);
    float** bias = matrix(2, 1);
    float** result = matrix(2, 2);
    float** expected = matrix(2, 2);

    m1[0][0] = 1.0; m1[0][1] = 2.0;
    m1[1][0] = 3.0; m1[1][1] = 4.0;
    bias[0][0] = 0.1; bias[1][0] = 0.2;

    expected[0][0] = 1.1; expected[0][1] = 2.1;
    expected[1][0] = 3.2; expected[1][1] = 4.2;

    add(m1, bias, result, 2, 2);

    printf("Basic Add Test: %s\n", matrices_equal(result, expected, 2, 2, 0.0001) ? "PASSED" : "FAILED");

    free_matrix(m1, 2);
    free_matrix(bias, 2);
    free_matrix(result, 2);
    free_matrix(expected, 2);
}

// Test 2: Edge case - 1x1 matrix
static void test_1x1_add() {
    float** m1 = matrix(1, 1);
    float** bias = matrix(1, 1);
    float** result = matrix(1, 1);
    float** expected = matrix(1, 1);

    m1[0][0] = 5.0;
    bias[0][0] = 0.5;
    expected[0][0] = 5.5;

    add(m1, bias, result, 1, 1);

    printf("1x1 Matrix Add Test: %s\n", matrices_equal(result, expected, 1, 1, 0.0001) ? "PASSED" : "FAILED");

    free_matrix(m1, 1);
    free_matrix(bias, 1);
    free_matrix(result, 1);
    free_matrix(expected, 1);
}

// Test 3: Zero bias
static void test_zero_bias() {
    float** m1 = matrix(2, 2);
    float** bias = matrix(2, 1);
    float** result = matrix(2, 2);

    m1[0][0] = 1.0; m1[0][1] = 2.0;
    m1[1][0] = 3.0; m1[1][1] = 4.0;
    bias[0][0] = 0.0; bias[1][0] = 0.0;

    add(m1, bias, result, 2, 2);

    printf("Zero Bias Test: %s\n", matrices_equal(result, m1, 2, 2, 0.0001) ? "PASSED" : "FAILED");

    free_matrix(m1, 2);
    free_matrix(bias, 2);
    free_matrix(result, 2);
}
