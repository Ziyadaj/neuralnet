cmake_minimum_required(VERSION 3.10)
project(NeuralNetwork C)

set(CMAKE_C_STANDARD 11)

# Define TESTING macro for the entire project
add_definitions(-DTESTING)

# Add source files
set(SOURCE_FILES
    src/neural_network.c
    src/matrix.c
)

# Create the main library
add_library(neural_network ${SOURCE_FILES})

# Link math library to the main library
target_link_libraries(neural_network m)

# Enable testing
enable_testing()

# Function to add a test
function(add_project_test test_name)
    add_executable(${test_name} tests/${test_name}.c)
    target_link_libraries(${test_name} your_library)
    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

# Add all test files
add_project_test(test_forward_propagation)
add_project_test(test_matrix_operations)
