cmake_minimum_required(VERSION 4.4)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp)
add_executable(operator_overloading operator_overloading/operator_overloading.cpp)
add_executable(reference reference/reference.cpp)
add_executable(function_overloading function_overloading/function_overloading.cpp)
add_executable(constructor constructor/constructor.cpp)
add_executable(destructor destructor/destructor.cpp)
add_executable(this_pointer this_pointer/this_pointer.cpp)
add_executable(cv-qualifiers cv-qualifiers/cv-qualifiers.cpp)
add_executable(my_string example/my_string/my_string.cpp example/my_string/my_string.h
        example/my_string/main.cpp)
add_executable(function_specifier function_specifier/function_specifier.cpp)
add_executable(storage_class_specifier storage_class_specifier/storage_class_specifier.cpp)
add_executable(inheritance inheritance/Inheritance.cpp)
