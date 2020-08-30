/**
 * @file crtp_trick.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-05
 * 
 * @copyright Copyright (c) 2020
 * 
 * Curiously Recurring Template Pattern (CRTP)
 * 
 */

#include <iostream>
#include <type_traits>

template <typename CatT>
class ICat
{
public:
    void Say()
    {
        this->Derived().Say();
    }

private:
    CatT &Derived()
    {
        return static_cast<CatT>(*this);
    }

    const CatT &Derived() const
    {
        return static_cast<const CatT>(*this);
    }
};

class GrayCat : public ICat<GrayCat>
{
public:
    void Say()
    {
        std::cout << "I am GrayCat" << std::endl;
    }
};

class SesameCat : public ICat<SesameCat>
{
public:
    void Say()
    {
        std::cout << "I am SesameCat" << std::endl;
    }
};

int main(int argc, char **argv)
{
    GrayCat gray_cat{};
    SesameCat sesame_cat{};

    gray_cat.Say();
    sesame_cat.Say();
    return 0;
}