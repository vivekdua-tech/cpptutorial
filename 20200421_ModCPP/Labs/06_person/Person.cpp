#include <iostream>
using namespace std;

class Car {
public:
	Car(std::string _description) :
		description(_description) {}

	std::string GetDescription() {
		return description;
	}

private:
	std::string description;
};

class House {
public:
	House(std::string _address) :
		address(_address) {}

	std::string GetAddress() {
		return address;
	}

private:
	std::string address;
};

class Person {
public:

	Person() = default;

	Person(std::string cardescription,
			std::string homeaddress) {
		pCar = new Car(cardescription);
		pHouse = new House(homeaddress);	
	}

	Person(const Person& _inObject) {
		Init(_inObject.pCar,
			_inObject.pHouse);
	}

	Person& operator=(const Person& _inObject) {
		if (this == &_inObject) {
			return *this;
		}
		Init(_inObject.pCar, _inObject.pHouse);
		return *this;
	}

	void Init(Car* _pCar, House* _pHouse) {
		delete pCar;
		delete pHouse;
		pCar = new Car(_pCar->GetDescription());
		pHouse = new House(_pHouse->GetAddress());
	}

	~Person() {
		delete pCar;
		delete pHouse;
	}

	std::string GetPerson() {
		return pCar->GetDescription() + " " + pHouse->GetAddress();
	}
private:

	Car* pCar = nullptr;
	House* pHouse = nullptr;
};

int main()
{
	Person p1("Honda Civic", "100 Main Street");
	Person p2(p1);
	Person p3;
	p3 = p2;
	cout << "P1 " << p1.GetPerson() << endl;
	cout << "P2 " << p2.GetPerson() << endl;
	cout << "P3 " << p3.GetPerson() << endl;
}
