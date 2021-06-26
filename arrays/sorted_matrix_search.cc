// https://leetcode.com/problems/search-a-2d-matrix/submissions/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int loR = 0, hiR = m-1;

        while(loR<=hiR){
            int mid = loR + (hiR - loR)/2;

            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
                loR = mid + 1;
            else
                hiR = mid - 1;
        }

        if(loR<=0)
            return false;

        int r = loR-1;

        int loC = 0, hiC = n-1;

        while(loC <= hiC){
            int mid = loC + (hiC - loC)/2;

            if(matrix[r][mid] == target)
                return true;
            else if(matrix[r][mid] < target)
                loC = mid+1;
            else
                hiC = mid-1;
        }

        return false;
    }
};