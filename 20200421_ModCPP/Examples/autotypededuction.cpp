#include <iostream>

template<typename T>
T Func(T& param) {return param;}

template<typename T>
T Func2(const T& param) {return param;}

//int Func(int& param) {return param;}
//const int Func(const int& param) {return param;}

int a=42;
const int a_const=a;
const int& a_ref=a;

void foo(int x) {
    x = 10;
}

int main() {
    foo(a);
    foo(a_const);
    foo(a_ref);
      
    Func(a);        // 1
    Func(a_const);  // 2
    Func(a_ref);    // 3

    auto& aa = a;
    auto& aa_const = a_const;
    auto& aa_ref = a_ref;

    Func2(a);        // 1
    Func2(a_const);  // 2
    Func2(a_ref);    // 3

    const auto& caa = a;
    const auto& caa_const = a_const;
    const auto& caa_ref = a_ref;

    auto x = {2,3,4};
    //Func({3,4,5}); // non-deduced
    Func(x);
}
