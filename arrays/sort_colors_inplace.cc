//https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0; int e = nums.size() - 1;

        // !!!!! Pay        V attention here, we are using end as loop count
        for(int i = 0; i <= e; i++){
            if(nums[i] == 0){
                std::swap(nums[s], nums[i]);
                s++;
            }
            else if(nums[i] == 2){
                std::swap(nums[e], nums[i]);
                e--;
                i--; // !!!!! Pay attention here
            }
        }
    }
};