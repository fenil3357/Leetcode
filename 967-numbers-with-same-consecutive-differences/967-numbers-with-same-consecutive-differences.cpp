class Solution {
public:
    vector<string> res;
    
    void solve(string curr, int idx,int k, int n) {
        if(idx == n) {
            res.push_back(curr);
            return;
        }
        
        if(idx == 0) {
            for(int i=1; i<=9; i++) {
                curr[idx] = (i + '0');
                solve(curr, idx+1,k, n);
            }
        }
        else {
            for(int i=0; i<=9; i++) {
                int prev = curr[idx-1] - '0';
                if(abs(prev - i) == k) {
                    curr[idx] = (i + '0');
                    solve(curr, idx+1, k, n);
                }
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        string curr(n, '#');
        
        solve(curr, 0,k, n);
        vector<int> ans;
        
        for(int i=0; i<res.size(); i++) {
            ans.emplace_back(stoi(res[i]));
        }
        
        return ans;
    }
};