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

    private:
    priority_queue<int, vector<int>, greater<int>> pq;
    
    void solve(TreeNode* root){
        
        if(!root) return;
        
        pq.push(root->val);
        solve(root->left);
        solve(root->right);
    }
    
    public:
    int kthSmallest(TreeNode* root, int k) {
        solve(root);
        
        while(k>1){
            pq.pop();k--;
        }
        return pq.top();
    }
};