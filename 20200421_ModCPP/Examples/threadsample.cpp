#include <iostream>
#include <thread>
#include "threadraii.h"

void FuncA() {
    using namespace std::chrono_literals;

    for (auto i = 0; i < 100; ++i)
    {
        std::cerr << '.';
        std::this_thread::sleep_for(10ms);
    }
    
	std::cerr << "\n";
}

void process(std::string somedata) {
    using namespace std::chrono_literals;

	std::cout << "in process\n";

    auto traii = ThreadRAII(std::thread{ 
        [mydata=somedata] {
            // wait for start event
            using namespace std::chrono_literals;
            std::cerr << "lambda thread running with : " << mydata << "\n";

            for (auto i = 0; i < 100; ++i)
            {
                std::cerr << '.';
                std::this_thread::sleep_for(10ms);
            }
            
            std::cerr << "\n";
        }
     }, &std::thread::detach);
     // fire start event
    std::thread & t1 = traii.get();
    std::cout << std::boolalpha << t1.joinable() << '\n';

    std::this_thread::sleep_for(100ms);
    //t1.detach();
    //t1.join();
    std::cout << std::boolalpha << t1.joinable() << '\n';
	std::cout << "leaving process\n";
}

int main() {
    process("some data");
	std::cout << "exiting main\n";
}
