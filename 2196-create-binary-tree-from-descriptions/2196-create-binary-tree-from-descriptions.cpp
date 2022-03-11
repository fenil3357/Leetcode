class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> getNode;
        unordered_map<int, bool> isChild;

        for(auto &it : descriptions) {
            if(getNode.count(it[0]) == 0) {
                TreeNode* par = new TreeNode(it[0]);
                getNode[it[0]] = par; 
            }
            if(getNode.count(it[1]) == 0) {
                TreeNode* child = new TreeNode(it[1]);
                getNode[it[1]] = child;
            }
            if(it[2] == 1) getNode[it[0]]->left = getNode[it[1]];
            else getNode[it[0]]->right = getNode[it[1]];
            isChild[it[1]] = true;
        }

        TreeNode* ans = NULL;

        for(auto &it : descriptions) {
            if(isChild[it[0]] != true) {
                ans = getNode[it[0]];
                break;
            }
        }
        return ans;
    }
};