#include <iostream>

std::vector<std::string> generate(std::string s){
    if(s.length() == 1){
        std::cout<<s<<"\n";
        return;
    } 
    char first = s[0];
    std::string rest = s.substr(1, s.length() - 1);
    generate(rest);
    for(int i = 0; i <= rest.length(); i++){
        
        for(int j = 0; j < rest.length(); j++){
            if(i == j){
                std::cout<<first;
            }
            std::cout<<rest[j];
        }
        std::cout<<"\n";
    }
}

int main(int argc, char* argv[]){
    generate("abc");
    return 0;
}