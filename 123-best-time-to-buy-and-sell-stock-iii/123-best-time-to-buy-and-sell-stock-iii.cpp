class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        
        int k = 2, mxProf = 0;
        
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        
        for(int i=1; i<=k; i++) {
            int tmpMx = dp[i-1][0] - prices[0];
            
            for(int j=1; j<prices.size(); j++) {
                dp[i][j] = max(dp[i][j-1], prices[j] + tmpMx);
                tmpMx = max(tmpMx, dp[i-1][j] - prices[j]);
                mxProf = max(dp[i][j], mxProf);
            }
        }
        return mxProf;
    }
};