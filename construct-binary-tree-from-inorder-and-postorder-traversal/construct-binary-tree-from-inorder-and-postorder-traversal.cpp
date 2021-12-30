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
    unordered_map<int, int> mp;
    int idx;
    
    TreeNode* tree(vector<int> &in, vector<int> &post, int st, int end){
        
        if(st > end) return NULL;
        
        TreeNode* root = new TreeNode(post[idx--]);
        int pos = mp[root->val];
        
        if(st == end) return root;
        
        root->right = tree(in, post, pos+1, end);
        root->left = tree(in, post, st, pos-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        idx = post.size()-1;
        for(int i=0; i<in.size(); i++)
            mp[in[i]] = i;
        
        return tree(in, post, 0, in.size()-1);
    }
};