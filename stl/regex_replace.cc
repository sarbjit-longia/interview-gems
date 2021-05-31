#include <regex>
#include <string>
#include <iostream>


int main()
{
    const std::string s = "example string";
    const std::string r = std::regex_replace(s, std::regex("x"), "y");
    std::cout << r << std::endl;
    std::cout << std::regex_replace("/a/b////c//d", std::regex("/"), "") << std::endl;
    return 0;
}