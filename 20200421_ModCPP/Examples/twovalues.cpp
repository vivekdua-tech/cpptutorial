#include <iostream>

class TwoValues {
public:
	friend  TwoValues operator+( float lvalue, const TwoValues& rvalue);
	TwoValues(int one, int two) {
		first = one;
		second = two;
	}

    friend std::ostream& operator<<(std::ostream& os, TwoValues const & val)
    {
        os << "(" << val.first << ", " << val.second << ")";
        return os;
    }
private:
	int first, second;
};

TwoValues operator+(const TwoValues& lhs, float rhs) {
    return rhs + lhs;
}

TwoValues operator+(float lvalue, const TwoValues& rvalue) {
	auto increment = int(lvalue / 2);
	return TwoValues(rvalue.first + increment, rvalue.second + increment);
}

int main() {
	TwoValues obj1(10, 20);
	TwoValues obj2 = obj1 + 12.4;
	//TwoValues obj3 = obj1.operator+(12.4);
	TwoValues obj4 = 12.4 + obj1;
    std::cout << "obj1 = " << obj1 << '\n';
    std::cout << "obj2 = " << obj2 << '\n';
    std::cout << "obj4 = " << obj4 << '\n';

}
