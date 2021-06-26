/*
 *  You have a given a valid string str and width of character contains in a
    line. Return the number of lines required to write down the string

    str = "Hello world! this is IronMan" ;
    width = 7; Max(word length of a string) or greater than that.

    return 4;

    here is the explanation;

    1st line - Hello
    2nd line - world!
    3rd line- this is
    4th line - IronMan
 *
 */

#include <iostream>
#include <vector>
#include <sstream>

int screen_fit(std::string a, int max_length){
    int ans = 0;
    std::stringstream ss(a);
    std::string token;

    std::vector<std::string> lines;
    while (std::getline(ss, token, ' '))
    {
        if(token.length() > max_length)
            return -1;
        if(lines.size() > 0){
            if(max_length - lines.back().length() > token.length() - 1){ // for space
                lines[lines.size() - 1] = lines.back() + " " + token;
            }
            else{
                lines.push_back(token);
            }
        }
        else{
            lines.push_back(token);
        }
    }
    for (int i = 0; i < lines.size(); i++){
        std::cout << lines[i] << std::endl;
    }
    return lines.size();
}

int main(){
    std::string a = "Hello world! this is IronMan" ;
    std::cout << screen_fit(a, 7) << std::endl;
    return 0;
}
