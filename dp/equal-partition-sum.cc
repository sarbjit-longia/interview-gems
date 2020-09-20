//https://leetcode.com/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto n: nums) total += n;
        
        if(total % 2 != 0) return false;
        
        auto target = total / 2;
        
        vector<int> dp(target + 1, false);
        dp[0] = true;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = target; j >= nums[i]; j--){
                // Either you include this number or you dont
                // Update the dp index accordingly
                dp[j] = dp[j] | dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};

int main(){
    std::vector<int> arr = { 1, 5, 5, 11};
    Solution s;
    std::cout<<"Partition result: "<<s.canPartition(arr);
    return 0;
}
