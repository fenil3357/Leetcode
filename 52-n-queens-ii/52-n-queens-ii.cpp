class Solution {
public:
    int cnt = 0;
    bool isValid(vector<string> &nQ, int row, int col, int &n) {
        for(int i=0; i != row; i++) 
            if(nQ[i][col] == 'Q')
                return false;

        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
            if(nQ[i][j] == 'Q')
                return false;

        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) 
            if(nQ[i][j] == 'Q')
                return false;

        return true;
    }

    void solve(vector<vector<string>> &res, vector<string> &nQ, int row, int &n) {
        if(row == n) {
            res.push_back(nQ);
            cnt++;
            return;
        }

        for(int col = 0; col != n; col++) {
            if(isValid(nQ, row, col, n)) {
                nQ[row][col] = 'Q';
                solve(res, nQ, row+1, n);
                nQ[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string> > res;
        vector<string> nQueens(n, string(n, '.'));
        solve(res, nQueens, 0, n);
        return cnt;
    }
};