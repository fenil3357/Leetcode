class Solution {
public:
    int ans = 0;
    
    void solve(TreeNode* root, int mx) {
        if(!root) return; 
        
        if(root->val >= mx) ans++;
        
        mx = max(mx, root->val);
        
        solve(root->left, mx);
        solve(root->right, mx);
    }
    
    int goodNodes(TreeNode* root) {
        int mx = INT_MIN;
        solve(root, mx);
        return ans;
    }
};