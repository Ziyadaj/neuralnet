cmake_minimum_required(VERSION 3.10)
project(NeuralNetwork C)

set(CMAKE_C_STANDARD 11)

# Add source files
set(SOURCE_FILES
    src/neural_network.c
    src/matrix.c
)

# Create the main library
add_library(neural_network ${SOURCE_FILES})

# Create the test executable
add_executable(test_neural_network tests/forward_operations.c)
target_link_library(test_neural_network neural_network)

# Enable testing
enable_testing()

# Add the test
add_test(NAME NeuralNetworkTests COMMAND test_neural_network)
