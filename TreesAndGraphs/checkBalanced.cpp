// https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/ 

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        return abs(maxDepth(root->left) - maxDepth(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};