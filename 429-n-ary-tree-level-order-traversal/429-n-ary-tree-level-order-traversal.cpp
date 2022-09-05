class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            ans.emplace_back();
            
            for(int i=q.size(); i>=1; i--) {
                Node* node = q.front();
                q.pop();
                
                ans.back().push_back(node->val);
                
                for(auto &it : node->children) 
                    q.push(it);
            }
        }
        return ans;
    }
};