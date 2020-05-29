#include <iostream>
#include <vector>
#include <stack>

/*
   Very nice algorithm to solve the tasks that has dependencies to other tasks.
   The advantage of using this algo over dfs based algo is the cycle detection.
   In case the result is smaller than N, it has cycles
*/

class KahnTopologicalSort{

public:
  KahnTopologicalSort(int n) : n_(n) {
    nodes_.resize(n_);
  }

  std::vector<int> sort(){
    std::vector<int> indegree(n_, 0);
    for(auto n: nodes_){

        for(int i = 0; i < n.size(); i++){
          std::cout<<"Adding indegree for :"<<n[i]<<std::endl;
          indegree[n[i]]++;
        }
    }

    // Get all the ones with 0 indegree
    std::vector<int> temp;

    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0) temp.push_back(i);
    }
    //std::copy(indegree.begin(), indegree.end(), std::ostream_iterator<int>(std::cout, " "));
    //std::cout<<std::endl;
    //std::copy(temp.begin(), temp.end(), std::ostream_iterator<int>(std::cout, " "));
    //std::cout<<std::endl;
    
    // Now start iterating from back as we need answer in reverse order
    std::vector<int> result;
    
    while(!temp.empty()){
      int ee = temp.back();
      temp.pop_back();
      result.push_back(ee);

      for(int i = 0; i < nodes_[ee].size(); i++){
        int u = nodes_[ee][i];
        std::cout<<"Processing node: "<< ee<<" -> "<< u<<std::endl;
        indegree[u]--;

        if(indegree[u] == 0){
          temp.push_back(u);
        }
      }
    }

    /* If any entry in ingree is > 0, it has cycles */
    for(int i = 0; i < n_; i++){
        if(indegree[i] > 0){
          std::copy(indegree.begin(), indegree.end(), std::ostream_iterator<int>(std::cout, " "));
          std::cout<<std::endl;
          throw std::runtime_error("Graph has cycles.");
        }
    }
    return result;
  }

  void addEdge(int x, int y){
      std::cout<<"Adding edge X:" << x<<", Y:"<< y<<std::endl;
      nodes_[x].push_back(y);
  }

private:
  int n_;
  std::vector<std::vector<int> > nodes_;
};


int main(int argc, char* argv[]){

    KahnTopologicalSort g(6);
    
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    std::cout<<"Starting sort..."<<std::endl;
    auto result = g.sort();

    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;

}
