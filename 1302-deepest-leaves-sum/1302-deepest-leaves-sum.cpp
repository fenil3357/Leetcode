class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            res = 0;
            for(int i=q.size()-1; i>=0; --i) {
                TreeNode* node = q.front();
                res += node->val;
                q.pop();

                if(node->right) q.push(node->right); 
                if(node->left) q.push(node->left);
            }
        }
        return res;
    }
};