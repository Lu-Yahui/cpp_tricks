#include <iostream>
#include <array>

/**
 * @brief This is implemented based on template type deduction trick.
 * If the function template is declared to take its parameter by reference,
 * the type deduced for T is const T[N], which is the actual type of array, including the size.
 * 
 * If the function template is declared to take its parameter by value,
 * the type deduced for T is const T*.
 * 
 * @tparam T element type in array
 * @tparam N size of array
 * @return constexpr std::size_t 
 */
template <typename T, std::size_t N>
constexpr std::size_t ArraySize(T (&)[N]) noexcept
{
    return N;
}

int main(int argc, char **argv)
{
    int arr[] = {1, 2, 3};

    std::array<int, ArraySize(arr)> arr_copy;
    std::cout << ArraySize(arr) << std::endl;
    return 0;
}