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
 * // https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/
 */

// In this the only difference is that we get root from the end of postorder
class Solution {
public:
    int post_index = 0;

    int find_index(vector<int>& inorder, int value){
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == value) return i;
        }
        return -1;
    }

    TreeNode* create(vector<int>& inorder, vector<int>& postorder, int start, int end){
        if(start > end) return nullptr;

        TreeNode* root = new TreeNode(postorder[post_index--]);

        if(start == end) return root;

        int idx = find_index(inorder, root->val);

        root->right = create(inorder, postorder, idx + 1, end);
        root->left = create(inorder, postorder, start, idx - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_index = postorder.size() - 1;
        return create(inorder, postorder, 0, inorder.size() - 1);
    }
};