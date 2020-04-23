#include <iostream>
using namespace std;

class XClass {
    public:
    
    XClass() {
        cout << "constructor - no arg\n";
    }
    
    XClass(std::initializer_list<int> sl) {
        cout << "constructor - std::initializer_list<int>\n";
    }
    
    XClass(int a) {
        cout << "constructor - n1 arg\n";
    }
};


int main() {
    //XClass x1();
    XClass x1{2};
    XClass x2(1);
    //XClass x3;
    //XClass *xp = new XClass{};

    std::initializer_list<int> sl {};
    XClass x4 = sl;
    XClass x5 = 6;

    return 0;
}
