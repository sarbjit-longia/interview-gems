#include <iostream>
#include <vector>


void counting_sort(std::vector<int>& a){
  std::vector<int> count(10, 0);
  for(auto e: a) count[e]++;

  for(int i = 1; i <count.size(); i++){
      count[i] += count[i-1];
  }
  
  for(int i = 0; i < count.size(); i++){
    a[count[i]] = i;
    count[i]--;
  }
}

int main(int argc, char* argv[]){

    std::vector<int> arr = {1, 3, 2, 9, 4, 7, 7, 2};

    counting_sort(arr);
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout<<std::endl;
    return 0;
}
