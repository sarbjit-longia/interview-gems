#include <iostream>
#include <vector>

int levenstein(std::string a, std::string b){
    int na = a.length();
    int nb = b.length();

    std::vector<std::vector<int> > tbl(na + 1, std::vector<int>(nb + 1, 0));

    for(unsigned int i = 1; i <= na; ++i) tbl[i][0] = i;
	for(unsigned int i = 1; i <= nb; ++i) tbl[0][i] = i;

    for(int i = 1; i <= na; i++){
        for(int j = 1; j <= nb; j++){
            int cost = 1;

            if(a[i-1] == b[j-1]){
              cost = 0;
            }
            tbl[i][j] = std::min({
                    tbl[i-1][j] + 1,
                    tbl[i][j-1] + 1,
                    tbl[i-1][j-1] + cost});

        }
    }

    return tbl[na][nb];
}

int main(){
    std::cout<<levenstein("abcdfg", "abdg");
    std::cout<<levenstein("abc", "ac");
    return 0;
}
