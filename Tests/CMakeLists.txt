# Minimal version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(DataStructuresTests)

# Enable testing
enable_testing()

# Add Google Test directory
add_subdirectory(googletest)

# Include directories for headers
include_directories(
    googletest/include
    ../DataStructures/Common
    ../DataStructures/Linear/Queue
    ../DataStructures/Linear/LinkedList
    ../DataStructures/NonLinear/BST
)

# List of source files for the tests
set(TEST_SOURCES
    Linear/TestQueue.cpp
    Linear/TestLinkedList.cpp
    NonLinear/TestBST.cpp
    tests.cpp
)

# Create the test executable
add_executable(tests ${TEST_SOURCES})

# Link the test executable with Google Test and pthread
target_link_libraries(tests gtest)

# Add test target for running tests
add_test(NAME AllTests COMMAND tests)