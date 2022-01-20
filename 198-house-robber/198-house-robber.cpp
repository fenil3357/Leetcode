class Solution {
public:
    int rob(vector<int>& v) {
        if(v.size() == 1) return v[0];
        
        vector<int> dp(v);
        
        dp[1] = max(v[0], v[1]);
        
        for(int i=2; i<size(v); i++){
            dp[i] = max(dp[i-1], v[i]+dp[i-2]);
        }
        return dp.back();
    }
};