/**
 * @file tag_dispatching.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-04
 * 
 * @copyright Copyright (c) 2020
 * 
 * Tag dispatching is a quite intensively used technique in STL
 * e.g. std::advance
 * 
 */

#include <type_traits>
#include <iostream>

struct GenericCat
{
    struct GenericCatTag
    {
    };

    using CatTag = GenericCatTag;
};

struct GrayCat
{
    struct GrayCatTag
    {
    };

    using CatTag = GrayCatTag;
};

struct SesameCat
{
    struct SesameCatTag
    {
    };

    using CatTag = SesameCatTag;
};

namespace detail
{

    template <typename CatType, typename CatTag>
    void CatSayImpl(CatType &&cat, CatTag)
    {
        std::cout << "Generic Cat" << std::endl;
    }

    template <typename CatType>
    void CatSayImpl(CatType &&cat, typename GrayCat::CatTag)
    {
        std::cout << "Gray Cat" << std::endl;
    }

    template <typename CatType>
    void CatSayImpl(CatType &&cat, typename SesameCat::CatTag)
    {
        std::cout << "Sesame Cat" << std::endl;
    }

} // namespace detail

template <typename CatType>
void CatSay(const CatType &cat)
{
    using CatTag = typename CatType::CatTag;
    detail::CatSayImpl(cat, CatTag{});
}

// use std::decay to remove &, so that we can get the original cat type
template <typename CatType>
void CatSay(CatType &&cat)
{
    using CatTag = typename std::decay<CatType>::type::CatTag;
    detail::CatSayImpl(cat, CatTag{});
}

int main(int argc, char **argv)
{
    GrayCat gray_cat;
    CatSay(gray_cat);

    SesameCat sesame_cat;
    CatSay(sesame_cat);

    GenericCat cat;
    CatSay(cat);
    return 0;
}