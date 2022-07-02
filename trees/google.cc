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
 *
 * https://leetcode.com/problems/binary-search-tree-iterator/submissions/
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        stakify(root);
    }

    void stakify(TreeNode* root){
        auto temp = root;
        while(temp != nullptr){
            st.push(temp);
            temp = temp->left;
        }
    }

    int next() {
        if(st.size() > 0){
            auto e = st.top(); st.pop();
            if(e->right) stakify(e->right);
            return e->val;
        }
        return -1;
    }

    bool hasNext() {
        return st.size() > 0;
    }

    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */