/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
https://leetcode.com/problems/word-break/
*/
class Solution {
public:

    bool util(string name, int start, std::set<string>& cache, vector<int>& memo){ //O(n^3)
        if(start == name.length()) return true;

        auto curr_str = name.substr(start);
        if(cache.count(curr_str)) return true;

        //std::cout<<curr_str<<", start: "<< start<<std::endl;
        if(memo[start] != -1) return memo[start];

        for(int end = start + 1; end <= name.length(); end++){
            auto sub = name.substr(start, end - start);
            if(cache.count(sub)){
                //std::cout<<"found:" << sub<<std::endl;
                if(util(name, end, cache, memo)){
                    memo[start] = true;
                    return true;
                }
            }
        }

        memo[start] = false;
        return false;
    }

    bool wordBreak(string name, vector<string>& wordDict) {
        std::set<string> cache;
        vector<int> memo(name.length(), -1);
        for(auto e : wordDict) cache.insert(e);
        return util(name, 0, cache, memo);
    }

};