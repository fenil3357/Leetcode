class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int mx = 0;
        
        int minTillNow = INT_MAX;
        
        for(int i=0; i<n; i++){
            minTillNow = min(minTillNow, prices[i]);
            mx = max(prices[i]-minTillNow, mx);
        }
        
        return mx;
    }
};