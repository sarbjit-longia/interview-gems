// https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> indegree(numCourses, 0);
        std::vector<int> result;

        std::vector<std::vector<int> > nodes(numCourses);

        for(int i = 0; i <prerequisites.size() ;i++){
            nodes[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i < nodes.size(); i++){
            for(int j = 0; j < nodes[i].size(); j++){
                indegree[nodes[i][j]]++;
            }
        }

        std::vector<int> temp;

        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) temp.push_back(i);
        }

        while(!temp.empty()){

            auto e = temp.back();
            temp.pop_back();
            result.push_back(e);

            for(int i = 0; i < nodes[e].size(); i++){
                indegree[nodes[e][i]]--;
                if(indegree[nodes[e][i]] == 0)
                    temp.push_back(nodes[e][i]);
            }
        }

        for(int i = 0; i <indegree.size(); i++){
            if(indegree[i] > 0) return false;
        }

        return true;
    }
};