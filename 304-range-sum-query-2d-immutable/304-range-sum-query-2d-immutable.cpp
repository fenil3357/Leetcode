class NumMatrix {
public:
    int row, col;
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& mat) {
        row = mat.size();
        col = ((row > 0) ? mat[0].size() : 0);

        pref = vector<vector<int>> (row+1, vector<int>(col+1, 0));

        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (pref[row2+1][col2+1] - pref[row2+1][col1] - pref[row1][col2+1] + pref[row1][col1]);
    }
};