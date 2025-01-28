
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //1. level order transversal
        //2.BFS traversal 
        if(root== NULL) return {};
        vector<int>sol;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           int n= q.size(); // size of queue
            TreeNode *curr = nullptr;
           while(n--){
            curr = q.front();
            q.pop();
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
           }
           sol.push_back(curr->val);
        }
        return sol;
    }
};