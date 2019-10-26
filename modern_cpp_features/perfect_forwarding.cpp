#include <utility>
#include <iostream>
#include <cstring>

struct Point2i
{
    int x;
    int y;
};

std::ostream &operator<<(std::ostream &os, const Point2i &p)
{
    os << "P(" << p.x << ", " << p.y << ")";
    return os;
}

class PointCloud2i
{
public:
    PointCloud2i(int n)
        : size_(n)
    {
        if (size_ > 0)
        {
            points_ = new int[2 * size_];
            for (int i = 0; i < size_; ++i)
            {
                points_[2 * i] = i;
                points_[2 * i + 1] = i;
            }
        }
    }

    PointCloud2i(const PointCloud2i &other)
    {
        std::cout << "copy constructor\n";
        size_ = other.size_;
        if (size_ > 0)
        {
            points_ = new int[2 * size_];
            for (int i = 0; i < size_; ++i)
            {
                points_[2 * i] = other.points_[2 * i];
                points_[2 * i + 1] = other.points_[2 * i + 1];
            }

            // also we can copy elements by std::copy or std::memcoy
            // std::copy(other.points_, other.points_ + 2 * size_, points_);
            // std::memcpy(points_, other.points_, 2 * sizeof(int) * size_);
        }
    }

    PointCloud2i(PointCloud2i &&other)
    {
        std::cout << "move constructor\n";
        size_ = other.size_;
        if (size_ > 0)
        {
            points_ = other.points_;
            other.points_ = nullptr;
        }
    }

    PointCloud2i &operator=(const PointCloud2i &other)
    {
        std::cout << "copy assignment\n";
        if (&other != this)
        {
            delete[] points_;
            points_ = nullptr;

            size_ = other.size_;
            if (size_ > 0)
            {
                points_ = new int[2 * size_];
                for (int i = 0; i < size_; ++i)
                {
                    points_[2 * i] = other.points_[2 * i];
                    points_[2 * i + 1] = other.points_[2 * i + 1];
                }
            }
        }

        return *this;
    }

    PointCloud2i &operator=(PointCloud2i &&other)
    {
        if (&other != this)
        {
            std::cout << "move assignment\n";

            size_ = other.size_;
            delete[] points_;
            points_ = other.points_;
            other.points_ = nullptr;
        }
    }

    ~PointCloud2i()
    {
        if (points_ != nullptr)
        {
            delete[] points_;
        }
    }

    Point2i Point(const int i) const
    {
        return {points_[2 * i], points_[2 * i + 1]};
    }

    int Size() const
    {
        return size_;
    }

private:
    int *points_;
    int size_;
};

std::ostream &operator<<(std::ostream &os, const PointCloud2i &point_cloud)
{
    for (int i = 0; i < point_cloud.Size(); ++i)
    {
        os << point_cloud.Point(i) << ",";
    }
    return os;
}

template <typename T, typename U>
std::pair<T, U> MakePairWitForwarding(T &&t, U &&u)
{
    return std::make_pair(std::forward<T>(t), std::forward<U>(u));
}

template <typename T, typename U>
std::pair<T, U> MakePairWithoutForwarding(T &&t, U &&u)
{
    return std::make_pair(t, u);
}

int main(int argc, char **argv)
{
    PointCloud2i pc1(1000000);
    PointCloud2i pc2 = pc1;

    std::cout << "--- MakePairWithoutForwarding ---\n";
    MakePairWithoutForwarding(1, std::move(pc1));

    std::cout << "---- MakePairWithForwarding ----\n";
    MakePairWitForwarding(1, std::move(pc2));

    return 0;
}