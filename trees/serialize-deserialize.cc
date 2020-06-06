// You can choose to save inorder and preorder traversal
// or to save the level order traversal using BFS as shown below
// 
/**
 * Definition for a binary tree node.
 */
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::stringstream ss;
        
        std::queue<TreeNode*> s;
        s.push(root);
        
        while(s.size() > 0){
            auto e = s.front(); 
            s.pop();
            //std::cout<<"size:"<<s.size()<<std::endl;
            if(e == NULL) {
                ss<<"null,";
            }
            else{
                ss<<e->val<<",";
                s.push(e->left);
                s.push(e->right);
            }
        }
        //std::cout<<ss.str();
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* createNode(std::string val){
        if(val == "null") return NULL;
        int v = atoi(val.c_str());
        TreeNode* node = new TreeNode(v);
        return node;
    }
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        
        std::vector<std::string> strs;
        auto tmp = strtok((char*)data.c_str(), ",");
        while(tmp){
            strs.push_back(std::string(tmp));
            tmp = strtok(NULL, ",");
        }
        
        TreeNode* root = createNode(strs[0]);
        int index = 1;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto e = q.front();
            q.pop();
            if(e == NULL) continue;
            
            auto le = strs[index++];
            auto re = strs[index++];
            e->left = createNode(le);
            e->right = createNode(re);
            
            q.push(e->left);
            q.push(e->right);
        }
        return root;
    }
};
