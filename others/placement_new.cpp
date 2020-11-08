/**
 * @file placement_new.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-08
 * 
 * @copyright Copyright (c) 2020
 * 
 * Placement new is a rarely used syntax in C++.
 * It initializes object in the pre-allocated memory.
 * 
 */

#include <iostream>
#include <string>

struct Cat
{
    Cat(const int &_age, const std::string &_name)
        : age(_age), name(_name)
    {
        toys = new int[2];
        std::fill(toys, toys + 2, 1);
        std::cout << "Cat Initialized" << std::endl;
    }

    ~Cat()
    {
        std::cout << "Destructor" << std::endl;
        delete[] toys;
    }

    int age;
    std::string name;
    int *toys;
};

int main(int argc, char **argv)
{
    // 1. allocate memory
    const auto cat_size = sizeof(Cat);
    std::cout << "Cat size: " << cat_size << std::endl;
    char *cat_buffer = new char[cat_size];

    // 2. initialize cat
    Cat *gray_cat = new (cat_buffer) Cat(3, "gray cat");
    std::cout << gray_cat->name << ": " << gray_cat->age << std::endl;

    // 3. invoke destructor manually, if necessary.
    gray_cat->~Cat();

    // 4. free buffer
    delete[] cat_buffer;

    return 0;
}