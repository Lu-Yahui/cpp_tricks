#include <iostream>
#include <string>

enum class MyCat
{
    GrayCat,
    Sesame
};

template <MyCat Cat>
struct Dispatcher
{
    static void MyCatSay(const std::string &s)
    {
    }
};

// specilization for gray cat
template <>
void Dispatcher<MyCat::GrayCat>::MyCatSay(const std::string &s)
{
    std::cout << "[GrayCat]: " << s << "\n";
}

// specilization for sesame
template <>
void Dispatcher<MyCat::Sesame>::MyCatSay(const std::string &s)
{
    std::cout << "[Sesame ]: " << s << "\n";
}

int main(int argc, char **argv)
{
    Dispatcher<MyCat::GrayCat>::MyCatSay("What is the best debugger for c++ ?");
    Dispatcher<MyCat::Sesame>::MyCatSay("A rubber duck!");

    return 0;
}