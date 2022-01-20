class Solution {
public:
    int solve(vector<int> &nums, vector<int> &dp, int idx){
        if(idx >= size(nums)) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        return dp[idx] = max(solve(nums, dp, idx+1), nums[idx]+solve(nums, dp, idx+2));
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(size(nums), -1);
        return solve(nums, dp, 0);
    }
};