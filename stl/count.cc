#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> cloud = { 1,2,3,4,-7,999,5,6, 2 };

    std::cout <<"Count of 2 in vector: " << std::count(std::begin(cloud), std::end(cloud), 2) << '\n';

    return 0;
}
