//https://leetcode.com/problems/interval-list-intersections/submissions/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        int n = firstList.size();
        int m = secondList.size();

        int ni = 0;
        int mi = 0;

        vector<vector<int>> result;

        while(ni < n && mi < m){

            int lo = max(firstList[ni][0], secondList[mi][0]);
            int hi = min(firstList[ni][1], secondList[mi][1]);

            if(lo <= hi)
                result.push_back({lo, hi});

            if(firstList[ni][1] < secondList[mi][1]){
                ni++;
            }
            else{
                mi++;
            }
        }
        return result;
    }
};