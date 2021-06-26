//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() <= 2)return nums.size();
        int i=1;
        for(int j=2;j<nums.size();j++)
        {
            if(nums[i-1] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};