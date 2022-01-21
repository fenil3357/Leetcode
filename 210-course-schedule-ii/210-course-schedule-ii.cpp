class Solution {
public:
    
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(checkCycle(it, adj, vis, dfsVis))
                    return true;
            }
            else if(dfsVis[it]) return true;
        }
        
        dfsVis[node] = 0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]){
        int vis[n], dfsVis[n];
        memset(vis, 0, sizeof vis);
        memset(dfsVis, 0, sizeof dfsVis);
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(checkCycle(i, adj, vis, dfsVis))
                    return true;
            }
        }
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<int> adj[n];
        
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> topo;
        if(isCyclic(n, adj)) return topo;
        
        queue<int> q;
        vector<int> inDegree(n, 0);
        
        for(int i=0; i<n; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }
        
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
};