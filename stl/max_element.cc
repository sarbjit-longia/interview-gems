#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> cloud = { 1,2,3,4,-7,999,5,6 };

    std::cout << *std::max_element(std::begin(cloud), std::end(cloud)) << '\n';
    std::cout << *std::min_element(std::begin(cloud), std::end(cloud)) << '\n';

    return 0;
}
