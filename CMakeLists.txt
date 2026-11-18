cmake_minimum_required(VERSION 4.4)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp)
add_executable(operator_overloading operator_overloading/operator_overloading.cpp)
add_executable(reference reference/reference.cpp)
add_executable(function_overloading function_overloading/function_overloading.cpp)
add_executable(constructor constructor/constructor.cpp)
add_executable(destructor destructor/destructor.cpp)
