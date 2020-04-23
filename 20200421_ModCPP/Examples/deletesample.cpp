#include <iostream>

template<typename T> 
void DoSomething(T _arg) {
}

void DoSomething(int _arg) = delete;

int main()
{
	DoSomething(1.5);
	// will not compile
	DoSomething(1);  
}
