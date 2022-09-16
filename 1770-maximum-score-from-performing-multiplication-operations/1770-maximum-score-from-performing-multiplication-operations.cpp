class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();

        vector<vector<int>> dp(m+1, vector<int>(m+1));

        for(int i=m-1; i>=0; i--) {
            for(int left = i; left>=0; left--) {
                dp[i][left] = max(multipliers[i]*nums[left] + dp[i+1][left+1], multipliers[i]*nums[n-1-(i-left)]+dp[i+1][left]);
            }
        } 

        return dp[0][0];
    }
};