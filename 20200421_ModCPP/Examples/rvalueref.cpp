#include <iostream>

int FuncA(){
	return 5;
}

int b = 10;
int & x = b;

int & FuncB() {
	return b;
}

struct Collection
{
    int& operator[](int index) { return a[index]; }
private:
    int a[5];
};

int main() {
    int a = 5;
    int &b = a;

    const int &c = 10;

    int &&d = 10; //_is_a_name

    //int && x = (int&&)d;
    int && x = std::move(d);
    //int && e = a;

	// int a = 100; 
	// //100 = a; 
	// int c = FuncA(); 
	// FuncB() = a;
    // std::cout << b << '\n';
    // x = b;
    // Collection col;
    // col[1] = 4;
}
