class Solution {
public:
    int numIslands(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = m ? mat[0].size() : 0;
        
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == '1'){
                    ans++;
                    solve(mat, i, j);
                }
            }
        }
        return ans;
    }
    
    private:
    void solve(vector<vector<char>> &mat, int i, int j){
        int m = mat.size();
        int n = m ? mat[0].size() : 0;
        if(i<0 || i==m || j<0 || j==n || mat[i][j]=='0') return;
        
        mat[i][j] = '0';
        
        solve(mat, i-1, j);
        solve(mat, i+1, j);
        solve(mat, i, j-1);
        solve(mat, i, j+1);
    }
};