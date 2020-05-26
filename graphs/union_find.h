#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

class UnionFind{

public:
  
  UnionFind(int count);
  // Method to find the parent of the element
  int find(int x);

  // Method to merge the disjoint sets
  void merge(int x, int y);

  //Method to find if both elements belong to the same set
  bool same(int x, int y);

private:
  std::vector<int> parents_;
  std::vector<int> ranks_;
  int count_;
};

UnionFind::UnionFind(int x){
    count_ = x;
    parents_.resize(x);
    ranks_.resize(x);
    std::iota(parents_.begin(), parents_.end(), 0);
    std::fill(ranks_.begin(), ranks_.end(), 0);
}

int UnionFind::find(int x){
  if(parents_[x] == x) return parents_[x];

  parents_[x] =  find(parents_[x]);
  return parents_[x];
}

void UnionFind::merge(int x, int y){
  auto px = find(x);
  auto py = find(y);

  if(px == py) return;
  
  if(ranks_[px] > ranks_[py]){
    parents_[py] = px;
  }
  else if(ranks_[px] < ranks_[py]){
    parents_[px] = py;
  }
  else{
    parents_[px] = py;
    ranks_[py]++;
  }
}

bool UnionFind::same(int x, int y){
    return find(x) == find(y);
}
