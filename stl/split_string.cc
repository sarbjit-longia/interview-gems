#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> split(std::string s){
    std::stringstream ss(s);
    std::string token;
    std::vector<std::string> result;

    while (std::getline(ss, token, ' '))
    {
        result.push_back(token);
    }
    return result;
}

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
