#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

int main(int arc, char* argv[]){
    std::string sentence = "hello world";
    std::istringstream ss(sentence);

    std::vector<std::string> words;

    std::copy(std::istream_iterator<std::string>(ss), 
              std::istream_iterator<std::string>(),
              std::back_inserter(words));

    std::copy(std::begin(words), std::end(words), std::ostream_iterator<std::string>(std::cout, "\n"));
    return 0;
}
