#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <pair<int,int>> st;
        int area=0;

        //traverse all index while computing area when pop out
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[i]<=st.top().first)
            {
                auto temp =st.top();
                st.pop();
                int left= (st.empty())?-1:st.top().second;
                int temp_area =(i-left-1)*temp.first;
                area=max(temp_area,area);
            }
            st.push(make_pair(heights[i],i));

        }
        //pop each element from stack and compute them too
        while(!st.empty())
        {
            auto temp = st.top();
            st.pop();
            int left = (st.empty())?-1:st.top().second;
            int temp_area =((heights.size()-left-1)*temp.first);
            area= max(temp_area,area);
        }
        return area;
    }
};