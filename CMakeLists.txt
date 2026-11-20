cmake_minimum_required(VERSION 4.4)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions($<$<CONFIG:Debug>:_GLIBCXX_DEBUG>)

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
add_executable(io_stream stream/io_stream.cpp)
add_executable(file_stream stream/file_stream.cpp)

configure_file(stream/file_stream.txt ${CMAKE_CURRENT_BINARY_DIR}/file_stream.txt COPYONLY)
configure_file(stream/file_stream_other.txt ${CMAKE_CURRENT_BINARY_DIR}/file_stream_other.txt COPYONLY)
configure_file(stream/file_stream_output.txt ${CMAKE_CURRENT_BINARY_DIR}/file_stream_output.txt COPYONLY)

add_executable(string_stream stream/string_stream.cpp)
add_executable(template template/template.cpp)
add_executable(template_metaprogramming template/template_metaprogramming.cpp)
add_executable(sequence_container standard_template_library/sequence_container.cpp)
add_executable(my_deque example/my_deque/my_deque.cpp
        example/my_deque/my_deque.h
        example/my_deque/main.cpp
        example/my_deque/my_deque.cpp
        example/my_deque/my_deque.h
        example/my_deque/main.cpp)
