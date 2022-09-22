class Solution {
public:
    int findLength(vector<int>& v1, vector<int>& v2) {
        int m = v1.size(), n = v2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int ans = 0;

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(v1[i-1] == v2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};