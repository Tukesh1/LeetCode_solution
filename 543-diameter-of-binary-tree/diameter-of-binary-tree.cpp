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
    int diameterTree(TreeNode *root, int &dia){
       if(root == nullptr) return 0;
       int lh= diameterTree(root->left, dia);
       int rh  = diameterTree(root->right, dia);
       dia= max(dia, lh+rh); 
       return 1+max(rh, lh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
         diameterTree(root,diameter);
        return diameter;
    }
};