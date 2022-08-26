class Solution {
public:
    int solve(vector<int> &v) {
        if(v.size() == 1) return v[0];
        
        vector<int> dp(v);
        
        dp[1] = max(v[0], v[1]);
        
        for(int i=2; i<size(v); i++){
            dp[i] = max(dp[i-1], v[i]+dp[i-2]);
        }
        return dp.back();
    }
    
    int rob(vector<int>& v) {
        vector<int> v1, v2;
        int n = v.size();
        if(n == 1) return v[0];
        
        for(int i=0; i<n; i++) {
            if(i != 0) v1.push_back(v[i]);
            if(i != n-1) v2.push_back(v[i]);
        }
        
        return max(solve(v1), solve(v2));
    }
};