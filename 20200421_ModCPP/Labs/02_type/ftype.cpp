#include <iostream>


template<typename FP>
void DisplayFunctionType(FP fp)
{
    std::cout << typeid(decltype(fp)).name() << '\n';
}


int FuncA(int x)
{
    return x;
}

void FuncB() {
}

int main()
{
    DisplayFunctionType(FuncA);
    DisplayFunctionType(FuncB);
}