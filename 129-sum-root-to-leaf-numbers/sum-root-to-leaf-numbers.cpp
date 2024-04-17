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
    int solution(TreeNode *root, int ct_sum){
        // base case 
        if(root == NULL) return 0;
        // update curr sum ,assume u are at the child node 
        ct_sum = ct_sum *10 + root->val;
        // if you are at the leaf node 
        if(root->left == NULL && root->right ==NULL) return ct_sum;
        return solution(root->left,ct_sum) + solution(root->right, ct_sum);
    } 
    int sumNumbers(TreeNode* root) {
        return solution(root,0);
    }
};