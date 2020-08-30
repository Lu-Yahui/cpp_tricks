cmake_minimum_required(VERSION 3.0)
project(cpp_tricks)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(perfect_forwarding 
    modern_cpp_features/perfect_forwarding.cpp
)

add_executable(make_tuple_easy_to_read 
    modern_cpp_features/make_tuple_easy_to_read.cpp
)

add_executable(dispatcher
    templates/dispatcher.cpp
)

add_executable(compute_array_size_at_compiling_time
    templates/compute_array_size_at_compiling_time.cpp
)

add_executable(tricks_of_overloading_on_universal_references
    templates/tricks_of_overloading_on_universal_references.cpp
)

add_executable(tag_dispatching
    templates/tag_dispatching.cpp
)

add_executable(crtp_trick
    templates/crtp_trick.cpp
)

add_executable(virtual_constructor
    others/virtual_constructor.cpp
)

add_executable(class_acting_like_pointer
    others/class_acting_like_pointer.cpp
)
