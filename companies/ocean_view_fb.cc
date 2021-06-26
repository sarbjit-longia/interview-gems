// https://leetcode.com/discuss/interview-experience/713601/Facebookor-E5or-Phone-Screenor-NYC/602013

#include <iostream>
#include <stack>
#include <vector>

std::vector<int> ocean_view(std::vector<int>& arr){
    std::stack<int> st;
    // For this we maintain monotonic increasing stack and when we encounter
    // value bigger than top of stack we take out stuff
    // TODO: can use deque instead of stack too to make it easier to return vector
    for (auto entry : arr){
        if(st.empty()){
            st.push(entry);
        }
        else{
            auto ts = st.top();
             while(entry >= ts){
                st.pop();
                if(st.empty())
                    break;
                ts = st.top();
            }
            st.push(entry);
        }
    }
    std::vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    std::vector<int> arr = {3, 4, 4, 3, 2, 1};
    std::vector<int> result = {4, 3, 2, 1};

    bool success = (result == ocean_view(arr));
    std::cout << (success ? "PASSED" : "FAILED");
    return 0;
}