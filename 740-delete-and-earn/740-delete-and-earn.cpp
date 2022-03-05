class Solution {
public:
    int deleteAndEarn(vector<int>& v) {
        int n = 10001;

		vector<int> sum(n, 0);
		vector<int> dp(n, 0);

		for(auto it : v) {
			sum[it] += it;
		}

		dp[0] = 0;
		dp[1] = sum[1];

		for(int i=2; i<n; i++) {
			dp[i] = max(dp[i-2]+sum[i], dp[i-1]);
		}
		return dp[n-1];
    }
};