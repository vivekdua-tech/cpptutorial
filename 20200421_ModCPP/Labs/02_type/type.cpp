#include <iostream>

template<typename T, typename V>
void ShowType(T a, V b)
{
    std::cout << "a is of type " << typeid(a).name() << std::endl;
    std::cout << "b is of type " << typeid(b).name() << std::endl;
}

void ShowType(float a, int b) = delete;
struct MyStruct
{
};

int main()
{
    ShowType(4,5);
    ShowType(MyStruct(),5);
    //ShowType(4.3f, 5);

}