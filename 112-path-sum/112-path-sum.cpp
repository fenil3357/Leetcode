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
    void helper(TreeNode* &root){
        if(!root) return;
        
        if(root->left)
            root->left->val += root->val;
        
        if(root->right)
            root->right->val += root->val;
        
        helper(root->left);
        helper(root->right);
    }
    int f = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root) return false;
        
        if(f == 0){
            helper(root);
            f = 1;
        }
        
        if((!root->left and !root->right) and (root->val == targetSum)) return true;
        
        bool l = hasPathSum(root->left, targetSum);
        bool r = hasPathSum(root->right, targetSum);
        
        return (l || r);
    }
};