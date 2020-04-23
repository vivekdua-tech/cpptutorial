#include <iostream>
#include <boost/type_index.hpp>

template<typename T1, typename T2>
//auto mult(T1 v1, T2 v2) -> decltype(v1 * v2)
decltype(auto) mult(T1 v1, T2 v2)
{
    return v1 * v2;
}

struct MyStruct
{
};

int foo(double x, char c) { return 1; }

int main()
{
    auto sum = mult(3,2.3);

    int x = 23;
    double y = 3.14;

    //decltype(x++) tmp;
    auto tmp = x++;

    std::cout << tmp << '\n';
    std::cout << x << '\n';

    auto ms = MyStruct{};

    std::cout << typeid(x).name() << '\n';
    std::cout << typeid(y).name() << '\n';
    std::cout << typeid(ms).name() << '\n';
    std::cout << typeid(foo).name() << '\n';
    std::cout << boost::typeindex::type_id<decltype(foo)>().pretty_name() << '\n';
}