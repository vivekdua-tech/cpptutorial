#include <iostream>
#include <cstring>

class String final
{
public:
    String(const char* str) : data(str == nullptr ? nullptr : new char[strlen(str)+1]) {
        std::cout << "allocating memory\n"; 
        strcpy(data, str);
    }
    String(String const & other) : String(other.data) { std::cout << "String copy\n"; }
    String(String && other) : data(other.data) {
        std::cout << "String move\n"; 
        other.data = nullptr; 
    }

    ~String() { delete [] data; }

    String& operator=(String const & rhs) {
        std::cout << "String copy assignment\n";
        String tmp(rhs);
        using std::swap;
        swap(data, tmp.data);
        return *this;
    }

    String& operator=(String && rhs) {
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
/*     String& operator=(String const & rhs) {
        if (this == &rhs) { return *this; }
        delete [] data;
        data = (rhs.data == nullptr ? nullptr : new char[strlen(rhs.data)+1]);
        strcpy(data, rhs.data);
        return *this;
    }
 */
private:
    char * data;
};

String process(String s) {
    std::cout << "in process : " << s << '\n';
    return s;
}

int main()
{
    auto s = String("hello");

    process(s);

    auto t = String("goodbye");

    try {
        s = t;
    } catch (...) {}

    std::cout << s << '\n';

    //auto z = process(s);
    auto z = process(s);
    std::cout << z << '\n';

    t = process(s);
    std::cout << z << '\n';

    auto x = std::move(z);

    std::cout << x << '\n';
}