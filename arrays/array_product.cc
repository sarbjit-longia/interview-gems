/*
Given an integer array nums, return an array answer such that answer[i] is equal to the
product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

https://leetcode.com/problems/product-of-array-except-self/

https://www.youtube.com/watch?v=bNvIQI2wAjk
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> pre(nums.size() + 1, 1);
        std::vector<int> suf(nums.size() + 1, 1);

        for(int i = 0; i < nums.size(); i++){
            pre[i+1] = pre[i] * nums[i];
        }
        for(int i = nums.size() - 1; i >=0 ; i-- ){
            suf[i] = suf[i+1] * nums[i];
        }

        vector<int> res(nums.size(), 1);
        for(int i = 0 ;i < nums.size(); i++){
            res[i] = pre[i] * suf[i+1];
        }
        return res;
    }
};