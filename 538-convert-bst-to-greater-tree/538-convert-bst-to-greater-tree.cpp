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
    int currSum = 0;
    
    void helper(TreeNode* root){
        if(!root) return;
        
        if(root->right) helper(root->right);
        
        root->val = (currSum += root->val);
        
        if(root->left) helper(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }
};