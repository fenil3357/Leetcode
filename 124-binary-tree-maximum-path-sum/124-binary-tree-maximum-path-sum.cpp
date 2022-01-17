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
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        maxPath(root, mx);
        return mx;
    }
    
    int maxPath(TreeNode* root, int &mx){
        if(!root) return 0;
        
        int left = max(0, maxPath(root->left,mx));
        int right = max(0, maxPath(root->right, mx));
        
        mx = max(mx, root->val+left+right);
        
        return root->val+max(left, right);
    }
};