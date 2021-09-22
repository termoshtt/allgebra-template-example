cmake_minimum_required(VERSION 3.17)

add_executable(openmp_test
    test.cpp
)
target_link_libraries(openmp_test OpenMP::OpenMP_CXX)

add_test(openmp_test openmp_test)