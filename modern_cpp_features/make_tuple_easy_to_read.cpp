#include <iostream>
#include <tuple>
#include <type_traits>

enum class CatInfo : std::size_t
{
    Name,
    Age
};

/**
 * @brief this function is to convert enum class to tuple index, 
 * which makes tuple easier to read. 
 * 
 * e.g.
 * you can not easily know what the return value of std::get<0>(tuple) is.
 * with std::get<ToTupleIndex(CatInfo::Name)>(tuple), you are very sure what the return value is.
 * 
 * @note the std::underlying_type<T> gives you the underlying type of enum class T.
 * in this case, it is std::size_t.
 * 
 * @note constexpr is added because std::get<T> needs a value which determined during the compiling time.
 * 
 * @tparam EnumT 
 * @param enum_t 
 * @return constexpr std::underlying_type<EnumT>::type 
 */
template <typename EnumT>
constexpr typename std::underlying_type<EnumT>::type ToTupleIndex(EnumT enum_t) noexcept
{
    return static_cast<typename std::underlying_type<EnumT>::type>(enum_t);
}

int main(int argc, char **argv)
{
    std::tuple<std::string, unsigned int> gray_cat;
    gray_cat = std::make_tuple<std::string, unsigned int>("gray cat", 2U);

    auto name = std::get<ToTupleIndex(CatInfo::Name)>(gray_cat);
    auto age = std::get<ToTupleIndex(CatInfo::Age)>(gray_cat);

    std::cout << name << ": " << age << std::endl;

    return 0;
}
