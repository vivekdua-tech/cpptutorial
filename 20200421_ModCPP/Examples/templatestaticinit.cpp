#include <iostream>

template<class T> class XClass {
    
    public:
    
    static int vara;
    static T varb;
};
template<typename T>
int XClass<T>::vara = 3;

template<typename T>
T XClass<T>::varb = T{4};

int main()
{
    std::cout << XClass<int>::vara << '\n';
    std::cout << XClass<int>::varb << '\n';
    
}