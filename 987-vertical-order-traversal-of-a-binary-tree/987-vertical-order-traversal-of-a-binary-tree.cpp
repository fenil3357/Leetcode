class Solution {
public:
    map<int, map<int, multiset<int>>> mp;

    void solve(TreeNode* root, int col, int row) {
        if(!root) return;

        mp[col][row].insert(root->val);
        solve(root->left, col-1, row+1);
        solve(root->right, col+1, row+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);

        vector<vector<int>> ans;

        for(auto &m1 : mp) {
            ans.push_back(vector<int>());

            for(auto &m2 : m1.second) {
                for(auto &m3 : m2.second) {
                    ans.back().push_back(m3);
                }
            }
        }

        return ans;
    }
};