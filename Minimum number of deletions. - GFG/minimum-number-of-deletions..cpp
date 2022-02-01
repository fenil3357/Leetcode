// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends

int longestCommonSubsequence(string s, string t) {
        
        int m = s.size();
        int n = t.size();
        
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++) dp[i][0] = 0;
        for(int j=0; j<=n; j++) dp[0][j] = 0;
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[m-i] == t[n-j]){
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
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
int minDeletions(string str, int n) { 
    //complete the function here 
    return (n-longestPalindromeSubseq(str));
} 