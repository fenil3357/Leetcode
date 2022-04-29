class Solution {
public:
    bool bipartiteBFS(int src, vector<vector<int>> &graph, int col[]){
        
        queue<int> q;
        q.push(src);
        
        col[src] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : graph[node]){
                if(col[it] == -1){
                    col[it] = 1 - col[node];
                    q.push(it);
                }
                else if(col[it] == col[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int color[graph.size()];
        memset(color, -1, sizeof color);
        
        for(int i=0; i<graph.size(); i++){
            if(color[i] == -1){
                if(!bipartiteBFS(i, graph, color)){
                    return false;
                }
            }
         }
        return true;
    }
};