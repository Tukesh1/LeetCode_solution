/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* rootLeft, TreeNode* rootRight) {
        if (rootLeft== nullptr || rootRight== nullptr)
            return rootLeft == rootRight; // base case
        return (rootLeft->val == rootRight->val) &&
               helper(rootLeft->left, rootRight->right) &&
               helper(rootRight->left, rootLeft->right);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        return helper(root->left, root->right);
    }
};