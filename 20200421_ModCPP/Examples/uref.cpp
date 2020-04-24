#include <iostream>

struct One
{

};

void process(One && rval) {
    std::cout << "rval\n";
}

void process(One const & lval) {
    std::cout << "lval\n";
}

template<typename T>
void logAndCall(T &&param)
{
    std::cout << "logging\n";
    process(std::forward<T>(param));
}

int main()
{
    auto val = One{};

    process(val);
    process(One{});

    logAndCall(val);
    logAndCall(One{});
}