//https://leetcode.com/problems/unique-paths/submissions/

class Solution {
public:
    void print(std::vector<std::vector<int> >& dp){
        for(int i = 0; i < dp.size(); i++){
            std::copy(dp[i].begin(), dp[i].end(), std::ostream_iterator<int>(std::cout, " "));
            std::cout<<std::endl;
        }
    }
    int uniquePaths(int m, int n) {
        if(m == 0|| n == 0) return 0;

        std::vector<std::vector<int> > dp(m, std::vector<int>(n, 0));

        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
        for(int i = 0; i < n; i++)
            dp[0][i] = 1;

        for(int r = 1; r < m; r++){
            for(int c = 1; c < n; c++){
                dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }
        print(dp);
        return dp[m-1][n-1];
    }
};