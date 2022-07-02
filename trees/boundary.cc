class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root->right && !root->left)
            return {root->val};

        vector<int> res;
        res.push_back(root->val);
        left_nodes(root->left, res);
        leaf_nodes(root, res);
        right_nodes(root->right, res);

        return res;
    }

    void leaf_nodes(TreeNode *root, vector<int> &res) {
        if(!root)
            return;
        if(!root->right && !root->left)
            res.push_back(root->val);

        leaf_nodes(root->left, res);
        leaf_nodes(root->right, res);
    }

    void left_nodes(TreeNode* root, vector<int> &res) {
        if(!root || (!root->right && !root->left))
            return;
        res.push_back(root->val);
        if(root->left)
            left_nodes(root->left, res);
        else
            left_nodes(root->right, res);
    }

    void right_nodes(TreeNode* root, vector<int> &res) {
        if(!root || (!root->right && !root->left))
            return;
        if(root->right)
            right_nodes(root->right, res);
        else
            right_nodes(root->left, res);
        res.push_back(root->val);
    }
};