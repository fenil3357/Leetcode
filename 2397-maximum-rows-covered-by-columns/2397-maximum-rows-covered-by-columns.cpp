class Solution {
public:
    int ans = INT_MIN;

    void solve(vector<vector<int>> &mat, int m, int n, int cols, int idx, vector<int> &vis) {
        if(cols == 0 || idx == n) {
            int cnt = 0;

            for(int i=0; i<m; i++) {
                bool chk = true;

                for(int j=0; j<n; j++) {
                    // If cell is 1 and not visited then we can't take this row
                    if(mat[i][j] == 1 and vis[j] == 0) {
                        chk = false;
                        break;
                    }
                }

                // If all 1s are marked as visited then count the row
                if(chk) cnt++;
            }

            ans = max(ans, cnt);
            return;
        }

        // Picking the ith column and marking column as visited
        vis[idx] = 1;
        solve(mat, m, n, cols-1, idx+1, vis);
        vis[idx] = 0;

        // Not picking the column
        solve(mat, m, n, cols, idx+1, vis);
        return;
    }

    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> vis(n);

        solve(mat, m, n, cols, 0, vis);
        return ans;
    }
};