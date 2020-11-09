/**
 * @file variadic_templates.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-09
 * 
 * @copyright Copyright (c) 2020
 * 
 * Variadic templates is a new feature in C++ 11. It allows to write functions taking an arbitrary
 * number of arguments and handle and resolve them in a type-safe way at compiling time.
 * 
 * The first example shows the very basic usage of variadic templates.
 * The second example shows how to compute max size of a list given types, this is useful when to implememt
 * variant.
 * 
 */

#include <iostream>

/**
 * @brief Example 1, similar to recursion, this is the base case.
 * 
 * @tparam T 
 * @param t 
 * @return T 
 */
template <typename T>
T add(T t)
{
    return t;
}

/**
 * @brief Example 1, add at compiling time.
 * 
 * @tparam T
 * @tparam Args: template parameter pack 
 * @param first 
 * @param args 
 * @return T 
 */
template <typename T, typename... Args>
T add(T first, Args... args)
{
    return first + add(args...);
}

/**
 * @brief Example 2, compute the max size of given types
 * 
 * @tparam T 
 * @tparam Args 
 */
template <typename T, typename... Args>
struct max_size
{
    static constexpr auto size = sizeof(T) > max_size<Args...>::size ? sizeof(T)
                                                                     : max_size<Args...>::size;
};

/**
 * @brief Example 2, base case
 * 
 * @tparam T 
 */
template <typename T>
struct max_size<T>
{
    static constexpr auto size = sizeof(T);
};

int main(int argc, char **argv)
{
    // test example 1
    auto sum = add(1, 2, 3, 4, 5);
    std::cout << "sum: " << sum << std::endl;

    // test example 2
    auto size = max_size<char, int32_t, int64_t>::size;
    std::cout << "max size of char, int32_t and int64_t is: " << size << " Bytes." << std::endl;

    return 0;
}