#include <iostream>
#include <vector>
#include <sstream>


void print_table(std::vector<std::vector<int> > & tbl, int na){
    for(int i= 0;i <= na; i++){
      std::copy(tbl[i].begin(), tbl[i].end(), std::ostream_iterator<int>(std::cout, " "));
      std::cout<<std::endl; 
    }
}

std::string lcs(std::string a, std::string b){
    int na = a.length();
    int nb = b.length();

    std::vector<std::vector<int> > tbl(na + 1, std::vector<int>(nb + 1, 0));

    for(int i = 1; i <= na; i++){
        for(int j = 1; j <= nb; j++){

            if(a[i-1] == b[j-1]){
              tbl[i][j] = tbl[i-1][j-1] + 1;
            }
            else{
              tbl[i][j] = std::max(tbl[i-1][j], tbl[i][j-1]);
            }
        }
    }

    // Now get the actual string by backtracing the values in table
    int mi = na;
    int mj = nb;
    std::stringstream ss;
    // if left and up are same move diagonal 
    // else move to the maximum value of two
    while(mi > 0 && mj > 0){
      if(tbl[mi-1][mj] == tbl[mi][mj-1]){
        ss<<a[mi-1];
        mi--;
        mj--;
      }
      else if(tbl[mi-1][mj] >= tbl[mi][mj]){
          mi--;
      }
      else{
          mj--;
      }
    }
    std::cout<<"The maximum length of common sub sequence: "<< tbl[na][nb]<<std::endl;
    return ss.str();
}

int main(){
    std::cout<<"Common subsequence from abcdfg and abdg :"<< lcs("abcdfg", "abdg");
    std::cout<<std::endl;
    std::cout<<"Common subsequece from abc and ac: "<< lcs("abc", "ac");
    std::cout<<std::endl;
    return 0;
}
