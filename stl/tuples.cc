#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

int main(int arc, char* argv[]){

    std::vector<std::tuple<int, int, int> > arr;
    arr.push_back({1, 3, 5});
    arr.push_back({7, 3, 5});
    arr.push_back({1, 8, 5});

    std::sort(std::begin(arr), std::end(arr));

    for(auto e : arr){
        int one, two, three;
        std::tie(one, two, three) = e;
        std::cout<<one<<", "<< two<<",  "<<three<<"\n";
    }
    return 0;
}
