#include <iostream>
#include <vector>


void counting_sort(std::vector<int>& a){
  std::vector<int> index(10, 0);
  for(auto e: a) index[e]++;

  for(int i = 1; i <index.size(); i++){
      index[i] += index[i-1];
  }

  auto temp = a;
  for (int i = 0; i < a.size(); i++){
      auto pos = index[temp[i]] - 1;
      index[temp[i]]--;
      a[pos] = temp[i];
  }
}

int main(int argc, char* argv[]){

    std::vector<int> arr = {1, 3, 2, 9, 4, 7, 7, 2};

    counting_sort(arr);
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout<<std::endl;
    return 0;
}
