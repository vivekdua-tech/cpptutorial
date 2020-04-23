#include <iostream>

struct Rational
{
    Rational(int _num, int _den = 1) : num(_num), den(_den) {}

    explicit operator double() const
    {
        return num / (double)den;
    }

    double asDouble() const
    {
        return num / (double)den;
    }
public:
    int num, den;
};

std::ostream &operator<<(std::ostream &os, Rational const &r)
{
    os << r.num;
    if (r.den != 1)
    {
        os << '/' << r.den;
    }
    return os;
}

struct Set
{
    explicit Set(int _capacity) : capacity(_capacity)
    {
        // memory allocation
    }
    //...
private:
    int capacity;
};

void process(Rational r)
{
}

void process(Set r)
{
}

void findIn(Set const &set, int val)
{
}

void print(double x)
{
    std::cout << x << '\n';
}

int main()
{
    auto r = Rational(3, 4);
    auto r2 = Rational(3);

    //std::cout << r << '\n';
    r << std::cout << '\n';
    process(r2);

    process(5); // process(Rational(5));

    auto s = Set(10);
    //someother set operations
    findIn(s, 3);

    //findIn(10000000, 4); // findIn(Set(10000000), 4);

    print(3.14);

    print(static_cast<double>(r));
    print((double)r);
}