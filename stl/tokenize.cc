#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main(){
    std::string s = "a,b,c,d,e";

    std::istringstream ss(s);
    std::string token;
    while (std::getline(ss, token, ',')){
        std::cout << token << std::endl;
    }
    return 0;
}