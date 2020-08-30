#include <iostream>
#include <type_traits>

class Cat
{
public:
    template <typename T,
              typename = typename std::enable_if<!std::is_same<Cat, typename std::decay<T>::type>::value>::type>
    explicit Cat(T &&name)
    {
        std::cout << "universal reference constructor invoked" << std::endl;
    }

    explicit Cat(const Cat &other)
    {
        std::cout << "copy constructor invoked" << std::endl;
    }

    Cat() = default;
};

int main(int argc, char **argv)
{
    Cat src;
    Cat cat_1(src);
    Cat cat_2("graycat");

    return 0;
}