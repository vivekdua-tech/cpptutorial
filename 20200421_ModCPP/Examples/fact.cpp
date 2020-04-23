#include <iostream>

int Factorial(short value);

int main()
{
	auto result = Factorial(6);

    std::cout << result << '\n';
}

int Factorial(short value) {
	static int answer=1, count;
	answer=answer*(++count);
	if (count == value) {
		return answer;
	}
    return Factorial(value);
}
