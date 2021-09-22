cmake_minimum_required(VERSION 3.17)
project(allgebra_vscode_example
    VERSION 0.1.0
    DESCRIPTION "Example project to show the usage of allgebra with Visual Studio Code"
    HOMEPAGE_URL https://github.com/ricosjp/allgebra-remote-container
    LANGUAGES CXX
)
enable_testing()

# Find OpenMP runtime
# See https://cmake.org/cmake/help/latest/module/FindOpenMP.html
find_package(OpenMP REQUIRED)

# clangd setting
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)