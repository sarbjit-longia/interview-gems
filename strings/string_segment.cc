#include <iostream>
#include <vector>

struct Node{
    Node(char ch){
        c = ch;
        for (int i = 0; i < 26; i++)
            childs[i] = nullptr;
    }
    char c;
    Node *childs[26];
};

class Trie final {

public:
    Trie (){
        root = new Node(' ');
    }
    void addString(std::string name){
        Node *temp = root;
        for (int i = 0; i < name.length(); i++){
            char curr = name[i];
            if (temp->childs[curr - 'a'] == nullptr){
                temp->childs[curr - 'a'] = new Node(curr);
            }
            temp = temp->childs[curr - 'a'];
        }
    }

    int findDifferentIndex(std::string name){
        //std::cout << " Finding name: " << name << std::endl;
        Node *temp = root;
        for (int i = 0; i < name.length(); i++) {
            char curr = name[i];
            if(temp->childs[curr - 'a'] == nullptr)
                return i;
            temp = temp->childs[curr - 'a'];
        }
        return name.length();
    }

    bool isStemmingPossible(std::string name){
        int index = 0;

        while(name.length() >= 0){
            int curr_index = findDifferentIndex(name);
            if(curr_index == name.length())
                break;
            //std::cout << "Curr index: " << curr_index << " index: " << index << std::endl;
            if (curr_index == index)
                return false;
            index = curr_index;
            name = name.substr(index);
        }
        return true;
    }
private:
    Node *root;
};


int main(){
    Trie t;
    t.addString("apple");
    t.addString("apple");
    t.addString("peer");
    t.addString("pie");

    std::cout << "Applepie can be segmented: " << t.isStemmingPossible("applepie") << std::endl;
    std::cout << "Applepear can be segmented: " << t.isStemmingPossible("applepear") << std::endl;
    return 0;
}