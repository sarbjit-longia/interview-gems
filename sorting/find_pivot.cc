// Method to find the pivot point in the rotated sorted array
// The basic idea is that for a pivot point the value next to it
// is smaller than it, we use binary search to find such position

#include <iostream>
#include <vector>

int find_pivot(std::vector<int>& arr, int l, int h){
  
  if(arr[l] < arr[h]) return -1;
  int m = l + (h-l) / 2;

  if(arr[m] > arr[m+1]) return m + 1;

  if(arr[l] <= arr[m]){
    return find_pivot(arr, m + 1, h);
  }
  return find_pivot(arr, l, m-1);
}

int find_pivot_iterative(std::vector<int>& arr){
  if(arr[0] < arr[arr.size() - 1]) return -1; // 0 rotations
  if(arr.size() == 1) return 0;

  int s = 0;
  int e = arr.size() - 1;

  while(s <= e){
      int m = (s + e) / 2;
      if(arr[m] > arr[m + 1]) return m + 1;

      if(arr[s] < arr[m]){
         // Left is sorted so no need to look there, look other way
         s = m + 1;
      }
      else{
          e = m;
      }
  }
  return 0;
}

int main(){
    std::vector<int> arr = {3, 4, 5, 6, 1, 2 };
    std::vector<int> arr2 = {3, 4, 5, 6 };
    std::cout<<"Pivot found at index: "<< find_pivot(arr, 0, arr.size() - 1)<<std::endl;
    std::cout<<"Pivot found at index: "<< find_pivot(arr2, 0, arr2.size() - 1)<<std::endl;
    std::cout<<"Pivot found at index: "<< find_pivot_iterative(arr)<<std::endl;
    std::cout<<"Pivot found at index: "<< find_pivot_iterative(arr2)<<std::endl;
    return 0;
    return 0;
}
