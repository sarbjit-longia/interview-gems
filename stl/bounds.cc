#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

int main(int arc, char* argv[]){

    std::vector<int > arr = {5, 2, 8, 3, 5, 7, 7, 1, 0, -10};
    std::sort(std::begin(arr), std::end(arr));

    std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, " "));
    //Perform binary search
    auto lb = std::lower_bound(std::begin(arr), std::end(arr), 5);
    auto ub = std::upper_bound(std::begin(arr), std::end(arr), 5);
    auto eb = std::equal_range(std::begin(arr), std::end(arr), 5);
    std::cout<<"Number 5 found at location: "<<std::distance(arr.begin(), lb)<<std::endl;
    std::cout<<"Number of 5 found: "<<ub-lb<<std::endl;
    std::cout<<"In one shot. number of 5s :"<< eb.second - eb.first<<std::endl;

    auto llb = std::lower_bound(std::begin(arr), std::end(arr), 4);
    std::cout<<"Trying to find non existing 4 returned location shall be less than value: "<< std::distance(arr.begin(), llb)<<std::endl;
    return 0;
}
