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
    int preOrderIndex = 0;
    map<int, int> inOrderIndexMap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            inOrderIndexMap[inorder.at(i)] = i;

        /* Create a tree from the preorder array */
        return createTree(preorder, 0 , preorder.size() - 1);
    }

    TreeNode* createTree(vector<int> preOrderArr, int left, int right) {
        /* Recursion breaking case */
        if (left > right) return NULL;

        /* Get the value at the preOrderIndex while incrementing it */
        int rootVal = preOrderArr.at(preOrderIndex++);

        /* Create the root of this (sub)-tree */
        TreeNode* root = new TreeNode(rootVal);

        /* Do the same for the left and right subtrees */
        root -> left = createTree(preOrderArr, left, inOrderIndexMap[rootVal] - 1);
        root -> right = createTree(preOrderArr, inOrderIndexMap[rootVal] + 1, right);

        /* Return the root */
        return root;
    }
};

