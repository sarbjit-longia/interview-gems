#include <iostream>
#include <vector>

using namespace std;
// funtion that gives me the water between two points
// Complexity: O(N)

// funtion that gives me the water between two points
// Complexity: O(N)
// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:

    int trap(vector<int>& height) {
        int result =0 ;

        if(height.size() == 0) return 0;
        int n = height.size();

        vector<int> left(n);
        vector<int> right(n);

        left[0] = height[0];
        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1] , height[i]);
        }

        right[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            right[i] = max(right[i+1] , height[i]);
        }

        for(int i = 0; i < n; i++){
            result += min(left[i], right[i]) - height[i];
        }

        return result;
    }
};
int main(){

    Solution s;
    std::vector<int> in = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    auto result = s.trap(in);
    std::cout << result << std::endl;
    return 0;
}