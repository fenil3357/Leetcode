class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int solve(vector<int> &prices, int pos, int t, bool bought) {
        if(pos >= prices.size() || t==0) return 0;
        if(dp[bought][t][pos]!=-1) return dp[bought][t][pos];

        // SKIP
        int result = solve(prices, pos+1, t, bought);

        // SELL
        if(bought) result = max(result, solve(prices, pos+1, t-1, false) + prices[pos]);

        // BUY
        else result = max(result, solve(prices, pos+1, t, true) - prices[pos]);

        dp[bought][t][pos] = result;
        return result;
    }

    int maxProfit(int k, vector<int>& prices) {
        dp.resize(2, vector<vector<int>>(k+1, vector<int>(prices.size(), -1)));
        return solve(prices, 0, k, false);
    }
};