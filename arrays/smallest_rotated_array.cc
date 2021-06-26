//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/

class Solution {
public:
    int find_pivot(vector<int>& nums){
        if(nums[0] < nums[nums.size() - 1]) return -1; // 0 rotations
        if(nums.size() == 1) return 0;

        int s = 0;
        int e = nums.size() - 1;

        while(s <= e){
            int m = (s + e) / 2;
            if(nums[m] > nums[m + 1]) return m + 1;

            if(nums[s] < nums[m]){
                // left is sorted
                s = m + 1;
            }
            else{
                e = m;
            }
        }
        return 0;
    }
    int findMin(vector<int>& nums) {
        auto idx = find_pivot(nums);
        if(idx == -1) return nums[0];
        return nums[idx];
    }
};