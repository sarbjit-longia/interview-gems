#include <iostream>
#include <vector>
#include <tgmath.h>

void generate_sets(std::vector<int>& input, std::vector<std::vector<int> >& result){
    auto final_count = pow(2, input.size());

    for(int i = 0; i < final_count; i++){
        std::vector<int> e; 
        for(int j = 0; j < input.size(); j++){
           if( i & (1 << j)){
              e.push_back(input[j]);
           }
        }
        result.push_back(e);
    }
}

int main(){
    std::vector<int> input = {3, 4, 5};
    std::vector<std::vector<int> > result;
    generate_sets(input, result);

    for(int i = 0; i < result.size(); i++){
        std::copy(result[i].begin(), result[i].end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout<<std::endl;
    }
    return 0;
}
