//https://leetcode.com/problems/spiral-matrix/submissions/

#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0, r = m-1, t = 0, b = n- 1;
        while(result.size() < (m * n)){

            for(int i = l; i <= r; i++){
                result.push_back(matrix[t][i]);
            }
            if(result.size() == m * n) break;
            for(int i = ++t; i <= b; i++){
                result.push_back(matrix[i][r]);
            }
            if(result.size() == m * n) break;
            for(int i = --r; i >= l; i--){
                result.push_back(matrix[b][i]);
            }
            if(result.size() == m * n) break;
            for(int i = --b; i>= t; i--){
                result.push_back(matrix[i][l]);
            }
            l++;
        }
        return result;
    }
};