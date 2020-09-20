// Longest increasing sub sequence
#include <iostream>
#include <vector>

int lis(std::vector<int>& arr){
    int ans = 0;
    std::vector<int> dp(arr.size(), 0);
    dp[0] = 1;

    for(int i = 1; i < arr.size(); i++){
        int maxVal = 0;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                // Find the maximum count at j and compare with self
                maxVal = std::max(maxVal, dp[j]);
            }
        }
        dp[i] = maxVal + 1;
        ans = std::max(dp[i], ans);
    }
    return ans;
}

int main(){
    std::vector<int> arr = {10,9,2,5,3,7,101,18};
    std::cout<<"Longest increasing subsequence: "<< lis(arr) << std::endl;
    return 0;
}

