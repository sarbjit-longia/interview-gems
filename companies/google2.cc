//https://leetcode.com/discuss/interview-question/1232885/Google-Interview-Question

#include <iostream>
#include <vector>

enum
{
    GREEN=1,
    RED,
    BLUE
};

#ifdef TRUE
bool is_complete(std::vector<std::vector<bool> >& visited){
    for (int i = 0; i < visited.size(); i++){
        for (int j = 0; j < visited[0].size(); j++){
            if(visited[i][j] == false)
                return false;
        }
    }
    return true;
}

void dfs(std::vector<std::vector<int> >& grid, int i, int j,
            std::vector<std::vector<bool> >& visited, long& curr_ways, std::vector<int> colors){
    if(i < 0 || j < 0 || i >= visited.size() || j >= visited[0].size())
        return;
    if(visited[i][j])
        return;

    std::cout << "Visiting: " << i << ", " << j << std::endl;
    visited[i][j] = true;
    if(is_complete(visited))
        curr_ways++;
    for (int i = 0; i < colors.size(); i++)
    {
        std::vector<int> vec = colors;
        vec.erase(std::remove(vec.begin(), vec.end(), colors[i]), vec.end());
        dfs(grid, i - 1, j, visited, curr_ways, vec);
        dfs(grid, i + 1, j, visited, curr_ways, vec);
        dfs(grid, i, j - 1, visited, curr_ways, vec);
        dfs(grid, i, j + 1, visited, curr_ways, vec);
    }
}

long ways_to_color(int m, int n){
    long ans = 0;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            std::vector<std::vector<int> > grid(m, std::vector<int>(n, 0));
            std::vector<std::vector<bool> > visited(m, std::vector<bool>(n, false));
            long curr_ways = 0;
            std::vector<int> colors = {GREEN, RED, BLUE};
            dfs(grid, i, j, visited, curr_ways, colors);
            ans += curr_ways;
        }
    }
    return ans % 10000000007;
}
#endif
int main(){
    //std::cout << "Number of ways: " << ways_to_color(3, 1) << std::endl;
    //std::cout << "Number of ways: " << ways_to_color(3, 2) << std::endl;
    //std::cout << "Number of ways: " << ways_to_color(5, 5) << std::endl;
    return 0;
}
