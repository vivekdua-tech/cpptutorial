#include <iostream>
#include <functional>

using namespace std;

enum op_type { a, d, m, s };

double mat[4][4] = {
    {a,4,5,0},
    {d,0,3,0},
    {m,4,8,0},
    {s,1,4,0},
};

std::function<double(double, double)> lams[4]{
    [](double a, double b) { return a + b; },
    [](double a, double b) { return a / b; },
    [](double a, double b) { return a * b; },
    [](double a, double b) { return a - b; }
};
int main()
{
    for (auto& v : mat)
    {
        v[3] = lams[static_cast<int>(v[0])](v[1],v[2]);
    }

    for (auto v : mat)
    {
        switch (static_cast<int>(v[0]))
        {
            case a:
                std::cout << "add(";
                break;
            case d:
                std::cout << "div(";
                break;
            case m:
                std::cout << "mul(";
                break;
            case s:
                std::cout << "sub(";
                break;
        }
        std::cout << v[1] << ", " << v[2] << ") is " << v[3] << '\n';
    }
}