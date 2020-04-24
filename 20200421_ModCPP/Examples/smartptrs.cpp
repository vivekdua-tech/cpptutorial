#include <iostream>
#include <memory>
#include <cstdio>

struct RAII
{
    RAII(int *_data) : data(_data) { std::cout << "Acquisition of int\n"; }
    ~RAII()
    {
        std::cout << "deleting int\n";
        delete data;
    }
    int *data;
};
void func()
{
    // RAII - Resource Acquisition Is Initialization
    auto raii = RAII(new int(4));
    std::cout << "working with int\n";
}
/*
void bad_auto_ptr()
{
    std::auto_ptr<int> a(new int(4));

    std::cout << *a << '\n';

    *a = 19;

    std::cout << *a << '\n';

    std::auto_ptr<int> b = a;

    std::cout << *b << '\n';
    std::cout << *a << '\n';

}
*/

struct MyStruct
{
    MyStruct(int _x, int _y) : x(_x), y(_y) {}
    void foo() { std::cout << "calling foo\n"; }
    void bar() { std::cout << "calling bar\n"; }
    int x, y;
};
void use_unique_ptr()
{
    std::unique_ptr<int> a(new int(4));

    std::cout << *a << '\n';

    *a = 19;

    std::cout << *a << '\n';

    //std::unique_ptr<int> b = a;
    std::unique_ptr<int> b = std::move(a);

    std::cout << *b << '\n';
    //std::cout << *a << '\n';
    //std::unique_ptr<MyStruct> c{new MyStruct{}};
    auto c = std::make_unique<MyStruct>(4, 4);

    c->foo();
    c->bar();

    //c.release();
    c.reset(new MyStruct{2, 3});
    if (c)
    {
        c->bar();
    }
    //auto fp = std::fopen("employee.cpp","r");
    //std::unique_ptr<FILE, int(FILE*)> file(fp, std::fclose);
}

void use_shared_ptr()
{
    using namespace std;
    auto sp = std::shared_ptr<int>{ new int(4) };
    auto sp2 = sp;
    auto x = std::make_shared<int>(5);
    {
        auto a = x;
        cout << a.use_count() << endl;
    }
    cout << x.use_count() << endl;
    x.reset();
    cout << x.use_count() << endl;
}
struct B;
struct A
{
    A() { std::cout << "construct A\n";}
    ~A() { std::cout << "destruct A\n";}
    void foo() const {std::cout << "calling A\n"; }
    std::shared_ptr<B> b_ptr;
};

struct B
{
    B() { std::cout << "construct B\n";}
    ~B() { std::cout << "destruct B\n";}

    void doSomethingWithA() {
        std::cout << "A : " << a_ptr.use_count() << '\n';
        auto spa = a_ptr.lock();
        if (spa) {
            spa->foo();
        }
        std::cout << "A : " << a_ptr.use_count() << '\n';
    }
    std::weak_ptr<A> a_ptr;
};

void linkedref()
{
    auto sa = std::make_shared<A>();
    auto sb = std::make_shared<B>();

    sa->b_ptr = sb;
    sb->a_ptr = std::weak_ptr<A>{sa};
    sb->doSomethingWithA();
    std::cout << "A : " << sa.use_count() << '\n';
    std::cout << sb.use_count() << '\n';
}
std::unique_ptr<int> intFactory()
{
    return std::make_unique<int>(3);
}
int main()
{
    //func();
    //use_unique_ptr();
    //use_shared_ptr();
    linkedref();

    auto up = std::make_unique<int>(4);
    auto sp = std::shared_ptr<int>(std::move(up));

    auto sp1 = std::shared_ptr<int>(intFactory());
    std::shared_ptr<int> sp2 = intFactory();

    
}