class Solution {
public:

    string solve(TreeNode* root) {
        if(!root) return "";

        if(!root->left && !root->right) {
            return ("(" + to_string(root->val) + ")");
        }

        if(!root->left) {
            return ("(" + to_string(root->val) + "()" + solve(root->right) + ")");
        }

        if(!root->right) {
            return ("(" + to_string(root->val) + solve(root->left) + ")");
        }

        return ("(" + to_string(root->val) + solve(root->left) + solve(root->right) + ")");
    }

    string tree2str(TreeNode* root) {
        string ans = solve(root);
        ans.erase(0, 1);
        ans.pop_back();
        return ans;
    }
};