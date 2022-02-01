class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> dp(n,0);
        
        int minTillNow = INT_MAX;
        
        for(int i=0; i<n; i++){
            minTillNow = min(minTillNow, prices[i]);
            dp[i] = prices[i] - minTillNow;
        }
        
        sort(dp.begin(), dp.end());
        return dp[n-1];
    }
};