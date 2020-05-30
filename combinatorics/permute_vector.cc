#include <iostream>
#include <vector>

std::vector<std::vector<int> > result;

void permute(std::vector<int>& arr, int s, int e){
  if(s == e){
    result.push_back(arr);
  }
  
  for(int i = s; i <= e; i++){
    std::swap(arr[i], arr[s]);
    permute(arr, s + 1, e);
    std::swap(arr[i], arr[s]);
  }
}

int main(){
    std::vector<int> arr = {3, 5, 1, 7};
    permute(arr, 0, arr.size() - 1);
    
    std::cout<<"Number of permutations generated: "<< result.size()<<std::endl;
    for(int i = 0; i <result.size(); i++){
      std::copy(result[i].begin(), result[i].end(), std::ostream_iterator<int>(std::cout, " "));
      std::cout<<std::endl;
    }

    return 0;
}
