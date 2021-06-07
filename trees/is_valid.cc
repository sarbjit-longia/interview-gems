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
 *
 * https://leetcode.com/problems/validate-binary-search-tree/submissions/
 */
class Solution {
public:

    bool util(TreeNode* root, int minv, int maxv){
        if(root == nullptr) return true;
        if(root->val < minv || root->val > maxv) return false;

        if(root->val==INT_MIN && root->left != nullptr){
            return false;
        }
        if(root->val==INT_MAX && root->right != nullptr){
            return false;
        }

        int newMax = INT_MIN;
        int newMin = INT_MAX;
        if(root->val>INT_MIN){
            newMax = root->val-1;
        }
         if(root->val<INT_MAX){
            newMin = root->val+1;
        }
        return util(root->left, minv, newMax) && util(root->right, newMin, maxv);
    }

    bool isValidBST(TreeNode* root) {
        return util(root, INT_MIN, INT_MAX);
    }
};