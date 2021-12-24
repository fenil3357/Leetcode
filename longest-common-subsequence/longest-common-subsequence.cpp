class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) {
        
        int m = str1.size();
        int n = str2.size();
        
        int **dp = new int*[m+1];
        
        for(int i=0; i<=m; i++)
            dp[i] = new int[n+1];
        
        for(int i=0; i<=m; i++)
            dp[i][0] = 0;
        
        for(int i=0; i<=n; i++)
            dp[0][i] = 0;
        
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[m-i] == str2[n-j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    int a = dp[i-1][j];
                    int b = dp[i][j-1];
                    int c = dp[i-1][j-1];
                    dp[i][j] = max(a, max(b, c));
                }
            }
        }
        return dp[m][n];
    }
};