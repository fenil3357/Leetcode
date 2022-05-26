class Solution {
public:

    void solve(vector<string> &res, string s, int n, int m) {
        if(n == 0 && m == 0) {
            res.push_back(s);
            return;
        }

        if(m>0) solve(res, s+")", n, m-1);
        if(n>0) solve(res, s+"(", n-1, m+1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(res, "", n, 0);
        return res;
    }
};