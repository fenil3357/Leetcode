class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        int n = s.size();
        
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<i; j++) {
                if(dp[j]) {
                    if(find(wd.begin(), wd.end(), s.substr(j, i-j)) != wd.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};