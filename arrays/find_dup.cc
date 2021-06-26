/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Floyd's Algorithm, O(N)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow_pointer = nums[0];
        int fast_pointer = nums[0];

        do{
            //  1️⃣ collision
            slow_pointer = nums[slow_pointer];
            fast_pointer = nums[nums[fast_pointer]];
        }while(slow_pointer!=fast_pointer);

        fast_pointer = nums[0];

        while(slow_pointer!=fast_pointer){
            //  2️⃣ collision
            slow_pointer = nums[slow_pointer];
            fast_pointer = nums[fast_pointer];
        }

        return fast_pointer;
    }
};