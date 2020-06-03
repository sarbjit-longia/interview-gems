/*
 A minimum spanning tree is a special kind of tree that minimizes the lengths (or “weights”) of the edges of the tree. An example is a cable company wanting to lay line to multiple neighborhoods; by minimizing the amount of cable laid, the cable company will save money.
*/

#include "union_find.h"
#include <vector>
#include <set>
#include <algorithm>


struct Edge{
    int x;
    int y;
    int w;
};

class Kruskal{
public:
  Kruskal(){
  }

  void add(Edge e){
    edges_.push_back(e);
  }

  int cost(int num_nodes){
    std::sort(edges_.begin(), edges_.end(), [](Edge const& a, Edge const& b) { return a.w < b.w; });
    
    // Keep in mind that union find object takes number of nodes not number of edges.
    UnionFind u(num_nodes);
    // Its a greedy algorithm so we just gonna see the edge with minimum weight and keep on adding to the
    // tree.

    int c = 0;
    for(Edge& e: edges_){
      if(!u.same(e.x, e.y)){
        u.merge(e.x, e.y);
        c += e.w;
      }
    }
    return c;
  }

private:
  std::vector<Edge> edges_;
};

int main(int argc, char* argv[]){
    
    Kruskal k;
    k.add({1, 2, 4});
    k.add({2, 3, 8});
    k.add({1, 3, 2});

    std::cout<<"Cost with minimum spanning tree:"<< k.cost(4)<<std::endl;
    return 0;
}
