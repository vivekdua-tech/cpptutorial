#include <iostream>
#include <boost/type_index.hpp>

template<typename T, typename V>
void display_prototype(T* func, V arg)
{
    //std::cout << boost::typeindex::type_id<decltype(func)>().pretty_name() << '\n';
    std::cout << boost::typeindex::type_id<T>().pretty_name() << '\n';
    std::cout << boost::typeindex::type_id<V>().pretty_name() << '\n';
}

void func(int x) { std::cout << x; }
int main()
{
    display_prototype(func, 4.5);
}