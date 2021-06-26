/*
0001000
0011100
0000011
0100000
1110000
given a matrix of 0's and 1's return the maximum repeating shape in in the matrix. A shape is denoted by a grouping of 1s from above, under, left, and right.

in this secnario the answer would be 2, and the maximum repeating shape is
 1
111
*/
#include <iostream>
#include <vector>
#include <map>


class CountShapes final{
 public:
    CountShapes(std::vector<std::vector<int> > grid){
        grid_ = grid;
        rows_ = grid.size();
        cols_ = grid[0].size();
    }

    void dfs(int i, int j, std::string& signature, std::string pos){

        if (i < 0 || j < 0 || i >= rows_ || j >= cols_)
            return;
        if(grid_[i][j] != 1)
            return;

        grid_[i][j] = -1;
        signature += pos;
        dfs(i, j+1, signature, "RIGHT");
        dfs(i + 1, j, signature, "DOWN");
        dfs(i - 1, j, signature, "UP");
        dfs(i, j - 1, signature, "LEFT");
    }

    int countShapes(){
        std::map<std::string, int> signatures;

        for (int i = 0; i < rows_; i++){
            for (int j = 0; j < cols_;  j++) {
                if(grid_[i][j] == 1){
                    std::string signature;
                    dfs(i, j, signature, "ROOT");
                    signatures[signature]++;
                }
            }
        }
        int max_val = INT_MIN;
        for (auto it = signatures.begin(); it != signatures.end(); it++) {
            max_val = std::max(max_val, it->second);
            std::cout << it->first <<" -> " << it->second << std::endl;
        }
        return max_val;
    }

private:
    std::vector<std::vector<int> > grid_;
    int rows_;
    int cols_;
};

int main(){
    std::vector<std::vector<int> > grid = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 1, 0, 0},
    };

    CountShapes s(grid);
    std::cout << "Max count: " << s.countShapes() << std::endl;
    return 0;
}