// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while(s <= e){
            int m = (s + e) / 2;

            if(nums[m] == target) return true;

            if(nums[s] == nums[m] && nums[m] == nums[e]){
                s++;
                e--;
            }

            else if(nums[s] <= nums[m]){
                // left is sorted
                if(nums[s] <= target && target <= nums[m]){
                    e = m-1; // Normal decision
                }
                else{
                    s = m+ 1;
                }
            }
            else{
                // Right is sorted
                if(nums[m] <= target && target <= nums[e]){
                    s = m+1;
                }
                else{
                    e = m- 1;
                }
            }
        }
        return false;
    }
};