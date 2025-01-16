// https://leetcode.com/problems/path-sum-iii/solutions/ 

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
    int count(TreeNode* node, long currsum, int targetSum){
        if(!node) return 0;
        currsum += node->val;
        int answer = 0;
        if(currsum == targetSum) answer++;
        return answer + count(node->left, currsum, targetSum) + count(node->right, currsum, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return count(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);        
    }
};