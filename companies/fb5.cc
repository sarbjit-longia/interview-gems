//https://leetcode.com/problems/subarray-sum-equals-k/
// Approach: Use prefix sum
// Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        if(nums.size() == 0) return 0;

        int ans = 0;
        int n = nums.size();

        std::unordered_map<int, int> c;
        c[0] = 1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(c.find(sum - k) != c.end()){
                ans += c[sum - k];
            }
            c[sum]++;
        }

        return ans;
    }
};