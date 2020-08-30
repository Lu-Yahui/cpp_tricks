#include <iostream>
#include <vector>

class GrayCat
{
public:
    GrayCat()
        : count(new std::size_t(1UL))
    {
        toys = new int[100];
    }

    GrayCat(const GrayCat &other)
        : toys(other.toys), count(other.count)
    {
        ++(*count);
    }

    GrayCat &operator=(const GrayCat &other)
    {
        ++(*other.count);
        --(*count);
        if (*count == 0UL)
        {
            if (count != nullptr)
            {
                delete count;
            }
            if (toys != nullptr)
            {
                delete[] toys;
            }
        }

        toys = other.toys;
        count = other.count;

        return *this;
    }

    ~GrayCat()
    {
        --(*count);
        std::cout << "count: " << *count << "\n";
        if (*count == 0UL)
        {
            delete count;
            delete[] toys;
            std::cout << "deallocated.\n";
        }
    }

private:
    int *toys;
    // here we use a run time allocated count to share count between copies
    std::size_t *count;
};

int main(int argc, char **argv)
{
    // initialize my gray cat
    GrayCat gray_cat_1;
    // copy constructor
    auto gray_cat_2 = gray_cat_1;
    auto gray_cat_3 = gray_cat_1;
    GrayCat gray_cat_4(gray_cat_2);

    // // copy assignment
    GrayCat gray_cat_5;
    gray_cat_5 = gray_cat_1;

    return 0;
}