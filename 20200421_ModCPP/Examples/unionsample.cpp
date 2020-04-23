#include <iostream>

class IntWrapper
{
public:
    IntWrapper() : pInt(0) {}
    int *pInt;
};

union Integer {
    Integer() {}
    IntWrapper pInt;
    int varInt;
};

int main()
{
    Integer obj;
    return 0;
}
