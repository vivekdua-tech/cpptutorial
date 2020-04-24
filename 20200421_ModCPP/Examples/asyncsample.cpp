#include <iostream>
#include <future>


int main()
{
    using namespace std::literals;
    auto somedata = "some information"s;

    auto fut = std::async(std::launch::async,
        [mydata=somedata] {
            // wait for start event
            using namespace std::chrono_literals;
            std::cerr << "lambda thread running with : " << mydata << "\n";

            for (auto i = 0; i < 100; ++i)
            {
                std::cerr << '.';
                std::this_thread::sleep_for(10ms);
            }
            throw std::bad_function_call();
            std::cerr << "\n";
            return "the result"s;
        }
    );

    for (auto i = 0; i < 100; ++i)
    {
        std::cerr << '+';
        std::this_thread::sleep_for(1ms);
    }

    try {
        auto result = fut.get();
        std::cout << "returned : " << result << '\n';
    } catch (...) { 
        std::cout << "exception\n"; 
    }

    std::cout << "leaving main\n";
}