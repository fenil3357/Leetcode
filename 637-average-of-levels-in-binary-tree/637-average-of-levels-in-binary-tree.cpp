class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        double sum = 0;
        int cnt = 0;
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node) {
                cnt++;
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            else {
                ans.push_back((double)(sum/cnt));
                sum = 0;
                cnt = 0;
                if(q.size()) q.push(nullptr);
            }
        }
        return ans;
    }
};