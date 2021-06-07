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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(root == nullptr) return result;

        q.push(root);

        while(!q.empty()){
            std::vector<int> entry;

            std::queue<TreeNode*> sq;
            while(!q.empty()){
                auto f = q.front(); q.pop();
                entry.push_back(f->val);
                if(f->left) sq.push(f->left);
                if(f->right) sq.push(f->right);
            }
            result.push_back(entry);

            while(!sq.empty()){
                q.push(sq.front()); sq.pop();
            }
        }
        return result;
    }
};