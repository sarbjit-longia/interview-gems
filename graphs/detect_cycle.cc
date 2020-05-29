#include <iostream>
#include<vector>

class Graph {
public:
  Graph(int n){
      n_ = n;
      adj_.resize(n_);
  }

  void addEdge(int x, int y){
    adj_[x].push_back(y);
  }
  
  bool is_cycle(int s){
      std::vector<bool> visited(n_, false);
      std::vector<bool> rec_stack(n_, false);
      
      for(int i = 0; i < n_; i++){
          if(is_cycle_util(i, visited, rec_stack)) return true;
      }
      return false;
  }
  bool is_cycle_util(int s, std::vector<bool>& visited, std::vector<bool>& st){
      visited[s] = true;
      st[s] = true;

      for(int i = 0; i < adj_[s].size(); i++){
          int node = adj_[s][i];

          if(!visited[node] && is_cycle_util(node, visited, st)) return true;
          if(st[node]) return true;
      }
      st[s] = false;
      return false;
  }
private:
  std::vector<std::vector<int> > adj_;
  int n_;
};

int main(){
  
  Graph g(4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);
  std::cout<<"Is cycle:"<< g.is_cycle(0)<<std::endl;
  g.addEdge(2, 1);
  
  std::cout<<"Is cycle:"<< g.is_cycle(0)<<std::endl;



  return 0;
}
