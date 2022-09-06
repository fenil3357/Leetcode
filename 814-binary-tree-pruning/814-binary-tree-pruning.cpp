class Solution {
public:
    
    bool solve(TreeNode* &root) {
        if(!root) return false;
        
        if(!root->left and !root->right and !root->val) return false;
        
        bool l = solve(root->left);
        bool r = solve(root->right);
        
        if(!l) root->left = nullptr;
        if(!r) root->right = nullptr;
        
        if(!l && !r) {
            if(root->val == 0) {
                root = nullptr;
                return false;
            }
            else {
                return true;
            }
        }
        
        return true;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        solve(root);
        return root;
    }
};