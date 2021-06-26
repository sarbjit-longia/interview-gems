//https://leetcode.com/problems/word-search/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, std::vector<std::vector<bool> >& visited){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(word[0] != board[i][j]) return false;

        if(visited[i][j]) return false;

        visited[i][j] = true;
        if(word.length() == 0) return true;


        if(word.length() == 1) return true;

        auto right = dfs(board, word.substr(1), i, j + 1, visited);
        auto left = dfs(board, word.substr(1), i, j -1, visited);
        auto up = dfs(board, word.substr(1), i - 1 , j, visited);
        auto down = dfs(board, word.substr(1), i + 1, j, visited);

        if( up || down || right || left) return true;
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                std::vector<std::vector<bool> > visited(board.size(), std::vector<bool>(board[0].size(), false));
                if(dfs(board, word, i, j, visited)) return true;
            }
        }
        return false;
    }
};