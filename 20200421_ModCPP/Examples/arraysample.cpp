#include <array> 
#include <iostream> 
#include <string>
#include <algorithm>

bool startsWithT(std::string const& val) {
    return val[0] == 't';
}
int main() {

	std::array<std::string, 5> data = { "one", "two", "three", 
		"four", "two"};

	std::cout << "Display forward" << std::endl;

    std::array<std::string, 5>::iterator it = data.begin();
    auto end = data.end();
	for (; it != end; ++it) {
		std::cout << *it << ' ';
    }
    std::cout << '\n';
    //auto b = data.begin();
    auto num = std::count(data.begin(), data.end(), "two");
    std::cout << num << '\n';
    num = std::count_if(data.begin(), data.end(), startsWithT);
    std::cout << num << '\n';
	std::cout << "\n\nDisplay reverse" << std::endl;
	for (auto i{ data.size() }; i-- > 0; )
		std::cout << data[i] << ' ';

	return 0;
}