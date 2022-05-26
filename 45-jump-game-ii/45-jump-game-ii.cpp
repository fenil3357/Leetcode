class Solution {
public:
    
    long long solve(vector<int> &nums, int idx, vector<long long> &dp) {
        if(idx >= nums.size()-1) return 0;
        long long mn = INT_MAX;
        
        if(dp[idx] != -1) return dp[idx];

        for(int i=1; i<=nums[idx]; i++) {
            mn = min(mn, 1 + solve(nums, idx+i, dp));
        }
        dp[idx] = mn;
        return mn;
    }
    int jump(vector<int>& nums) { 
        vector<long long> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};