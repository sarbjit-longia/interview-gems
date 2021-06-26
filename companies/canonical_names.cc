//https://leetcode.com/problems/simplify-path/submissions/

#include <regex>
#include <iostream>
#include <queue>

class Solution {
public:
    string simplifyPath(string path) {
        std::queue<string> q;

        std::string token;
        std::istringstream ss(path);

        while(getline(ss, token, '/')){
            auto t = std::regex_replace(token, std::regex("/"), "");
            if (t.length() == 0) continue;
            q.push(t);
        }

        std::stack<std::string> st;
        while(!q.empty()){
            auto e = q.front(); q.pop();
            if(e == ".") continue;
            else if(e == "..") {
                if  (st.size() == 0 )
                    continue;
                else
                    st.pop();
            }
            else{
                st.push(e);
            }
        }
        std::string ans = "";
        while(!st.empty()){
            auto e = st.top(); st.pop();
            ans = "/" + e + ans;
        }
        return (ans.length() > 0) ? ans : "/";
    }
};