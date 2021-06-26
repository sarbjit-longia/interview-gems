/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n]
and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/

class Solution {
public:
    //in this we have given a special property elements are from 1 to n and no
    //element is more than twice
    //we treat numbers as indexes, thats why this question becomes different
    //numbers are from 1 to n and indexes are 0 - n-1

	vector<int> findDuplicates(vector<int>& nums) {
	   vector<int> res;
		for(int i = 0; i < nums.size(); i++){
            //here we checking indexes
            //if index is greater than 0 means we are coming here 1st time
            //so we add -ve to that index
			nums[abs(nums[i]) - 1] *= -1;   // -1 because of 1 based and not 0 based numbers

            //else this is -ve, we come back 2nd time so add that element
			if(nums[abs(nums[i]) - 1] > 0){
				res.push_back(abs(nums[i]));
			}
		}
		return res;
	}
};