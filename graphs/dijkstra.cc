#include <iostream>
#include <queue>
#include <list>
#include <algorithm>

typedef std::pair<int, int> iPair;

class Graph{

public:
  Graph(int n) {
    n_ = n;
    adj_ = new std::list<iPair>[n];
  }
  
  void addEdge(int x, int y, int weight){
    adj_[x].push_back(std::make_pair(y, weight));
    adj_[y].push_back(std::make_pair(x, weight));
  }

  void solve(int s){
      distance_.assign(n_, INT_MAX);
      std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair> > pq;
      pq.push(std::make_pair(0, s)); // Its reverse here the weight is first as we need sorting on weight
      distance_[s] = 0;

      while(!pq.empty()){
        auto e = pq.top(); pq.pop();
        auto u = e.second;

        for(auto it = adj_[u].begin(); it!= adj_[u].end(); it++){
            auto v = it->first;
            auto w = it->second;
            if(distance_[u] + w < distance_[v]){
              distance_[v] = distance_[u] + w;
              pq.push(std::make_pair(distance_[u], v));
            }
        }
      }
      // Print shortest distances stored in dist[] 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < n_; ++i) 
        std::cout<<i<<"  \t\t "<< distance_[i]<<"\n"; 
  }

private:
  int n_;
  std::list<iPair>*  adj_;
  std::vector<int> distance_;
};

int main(){
    
    Graph g(9);

    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7);

    g.solve(0);

    return 0;
}
