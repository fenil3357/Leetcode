class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1005][1005] = {};
    
    int dfs(int d, int k) {
        if(d >= k)
            return d==k;
        
        if(dp[d][k] == 0) 
            dp[d][k] = (1 + dfs(d+1, k-1) + dfs(d + (d ? -1 : 1), k-1)) % mod;
        
        return dp[d][k] - 1;
    }
    
    int numberOfWays(int s, int e, int k) {
        return (dfs(abs(s - e), k));
    }
};