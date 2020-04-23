#include <iostream>
#include <vector>
#include <initializer_list>

struct One
{
    int x = 4,  y = 2;
};

struct Two
{
    Two(int v1, int v2) : x(v1), y(v2) {}
    int x, y;
};

struct Three
{
    Three(int x, int y, int z) : data{x,y,z} {
    }
    const int data[3];
};

struct Four
{
    Four(int _x) : x(_x) {
        std::cout << "Four(int)\n"; 
    }
    int x;
};

void print(int val)
{
    std::cout << val << ',';
}
int main()
{
    auto a1 = 1;
    auto a2(3);
    
    auto a3{4}; // c++11 treated this as std::initializer_list<int>
    auto a4 = {4,3,4};
    
    auto o1 = One{3,4};
    auto t1 = Two{3,4};

    auto f1 = Four{2};   


    int a[]{1,2,3};
    std::vector<int> v1(std::begin(a), std::end(a));
    std::initializer_list<int> sil{5,6,7};
    //std::vector<int> v2(sil);
    auto v2 = std::vector<int>{7,9,9};
    v2 = sil;
    v1 = {29,39,402};

    //std::vector<std::string> v3{"one", "two"};
    //std::vector<std::string> v4("one", "two");

    std::vector<int> v3{7,9};
    std::vector<int> v4(7,9);

    std::for_each(v3.begin(), v3.end(), print);
    std::cout << '\n';
    std::for_each(v4.begin(), v4.end(), print);
    std::cout << '\n';
}