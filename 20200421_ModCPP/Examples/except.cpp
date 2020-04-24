#include <iostream>
#include <vector>

class String final
{
public:
    String(const char* str) : data(str == nullptr ? nullptr : new char[strlen(str)+1]) {
        std::cout << "allocating memory\n"; 
        strcpy(data, str);
    }
    String(String const & other) : String(other.data) { std::cout << "String copy\n"; }
    String(String && other) noexcept : data(other.data) {
        std::cout << "String move\n"; 
        other.data = nullptr; 
    }

    ~String() noexcept { delete [] data; }

    String& operator=(String const & rhs) {
        std::cout << "String copy assignment\n";
        String tmp(rhs);
        using std::swap;
        swap(data, tmp.data);
        return *this;
    }

    String& operator=(String && rhs) noexcept {
        std::cout << "String move assignment\n";
        if (this == &rhs) { return *this; }
        delete [] data;
        data = rhs.data;
        rhs.data = nullptr;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, String const & str) {
        os << (str.data == nullptr ? "null" : str.data);
        return os;
    }
private:
    char * data;
};

std::vector<String> createVectorString(std::vector<String> tmp, bool thw) {
    tmp = std::vector<String>{};
    tmp.push_back(String("hello"));
    tmp.push_back(String("goodbye"));
    tmp.push_back(String("aloha"));
    if (thw) {
        throw std::bad_exception();
    }
    return tmp;
}

int main()
{
    auto vec = std::vector<String>{};
    vec.push_back(String("info"));
    vec.push_back(String("more"));
    vec.push_back(String("something"));

    try {
        vec = createVectorString(vec, false);
    } catch (std::exception e) {}

    std::cout << "-------------------------------\n";
    for (auto val : vec) {
        std::cout << val << '\n';
    }
    std::cout << "\n-------------------------------\n";
    std::cout << std::endl;

}