// This algorithm is used to sort elements when number of elements is roughly equal to
// the range of elements. It differs from counting sort such that it stores the list of
// elements at the value index
// Can be used to sort some complex objects depending upon the key,e.g. maps

// complexity O(N+Range)

#include <iostream>
#include <vector>

void pigeon_hole_sort(std::vector<int>& arr){
    int ma = *(std::max_element(arr.begin(), arr.end())); 
    int mi = *(std::min_element(arr.begin(), arr.end())); 
    std::vector<std::vector<int> > cache(ma - mi + 1);

    for(int i = 0; i < arr.size(); i++){
        cache[arr[i]-mi].push_back(arr[i]);
    }

    int idx = 0;

    for(int i = 0; i < cache.size(); i++){
        for(int j = 0; j < cache[i].size(); j++){
            arr[idx++] = cache[i][j];
        }
    }
}

int main(){

    std::vector<int> arr= { 5, 2, 7, 9, 2, 6};
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    pigeon_hole_sort(arr);
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    return 0;
}
