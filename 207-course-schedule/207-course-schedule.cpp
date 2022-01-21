class Solution {
public:
    
    bool isCycle(vector<int> adj[], vector<int> &vis, int node){
        if(vis[node] == 1) return true;
        
        if(vis[node] == 0){
            vis[node] = 1;
            
            for(auto it : adj[node]){
                if(isCycle(adj, vis, it)) return true;
            }
        }
        vis[node] = 2;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<int> adj[n];
        
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
        
        for(int i=0; i<n; i++){
            if(isCycle(adj, vis, i)) return false;
        }
        
        return true;
    }    
};