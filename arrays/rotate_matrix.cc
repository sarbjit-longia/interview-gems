#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    void print(vector<vector<int> >& matrix){
        std::cout<<"----------\n";
        for(int i = 0; i < matrix.size(); i++){
            std::copy(matrix[i].begin(), matrix[i].end(), std::ostream_iterator<int>(std::cout, " "));
            std::cout<<std::endl;
        }
    }
    void rotate(vector<vector<int> >& matrix) {
        int_fast8_t n = matrix.size();
        for(int_fast8_t i = 0 ; i < n ; i++)
            for(int_fast8_t j = 0 ; j <= i ; j++){
                swap(matrix[i][j],matrix[j][i]);
                print(matrix);
            }


        for(int_fast8_t i = 0 ; i < n ; i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};