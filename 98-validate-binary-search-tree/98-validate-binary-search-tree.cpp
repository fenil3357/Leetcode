class Solution {
public:
    bool help(TreeNode* root, TreeNode* min = NULL, TreeNode* max = NULL){
        
        if(!root) return true;
        
        if(min and root->val <= min->val) return false;
        if(max and root->val >= max->val) return false;
        
        bool leftValid = help(root->left, min, root);
        bool rightValid = help(root->right, root, max);
        
        return (leftValid and rightValid);
    }
    bool isValidBST(TreeNode* root) {
        
        return help(root, NULL, NULL);
    }
};