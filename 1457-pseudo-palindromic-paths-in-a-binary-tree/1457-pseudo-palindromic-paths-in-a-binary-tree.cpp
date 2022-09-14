class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root, int count = 0) {
        if(!root) return 0;
        count ^= 1 << (root->val - 1);
        
        int ans = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        
        if(root->left == root->right && (count & (count - 1)) == 0) ans++;
        return ans;
    }
};