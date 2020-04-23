#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>

bool isOdd(int val) 
{
    return val % 2;
}

struct isDivBy
{
    isDivBy(int _div) : div(_div) {}
    bool operator()(int val) const { return !(val % div); }
    int div;
};

struct  MyStruct
{
    MyStruct(int _div) : div(_div) {}
    std::function<bool(int)> createFunctor() {
        auto localDiv = div;
        //return [=](int val) { return !(val % div); }; // do not use default capture modes
        return [*this](int val) { return !(val % div); };
        //return [localDiv](int val) { return !(val % localDiv); };
    }
    auto createLambda() {
        auto localDiv = div;
        //return [=](int val) { return !(val % div); }; // do not use default capture modes
        return [*this](int val) { return !(val % div); };
        //return [localDiv](int val) { return !(val % localDiv); };
    }
    int div;
};

struct MyUniquePtrLambda
{
    MyUniquePtrLambda(std::unique_ptr<int> _ptr) : ptr(std::move(_ptr)) {}
    bool operator()(int val) const { return !(val % *ptr); }
    std::unique_ptr<int> ptr;
};

int main()
{
    auto vec = std::vector<int>{1,2,3,4,5,6,7,8,3,4,5,6,7,9,0,3,4,5,3,4,5,6,7,6,7};
    auto upi = std::unique_ptr<int>(new int{2});

    auto count = std::count_if(std::begin(vec), std::end(vec), 
        [lupi=std::move(upi)](int val) { return !(val % *lupi); } // Lambda4
    );
    std::cout << "Num div " << 2 << "s(lambda) is " << count << '\n';  




    auto mysp = new MyStruct(7);
    auto func = mysp->createFunctor();
    delete mysp;
    mysp = new MyStruct(8);
    auto l = mysp->createLambda();
    std::cout << "Is 16 div by 8 : " << std::boolalpha << l(16) << '\n';
    std::cout << "Is 22 div by 8 : " << std::boolalpha << l(22) << '\n';
    delete mysp;

    count = std::count_if(std::begin(vec), std::end(vec), func);
    std::cout << "Num div 7s is " << count << '\n';

    count = std::count_if(std::begin(vec), std::end(vec), 
        [](int val) { return !(val % 7); }
    );
    std::cout << "Num div " << 7 << "s(lambda) is " << count << '\n';  

    count = std::count(std::begin(vec), std::end(vec), 5);

    std::cout << "Num 5s is " << count << '\n';

    count = std::count_if(std::begin(vec), std::end(vec), isOdd);
    std::cout << "Num odds is " << count << '\n';

    auto div = 8;
    auto namedTempFunctionObject = isDivBy(div);
    count = std::count_if(std::begin(vec), std::end(vec), namedTempFunctionObject);
    std::cout << "Num div 8 is " << count << '\n';

    count = std::count_if(std::begin(vec), std::end(vec), 
        [](int val) { return val % 2; }
    );
    std::cout << "Num odds(lambda) is " << count << '\n';  

    count = std::count_if(std::begin(vec), std::end(vec), 
        [div=div*2](int val) { return !(val % div); } // Lambda1
    );
    std::cout << "Num div " << div*2 << "(lambda) is " << count << '\n';  

    count = std::count_if(std::begin(vec), std::end(vec), 
        [&div](int val) { return !(val % div); } // Lambda2
    );
    std::cout << "Num div " << div << "(lambda) is " << count << '\n';  

    count = std::count_if(std::begin(vec), std::end(vec), 
        [=](int val) { return !(val % div); } // Lambda1
    );
    std::cout << "Num div " << div << "(lambda) is " << count << '\n';  

    count = std::count_if(std::begin(vec), std::end(vec), 
        [&](int val) { return !(val % div); } // Lambda2
    );
    std::cout << "Num div " << div << "(lambda) is " << count << '\n';

    auto tmp = 1;
    auto lam = [tmp]() mutable { std::cout << ++tmp << '\n'; };
    lam();
    lam();
    std::cout << "tmp is now " << tmp << '\n';

    []{ std::cout << "no params\n"; }();
}

struct Lambda1
{
    int div;
    Lambda1(int _div) : div(_div) {}
    bool operator()(int val) const { return !(val % div); }
};

struct Lambda2
{
    int &div;
    Lambda2(int &_div) : div(_div) {}
    bool operator()(int val) const { return !(val % div); }
};

struct Lambda4
{
    std::unique_ptr<int> lupi;
    Lambda4(std::unique_ptr<int> && ptr) : lupi(std::move(ptr)) {}
    bool operator()(int val) const { return !(val % *lupi); }
};
