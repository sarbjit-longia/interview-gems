// Approach: Use stack to push the open brackets and pop when encountered close one
// Complexity: O(N)
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/submissions/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.length() == 0) return "";

        std::stack<int> st;
        std::string result = "";
        unordered_set<int> to_remove;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.size() > 0){
                    st.pop();
                }
                else{
                    to_remove.insert(i);
                }
            }
        }
        while(!st.empty()) to_remove.insert(st.top()), st.pop();

        std::stringstream ss;
        for(int i = 0 ; i < s.length(); i++){
            if(!to_remove.count(i)) ss << s[i];
        }
        return ss.str();
    }
};