//https://leetcode.com/problems/max-area-of-island/

class Solution {
public:

    void dfs(vector<vector<int>>& grid, int x, int y, int& cmax){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()){
            return;
        }
        if(grid[x][y] != 1) return;

        grid[x][y] = -1;
        cmax++;
        dfs(grid, x+1, y, cmax);
        dfs(grid, x-1, y, cmax);
        dfs(grid, x, y+1, cmax);
        dfs(grid, x, y-1, cmax);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;

        int max_area = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int curr_max = 0;
                    dfs(grid, i, j, curr_max);
                    max_area = std::max(max_area, curr_max);
                }
            }
        }
        return max_area;
    }
};