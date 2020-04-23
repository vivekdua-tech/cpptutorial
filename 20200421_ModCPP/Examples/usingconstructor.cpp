#include <iostream>
#include <string>

struct Base
{
    Base() = default;
    Base(int) {}
    Base(double, int) {}
    Base(std::string) {}

    virtual void foo() {}
    virtual void foo(int) {}
    virtual void foo(std::string) {}
};

struct Sub : public Base
{
    using Base::Base;
    //Sub(double x, int y) : Base(x, y) {/*do nothing*/}
    //Sub() { init();}
    //Sub(int) { init(); }
    Sub() : Sub(4) { }
    Sub(double y) : Sub(3) { data = y; }
    Sub(int x) : Base(x), data(x) { /*init code*/ }
    using Base::foo;
    void foo() override {}
    void bar() {}
private:
    void init() {}
    int data;
};

int main()
{
    Sub s(3.14, 4);

    s.foo();
    s.foo(3);
    s.bar();

};
