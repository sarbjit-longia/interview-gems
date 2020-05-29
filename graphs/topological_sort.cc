#include <iostream>
#include <vector>
#include <stack>

class TopologicalSort{

public:
  TopologicalSort(int n) : n_(n) {
    nodes_.resize(n_);
  }

  void dfs(int s){
    visited_[s] = true;

    for(int u : nodes_[s]){
      if(!visited_[u]) dfs(u);
    }
    result_.push(s);
  }

  std::vector<int> sort(){
    visited_.assign(n_, false);

    for(int i = 0; i <n_; i++){
      if(!visited_[i]) dfs(i);
    }
    std::vector<int> ans;

    while(!result_.empty()){
        auto e = result_.top(); result_.pop();
        ans.push_back(e);
    }
    return ans;
  }
  void addEdge(int x, int y){
    nodes_[x].push_back(y);
  }

private:
  int n_;
  std::vector<bool> visited_;
  std::stack<int> result_;
  std::vector<std::vector<int> > nodes_;
};


int main(int argc, char* argv[]){

    TopologicalSort g(6);
    
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    auto result = g.sort();

    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;

}
