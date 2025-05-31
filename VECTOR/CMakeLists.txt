cmake_minimum_required(VERSION 3.14)

set(This OOP3V30)
project(${This})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Include directories
include_directories(Include)

# Collect source files (excluding main.cpp for library)
file(GLOB SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Create a library from your source files (excluding main.cpp)
if(SOURCES)
    add_library(${This}_lib ${SOURCES})
    target_include_directories(${This}_lib PUBLIC Include)
endif()

# Create the main executable
add_executable(${This} src/main.cpp)
if(SOURCES)
    target_link_libraries(${This} ${This}_lib)
endif()

# Google Test setup
option(BUILD_TESTS "Build tests" ON)

SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

if(BUILD_TESTS)
    # Add Google Test
    add_subdirectory(googletest-main)
    
    # Enable testing
    enable_testing()
    
    # Collect test files
    file(GLOB TEST_SOURCES "test/*.cpp")
    
    if(TEST_SOURCES)
        # Create test executable
        add_executable(${This}_tests ${TEST_SOURCES})
        
        # Link test executable with Google Test and your library
        target_link_libraries(${This}_tests 
            gtest 
            gtest_main
            ${This}_lib
        )
        
        # Include directories for tests
        target_include_directories(${This}_tests PRIVATE Include)
        
        # Add tests to CTest
        add_test(NAME ${This}_unit_tests COMMAND ${This}_tests)
    endif()
endif()