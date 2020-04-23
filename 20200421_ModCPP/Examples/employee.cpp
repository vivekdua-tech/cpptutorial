#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	//friend class Employee;
	Person(string newname) {
		name = newname;
	}
	virtual void Display() = 0;
protected:
	string name;
};

class Employee: public Person {
public:
	Employee(string name) : Person(name) {
	}
	void Display() {
		cout << name << '\n';
	}
};

int main() {
	Employee bob("Bob Young");
	bob.Display();

    std::cout << bob.name << '\n';
}
