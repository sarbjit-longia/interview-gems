#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: "
              << random_variable << '\n';

    // roll 6-sided dice 20 times
    for (int n=0; n != 20; ++n) {
        std::cout << "Roll dice: " << (std::rand()  % 5) + 1 << std::endl;
    }
    return 0;
}