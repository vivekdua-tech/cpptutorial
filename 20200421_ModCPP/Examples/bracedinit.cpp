#include <iostream>
#include <vector>
#include <initializer_list>

struct One
{
    int x, y;
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
    int a1 = 1;
    int a2(3);
    
    int a3{4};
    int a4 = {4};
    
    One o1 = {3,4};
    Two t1 = {3,4};

    Four f1 {2};   


    int a[]{1,2,3};
    std::vector<int> v1(std::begin(a), std::end(a));
    std::initializer_list<int> sil{5,6,7};
    //std::vector<int> v2(sil);
    std::vector<int> v2{7,9,9};
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