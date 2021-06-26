//https://leetcode.com/problems/word-break-ii/

class Solution {
public:

    void wordBreak(string s, unordered_set<string>& dict, string result, vector<string>& ans) {
        if (s.empty()) {
            result.pop_back();
            ans.emplace_back(result); return;
        }

        for (int i = 0; i <= s.size(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (dict.count(left)) {
                string old = result;
                result += left + ' ';
                wordBreak(right, dict, result, ans);
                result = old;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        string result;
        vector<string>ans;
        wordBreak(s, dict, result, ans);
        return ans;
    }
};