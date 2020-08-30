# C++ Tricks
C++ tricks, modern C++ features and C++ related patterns 
## Who is gray cat and sesame?
Gray cat and Sesame are two cats of mine.

---
## Templates
### [dispatcher](templates/dispatcher.cpp)
### [tag dispatching](templates/tag_dispatching.cpp)
Tag dispatching is an intensively used technique in STL.
### [compute array size at compiling time](templates/comput_array_size_at_compiling_time.cpp)
This is implemented based on template type deduction trick.
If the function template is declared to take its parameter by reference,
the type deduced for T is const T[N], which is the actual type of array, including the size.
### [CRTP trick](templates/crtp_trick.cpp)
CRTP is a trick to implement compile-time polymorphism.

---
## Modern C++ Features
### [perfect forwarding](modern_cpp_features/perfect_forwarding.cpp)
### [tuple trick](modern_cpp_features/make_tuple_easy_to_read.cpp)

---
## Others
### [virtual constructor](others/virtual_constructor.cpp)
Virtual constructor is a technique which makes it possible to copy an object from a base class pointer, by delegating the coping action to the derived class.
### [class acting like shared pointers](others/class_acting_like_pointer.cpp)
This is a simple example that demostrates how shared_ptr works. It uses a run time allocated counter to remember how many references so far. Once the count becomes zero, the resource will be deallocated. This example is NOT thread safe. Try to set counter as std::atomic, to get it thread safe. 
