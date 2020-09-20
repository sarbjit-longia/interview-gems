//https://leetcode.com/problems/is-graph-bipartite/

class Solution {
 	public:
 		bool isBipartite(vector<vector<int>>& graph) {
 			int n = graph.size();
 			vector<int>color(n, -1);

 			for (int i = 0; i < n; i++) {
 				if (color[i] != -1) continue;

 				color[i] = 1;
 				queue<int>q;
 				q.push(i);

 				while (!q.empty()) {
 					int t = q.front();
 					q.pop();

 					for (int j = 0; j < graph[t].size(); j++) {
 						if (color[graph[t][j]] == -1) {
 							color[graph[t][j]] = 1-color[t];
 							q.push(graph[t][j]);
 						} else if (color[graph[t][j]] == color[t]) {
 							return false;
 						}
 					}
 				}
 			}

 			return true;
 		}
};
