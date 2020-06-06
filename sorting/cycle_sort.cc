// This algorithm is used to sort elements in minimum jumber of writes
// complexity O(N^2)

#include <iostream>
#include <vector>

void cycle_sort(std::vector<int>& arr){
    int writes = 0;

    for(int cycle_start = 0; cycle_start < arr.size() - 1; cycle_start++){
      
        // Find position where this index item belongs;
        int pos = cycle_start;
        int item = arr[cycle_start];

        for(int i = cycle_start + 1; i < arr.size(); i++){
            if(item > arr[i]) pos++;
        }

        // If we are already sorted, continue
        if(pos == cycle_start) continue;

        // Handle duplicates, get to the end of the duplicated
        while(pos < arr.size() && item == arr[pos]) pos++;

        if(pos != cycle_start){
            std::swap(item, arr[pos]);
            writes++;
        }

        // Do same thing until we restore the value in the starting position
        while(pos != cycle_start){
          pos = cycle_start;
          for(int i = cycle_start; i < arr.size(); i++){
            if(item > arr[i]) pos++;
          }

          while(pos < arr.size() && arr[pos] == item) pos++;

          if(item != arr[pos]){
            std::swap(item, arr[pos]);
            writes++;
          }
        }
    }
    std::cout<<"Number of writes to sort: "<< writes<<std::endl;
}

int main(){

    std::vector<int> arr= { 5, 2, 7, 9, 2, 6};
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    cycle_sort(arr);
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    return 0;
}
