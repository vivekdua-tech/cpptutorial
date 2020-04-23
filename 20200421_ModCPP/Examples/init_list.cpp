#include <iostream>
#include <vector>


struct Base
{
    Base(std::initializer_list<int> _in) : data(_in) {}

    int* begin() {
        return &data[0];
    }

    int* end() {
        return &data[data.size()];
    }

    //auto begin() {
    //    return data.begin();
    //}

    //auto end() {
    //    return data.end();
    //}

    void print() const {
        for (auto val : data) {
            std::cout << val << ',';
        }
        std::cout << '\n';
    }
private:
    std::vector<int> data;
};

int main()
{
    auto li = {2,2,76,4,2,213,452,3};
    int a[] = {3,2,3,2,344,452};

    for (auto val : a) {
        std::cout << val << ',';
    }
    std::cout << '\n';

    for (auto& val : a) {
        val += 3;
    }
    for (int val : a) {
        std::cout << val << ',';
    }
    std::cout << '\n';

    for (int val : li) {
        std::cout << val << ',';
    }
    std::cout << '\n';
    
    auto b = Base(li);

    b.print();
    for (auto & val : b) {
        val *= 2;
    }
    b.print();

}