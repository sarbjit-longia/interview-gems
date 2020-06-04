/*
   This algorithm is used to find the longest palindrome in the 
   string
*/

#include <iostream>
#include <vector>

class LongestPalindrome {
public:
  LongestPalindrome(std::string s){
      s_ = s;
  }

  std::string maxPalindrome(){
    auto s = s_;

    std::vector<std::vector<bool> > table(s.length(), std::vector<bool>(s.length(), false));
    int max_length = 1;
    int start_index = 0;
    for(int i = 0; i < s.length(); i++){
      table[i][i] = true;
    }
    // Find for two lengths
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i + 1]){
            table[i][i+1] = true;
            max_length = 2;
            start_index = i;
        }
    }
    
    // Find for n length
    int n = s.length();
    for(int k = 3; k <= s.length(); k++){
        for(int i = 0; i < n - k + 1; i++){
          int j = i + k -1;
          if(table[i+1][j-1] && s[i] == s[j]){
            start_index = i;
            max_length = k;
            table[i][j] = true;
          }
        }
    }
    return s.substr(start_index, max_length);

  }
private:
  std::string s_;
};

int main(){
    //LongestPalindrome l("AGHSHGYIU");
    LongestPalindrome l("ccc");
    std::cout<<"Longest palindrome: "<< l.maxPalindrome()<<std::endl;

    return 0;
}
