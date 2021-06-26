/*
Your previous Python 3 content is preserved below:

# Given 2 input lists, find the mathmatical symmetrical difference between these lists
# Given the contrived data members, the data actually will be externally sourced (data type, elements values, and the number of elements can be very different)
# Data can span millions of members for each list... so your design and code how you would approach the problem should be cognizant of this possibility
#
# Requirements:
# 1. Performance must be within Big O(n^2)
# 2. Baseline unit test to cover edge cases
# 3. Use idiomatic python, here PEP8, PEP257, PEP484 applies
# 4. Bonus pts if you can discuss how PEP20 applies
# 5. Scale considerations

def find_mathmatical_symm_diff(list1: list, list2: list)->list:
    return None

list2 = ['apple', 'watermelon', 3, 'orange']
list1 = ['orange', 5, 'orange', 'apple']

result = [5, 'orange', 'watermelon', 3]  # candidate thoughts to align on requirement understanding

print(find_mathmatical_symm_diff(list1, list2))
*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <iterator>


struct Pipe {

  Pipe(std::vector<std::string> list1){
    list_ = list1;
    index = 0;
  }

  bool get_next_val(std::string& entry){
    if(index < list_.size()){
      entry = list_[index++];
      return true;
    }
    return false;
  }
  void reset() { index = 0;}
  std::vector<std::string> list_;
  size_t index;
};


class Processor{
public:

  Processor(std::vector<std::string>& list1, std::vector<std::string>& list2)
      : first_pipe_(list1), second_pipe_(list2) {

  }

  std::vector<std::string> execute();
private:
  Pipe first_pipe_;
  Pipe second_pipe_;
};

void print_map(std::map<std::string, int>& m){

  for(auto it = m.begin(); it != m.end(); it++){
   std::cout<<it->first<<" : "<< it->second <<std::endl;

  }

  std::cout<<"---------------------\n"
;}

std::vector<std::string> Processor::execute(){
  std::map<std::string, int> first_map;
  std::map<std::string, int > second_map;
  std::map<std::string, int> result_map;
  std::vector<std::string> result;

  std::string entry;

  while(second_pipe_.get_next_val(entry)){
    second_map[entry]++;
  }

  //map: [orange: 2, apple: 1, 5: 1]

  while(first_pipe_.get_next_val(entry)){
    auto it = second_map.find(entry);
    if(it == second_map.end()){
      result_map[entry]++;
    }
    else{
      if(second_map[entry] == 0){
        result_map[entry]++;
      }
      else{
        second_map[entry]--;
      }
    }
    //result [watermelon, 3]
    //second map:  [orange: 1, , 5: 1]
  }
  // Pupulated result_map with potential solution
  //result [watermelon, 3]
  //second map:  [orange: 1, , 5: 1]
  // result = [5, 'orange', 'watermelon', 3]
  //print_map(first_map);
  //print_map(second_map);
  //print_map(result_map);


  first_pipe_.reset();
  second_pipe_.reset();

  while(first_pipe_.get_next_val(entry)){
    first_map[entry]++;
  }

  while(second_pipe_.get_next_val(entry)){
    auto it = first_map.find(entry);
    if(it == first_map.end()){
      if(result_map.find(entry) == result_map.end()){
        result_map[entry]++;
      }
    }
    else{
      if(it->second == 0){
        result_map[entry]++;
      }
      else{
        it->second--;
      }
    }
  }

  for(auto it = result_map.begin(); it != result_map.end(); it++){
    result.push_back(it->first);
  }

  return result;
}



//list2 = ['apple', 'watermelon', 3, 'orange']
//list1 = ['orange', 5, 'orange', 'apple']

//result = [5, 'orange', 'watermelon', 3]
int main(){

  std::vector<std::string> first = {"apple", "watermelon", "3", "orange"};
  std::vector<std::string> second = {"orange", "5", "orange", "apple"};

  Processor p(first, second);

  auto result = p.execute();

  std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, " "));

  return 0;

}



