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

# Create the test executable
add_executable(test_neural_network tests/forward_propagation.c)
target_link_libraries(test_neural_network neural_network)

# Enable testing
enable_testing()

# Add the test
add_test(NAME NeuralNetworkTests COMMAND test_neural_network)
