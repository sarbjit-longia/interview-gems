/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:

    int get_index(std::vector<int>& nums, int target){
        int s = 0;
        int e = nums.size() - 1;
        int ans = nums.size();
        while(s <= e){
            int m = s+ (e-s) / 2;

            if(nums[m] >= target){
                ans = m;
                e = m-1;
            }
            else{
                s = m + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};

        auto f = get_index(nums, target);
        auto s = get_index(nums, target + 1) - 1;

        if(f > s) return {-1, -1};

        return {f, s};

    }
};