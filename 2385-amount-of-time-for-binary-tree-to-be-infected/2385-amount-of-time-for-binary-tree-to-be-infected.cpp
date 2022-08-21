class Solution {
    int mx = 0;
    vector<vector<int>> e;

    void dfs1(TreeNode *node) {
        if (node == nullptr) return;
        mx = max(mx, node->val);
        dfs1(node->left); 
        dfs1(node->right);
    }

    void dfs2(TreeNode *node) {
        if (node->left != nullptr) {
            e[node->val].push_back(node->left->val);
            e[node->left->val].push_back(node->val);
            dfs2(node->left);
        }
        if (node->right != nullptr) {
            e[node->val].push_back(node->right->val);
            e[node->right->val].push_back(node->val);
            dfs2(node->right);
        }
    }

    int dfs3(int node, int parent) {
        int res = 0;
        for (int &it : e[node]) {
            if (it != parent) {
                res = max(res, dfs3(it, node) + 1);
            }
        }
        
        return res;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        dfs1(root);
        e.resize(mx + 1);
        dfs2(root);
        return dfs3(start, -1);
    }
};