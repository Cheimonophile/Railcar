cmake_minimum_required(VERSION 3.0.0)
project(rcc VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)


# Project
file(GLOB_RECURSE SRC src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PRIVATE src)

# import LLVM
find_package(LLVM REQUIRED CONFIG PATHS /Users/ben/lib/c++/llvm-12.0.1/lib/cmake/llvm)
include_directories(${LLVM_INCLUDE_DIRS})#  /Users/ben/lib/c++/llvm-12.0.1/include)
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(${PROJECT_NAME} ${llvm_libs})




set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

