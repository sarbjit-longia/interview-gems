//https://leetcode.com/problems/maximum-product-subarray/
/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
It is guaranteed that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_ending_here = nums[0];
        int max_so_far = nums[0];
        int min_ending_here = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int t = max_ending_here;
            max_ending_here = max({nums[i], max_ending_here * nums[i], min_ending_here * nums[i]});
            min_ending_here = min({nums[i], t * nums[i], min_ending_here * nums[i]});
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};