// https://leetcode.com/problems/rotate-array/submissions/
// Given an array, rotate the array to the right by k steps, where k is non-negative.

class Solution {
public:
    void rotated(vector<int>& nums, int low, int high){
        while(low <= high){
            std::swap(nums[low++], nums[high--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()){
            k = (k % nums.size());
        }
        rotated(nums, 0, nums.size() - 1);
        rotated(nums, 0, k-1);
        rotated(nums, k , nums.size() - 1);
    }
};