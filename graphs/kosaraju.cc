//https://www.youtube.com/watch?v=Rs6DXyWpWrI

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>


using namespace std;
#define V 8
#define pb push_back

unordered_map<int,vector<int>> adj,rev;

void dfs1(int u, vector<bool>& vis, stack<int>& st){
    vis[u] = true;

    for (auto v : adj[u]){
        if(!vis[v])
            dfs1(v, vis, st);
    }
    st.push(u);
}

void reverse(){
    for (int i = 0; i < V; i++){
        for(int v : adj[i])
            rev[v].pb(i);
    }
}

void dfs2(int u, vector<bool>& vis, vector<int>& result){
    result.push_back(u);
    vis[u] = true;

    for (auto v : rev[u]){
        if(!vis[v])
            dfs2(v, vis, result);
    }
}

void findSCCs()
{
    stack<int> st;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++){
        if(!vis[i])
            dfs1(i, vis, st);
    }
    reverse();

    std::fill(vis.begin(), vis.end(), false);

    while(!st.empty()){
        auto e = st.top();
        st.pop();

        vector<int> scc;

        if(!vis[e]){
            dfs2(e, vis, scc);
            std::copy(scc.begin(), scc.end(), std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl;
        }
    }
}

int main()
{
	adj[0].pb(1);
    adj[1].pb(2);
    adj[2].pb(0);
	adj[2].pb(3);
	adj[3].pb(4);
	adj[4].pb(5);
	adj[4].pb(7);
	adj[5].pb(6);
	adj[6].pb(4);
	adj[6].pb(7);

	findSCCs();
	return 0;
}

//TIME COMPLEXITY: O(V+E)