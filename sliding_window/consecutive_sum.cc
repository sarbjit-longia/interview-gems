//https://leetcode.com/problems/minimum-size-subarray-sum/
/*
Given an array of positive integers nums and a positive integer target,
return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr]
of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_count = INT_MAX;
        int curr_sum = 0;
        int curr_start_index = 0;
        int s = 0;

        while(s < nums.size()){
            curr_sum += nums[s];
            if(curr_sum >= target){
                while(curr_sum >= target){
                    min_count = std::min(min_count, s - curr_start_index + 1);
                    curr_sum -= nums[curr_start_index];
                    curr_start_index++;
                }
            }
            s++;
        }

        if(min_count == INT_MAX) return 0;

        return min_count;
    }

};