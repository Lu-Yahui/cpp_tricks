/**
 * @file virtual_constructor.cpp
 * @author GrayLoo (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-30
 * 
 * @copyright Copyright (c) 2019
 * 
 * We can NOT copy an object from a base class pointer, 
 * because the compiler must know exactly how many memories to allocate for the copy.
 * A virtual constructor is a way to delegate coping to the derived class, 
 * by defining a pure virtual clone function in the base class.
 */
#include <iostream>
#include <memory>

class Cat
{
public:
    virtual ~Cat() = default;

    virtual Cat *Clone() const = 0;
};

class GrayCat : public Cat
{
public:
    virtual GrayCat *Clone() const override
    {
        std::cout << "Cloned Graycat." << std::endl;
        return new GrayCat();
    }
};

class Sesame : public Cat
{
public:
    virtual Sesame *Clone() const override
    {
        std::cout << "Cloned Sesame." << std::endl;
        return new Sesame();
    }
};

int main(int argc, char **argv)
{
    Cat *graycat = new GrayCat();
    Cat *sesame = new Sesame();

    // clone gray cat by a base class pointer
    Cat *graycat_copy = graycat->Clone();
    // clone sesame by a base class pointer
    Cat *sesame_copy = sesame->Clone();
    return 0;
}