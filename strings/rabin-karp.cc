#include <iostream>
#include <string>
#include <vector>

#define BASE 256
#define PRIMARY 101

class FindPattern{
public:
    FindPattern(std::string s){
      text_ = s;
    }

    long calculate_hash(std::string s, int length){
      // Calculate the hash of the first k letter of the string
      long h = 0;
      for(int i = 0; i < length; i++){
        h = (h * BASE + s[i]) % PRIMARY; // B^n-1 + B ^ n-2....B^0   
      }
      return h;
    }

    long roll_hash(long hash, long power, char old_char, char new_char){
        //std::cout<<"Removing character: " << old_char<<", adding:" << new_char<<std::endl;
        long new_hash = (BASE * (hash - old_char * power) + new_char) % PRIMARY;  
  
      // We might get negative value , converting it to positive  
      if (new_hash < 0)  new_hash = (new_hash + PRIMARY);  

      return new_hash;
    }

    int find(std::string pattern){
      auto th = calculate_hash(text_, pattern.length());
      auto ph = calculate_hash(pattern, pattern.length());

      long power = 1;

      // Power is calculated for rolling the hash
      for(int i = 0; i < pattern.length() - 1; i++){
        power = (power * BASE) % PRIMARY;
      }
      
      
      for(int i = 0; i <= text_.length() - pattern.length(); i++){
        if(th == ph){
          // Check one by one now in this range
          if(pattern == text_.substr(i, pattern.length())) return i;
        }
        if(i < text_.length() - pattern.length()){
          //std::cout<<"Checking for string now:" << text_.substr(i, pattern.length())<<std::endl;
          th = roll_hash(th, power, text_[i], text_[i + pattern.length()]);
          //std::cout<<"New hash:"<< th<<", pattern hash: "<< ph<<std::endl;
        }
      }
      return -1;
    }
private:
    std::string text_;
};


int main(){
  
    FindPattern obj("Hello world");

    std::cout<<"Pattern wor found at location: "<< obj.find("wor")<<std::endl;
    std::cout<<"Pattern Hello found at location: "<< obj.find("Hello")<<std::endl;
    std::cout<<"Pattern ello found at location: "<< obj.find("ello")<<std::endl;
  
    return 0;
}
