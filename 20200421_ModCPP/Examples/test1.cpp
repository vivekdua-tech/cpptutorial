#include <iostream>

class XClass {
public:
	XClass() : value(42) {
		//XClass tmp = XClass(42);
		ptr = new int;
	}
	XClass(int a) : ptr(nullptr) {
		value = a;
	}
	~XClass() {
		delete ptr;
	}
	int value;
private:
	int* ptr;
};
class YClass {
public:
	YClass() {
		pObjs = new XClass[3];
	}
	~YClass() {
		delete [] pObjs;
	}
	XClass* pObjs;
};

void process(XClass x)
{

}

int main()
{
    XClass x(18);
    std::cout << x.value << '\n';
    std::cout << "exiting main\n";
    //process(x);
    //process(XClass(10));


}