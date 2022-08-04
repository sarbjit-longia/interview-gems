//https://leetcode.com/ /continuous-subarray-sum/submissions/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m.insert({0,-1});
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            int rem=sum%k;
            if(m.find(rem)!=m.end() and i-m[rem]>1)
            {
                return true;
            }
            else
            {
                m.insert({rem,i});
            }
        }
        return false;
    }
};