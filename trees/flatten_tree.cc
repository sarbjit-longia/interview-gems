
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
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/
 */
class Solution {
public:

    TreeNode* flattenUtil(TreeNode* root){
        // Edge case (root = NULL), Base case (leaf node) propogates the leaf up the callstack
        if (!root || (!root->left && !root->right)) return root;

        // Recurse - get the rightmost leaf of each subtree
        TreeNode *lst_rmleaf = flattenUtil(root->left);
        TreeNode *rst_rmleaf = flattenUtil(root->right);

        // Balance: Cut the right subtree at the root, place the left subtree on the right
        // and use the leftmost leaf node of the left subtree to attach the cut subtree from before
        if (root->left) {
            swap(root->right, root->left);
            swap(lst_rmleaf->right, root->left);
        }

        // Return rightmost leaf node pointer
        return rst_rmleaf ? rst_rmleaf : lst_rmleaf;
    }

    void flatten(TreeNode* root) {
        flattenUtil(root);
    }
};