//https://leetcode.com/problems/merge-intervals/submissions/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > result;
        if(intervals.size() == 0) return result;

        std::sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>& b){
            return a[0] < b[0];
        });


        std::vector<int> curr = intervals[0];
        for(int i = 1; i< intervals.size(); i++){
            auto entry = intervals[i];

            if(curr[1] >= entry[0]){
                // merge
                curr[1] = std::max(curr[1], entry[1]);
            }
            else{
                result.push_back(curr);
                curr = entry;
            }
        }
        result.push_back(curr);
        return result;
    }
};