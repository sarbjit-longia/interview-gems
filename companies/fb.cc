#include <vector>

#include <queue>
#include <iostream>

//[5, 3, 9, 1]
//k = 0 => 9
//k = 1 => 5

// Empty array
// k < 0
// -ve values in array
// Overflow

int getKthLargest(std::vector<int>& arr, int k){
  /*****
  If there is an empty array or k < 0, it shall return -1
  ****/
  
  if(arr.size() == 0 || k < 0) return -1;
  
  
  std::priority_queue<int, std::vector<int> , std::greater<int> > pq;
  
  for(auto i = 0; i < arr.size(); i++){  // O(N)
   
    if(pq.size() > k){
      auto topElement = pq.top();  
      if(arr[i] > topElement){
        pq.pop();
        pq.push(arr[i]);  // O(LogN)
      }
    }
    else{
      pq.push(arr[i]);  // O(LogN)
    }
  }
  
  return pq.top();
}


/*
[5]
[3, 5]
[5, 9]
*/

//[1, 3, 1, 4, 23], k=8 # True (because 3 + 1 + 4 = 8)
//[1, 3, 1, 4, 23], k=2 # False
//[1, 3], k=2


bool findKthSum(std::vector<int>& arr, int k){
 
  // TODO validations
  
  int start = 0;
  int end = 1;
  
  int sum = arr[0];
  while(end < arr.size()){  // O(N)
    
    while(start < end && arr[end] + sum > k){
      start++; 
      sum -= arr[start];
    }
                    
    sum += arr[end];
    if(arr[end] + sum == k) return true;
    end++;
  }
  return false;

}


int main(){

    std::vector<int> arr = {1, 3, 1, 4, 23};
    std::cout<<findKthSum(arr, 8)<<"\n";
    std::cout<<findKthSum(arr, 2)<<"\n";
  return 0;

}


