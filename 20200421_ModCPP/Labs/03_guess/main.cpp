#include <random>
#include <iostream>

int main()
{
    std::random_device r;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, 99);

    int thenumber = uniform_dist(e1);
    std::cout << "Try and guess the number between 0 and 99.\n";

    std::vector<int> guesses;
    int guess = 0;
    std::string line;
    for (int i = 0; std::getline(std::cin, line), i < 5; ++i) {
        guess = std::stoi(line);
        guesses.push_back(guess);
        if (guess == thenumber) {
            std::cout << "Congrats you guessed it!!!\n";
            break;
        }
        if (guess > thenumber) {
            std::cout << "lower\n";
        } else {
            std::cout << "higher\n";
        }
    }
    if (guess != thenumber) {
        std::cout << "Sorry no guesses left, the number was " << thenumber << '\n';
    }
    std::cout << "Your guesses were:\n";
    for (auto g : guesses) {
        std::cout << g << ",";
    }
    std::cout << std::endl;
}