#include <iostream>
#include <vector>

void subsets_util(std::vector<int>& input, int idx, std::vector<int>& subset, std::vector<std::vector<int> >& result){
    result.push_back(subset);

    for(int i = idx; i < input.size(); i++){
      subset.push_back(input[i]);
      subsets_util(input, i + 1, subset, result);
      subset.pop_back();
    }
}

void generate_sets(std::vector<int>& input, std::vector<std::vector<int> >& result){
    std::vector<int> subset;
    subsets_util(input, 0, subset, result);     
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
