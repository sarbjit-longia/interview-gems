/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//https://www.youtube.com/watch?v=PoBGyrIWisE

class Solution {
public:
    
    int findIndex(int v){
        for(int i = 0; i < inorder_.size(); i++){
            if(inorder_[i] == v) return i;
        }
        return -1;
    }
    
    TreeNode* util(int startIdx, int endIdx){
        if(startIdx > endIdx) return nullptr;
        
        auto root = new TreeNode(preorder_[preIndex_++]);
        
        if(startIdx == endIdx) return root;
        
        auto idxInInorder = findIndex(root->val);
        
        root->left = util(startIdx, idxInInorder - 1);
        root->right = util(idxInInorder + 1, endIdx);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex_ = 0;
        preorder_ = preorder;
        inorder_ = inorder;
        
        return util(0, preorder.size() - 1);
    }
    
    vector<int> preorder_;
    vector<int> inorder_;
    int preIndex_;
};

