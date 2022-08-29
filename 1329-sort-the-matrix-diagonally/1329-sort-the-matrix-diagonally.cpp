class Solution {
public:
    unordered_map<int, vector<int>> mp;

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                mp[i-j].push_back(mat[i][j]);
            }
        }    

        // min value of (i-j) is -(m-1), and max value is n-1;
        for(int k=-(m-1); k<n; k++) {
            sort(mp[k].begin(), mp[k].end());
        }

        for(int i=n-1; i>=0; --i) {
            for(int j=m-1; j>=0; --j) {
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};