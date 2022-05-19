class Solution {
public:
    bool checkLimits(int i, int j, int n, int m){ 
        return (i>=0 and i<n and j>=0 and j<m);
        
    }
    int solve(vector<vector<int>> &mat, vector<vector<int>> &dp, int i, int j, int n, int m) {
        if(!checkLimits(i, j, n, m)) return 0;

        if(dp[i][j] != - 1) return dp[i][j];

        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

        if(checkLimits(i+1, j, n, m) && mat[i+1][j] > mat[i][j]) 
            c1 = solve(mat, dp, i+1, j, n, m);

        if(checkLimits(i-1, j, n, m) && mat[i-1][j] > mat[i][j]) 
            c2 = solve(mat, dp, i-1, j, n, m);

        if(checkLimits(i, j+1, n, m) && mat[i][j+1] > mat[i][j]) 
            c3 = solve(mat, dp, i, j+1, n, m);

        if(checkLimits(i, j-1, n, m) && mat[i][j-1] > mat[i][j]) 
            c4 = solve(mat, dp, i, j-1, n, m);

        dp[i][j] = 1 + max(c1, max(c2, max(c3, c4)));
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int> > dp(n, vector<int> (m, -1));
        int ans = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) 
                ans = max(ans, solve(mat, dp, i, j, n, m));
        }
        return ans;
    }
};