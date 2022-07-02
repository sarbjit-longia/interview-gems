#include <map>
#include <vector>

using namespace std;

class Solution
{
public:

    unordered_map<string, int> cache;
    int t[301][301];

    bool solve(string str, int s, int e){
        if(s > e) return false;

        if(t[s][e]!=-1)
            return t[s][e];

        if(cache.find(str.substr(s, e - s + 1)) != cache.end()) return true;
        bool ans=false;

        for(int i = s; i < e; i++){
            auto l = (t[s][i] != -1 )? t[s][i] : solve(str, s, i);
            auto r = (t[i+1][e] != -1 )? t[i+1][e] : solve(str, i + 1, e);
            if(l && r) ans = true;
        }
        t[s][e] = ans;
        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length() == 0) return true;
        memset(t,-1,sizeof(t));

        for(auto str: wordDict) cache[str]++;
        return solve(s, 0, s.length() - 1);
    }
};