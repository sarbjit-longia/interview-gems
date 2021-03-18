/**
  Problem was to design an API that can assign colors to the users from a cache of colors
*/
#include <iostream>
#include <map>
#include <vector>

class AssignColor {
public:
    AssignColor(){
        empty_index = 0;
        for(int i = 0; i < 50;i ++){
            cache_.push_back(i);
        }
    }
    
    int assignColor(std::string name){
        if(members_.find(name) != members_.end()){
            return *(members_.find(name)->second);
        }
        members_[name] = std::begin(cache_) + empty_index;
        empty_index++;
        return *(members_[name]);
    } 
    
    void removeColor(std::string name){
        auto it = members_.find(name);
        members_.erase(it);
        int free_now = *(it->second);
        cache_.erase(it->second);
        cache_.push_back(free_now);
        empty_index--;
    } 
    
private:
    std::vector<int> cache_;
    std::map<std::string, std::vector<int>::iterator> members_;
    int empty_index = 0;
};


int main(){

    AssignColor obj;
    std::cout<< "Color assigned to sarbjit: " << obj.assignColor("sarbjit")<<std::endl;
    std::cout<< "Color assigned to singh: " << obj.assignColor("singh")<<std::endl;
    std::cout<< "Color assigned to sarbjit: " << obj.assignColor("sarbjit")<<std::endl;
    obj.removeColor("sarbjit");
    std::cout<< "Color assigned to sarbjit: " << obj.assignColor("sarbjit")<<std::endl;
    return 0;
}
