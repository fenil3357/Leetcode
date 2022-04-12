class Solution {
public:
    void gameOfLife(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> v(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1) {
                    int cnt = 0;

                    if(i>0 && j>0 && mat[i-1][j-1]==1) cnt++;
                    if(j>0 && mat[i][j-1]==1) cnt++;
                    if((i+1)<m && j>0 && mat[i+1][j-1]==1) cnt++;
                    if((i+1)<m && mat[i+1][j]==1) cnt++;
                    if((i+1)<m && (j+1)<n && mat[i+1][j+1]==1) cnt++;
                    if((j+1)<n && mat[i][j+1]==1) cnt++;
                    if(i>0 && (j+1)<n && mat[i-1][j+1]) cnt++;
                    if(i>0 && mat[i-1][j]==1) cnt++; 

                    if(cnt==2 || cnt==3) v[i][j] = 1;
                }
                else{
                    int cnt = 0;

                    if(i>0 && j>0 && mat[i-1][j-1]==1) cnt++;
                    if(j>0 && mat[i][j-1]==1) cnt++;
                    if((i+1)<m && j>0 && mat[i+1][j-1]==1) cnt++;
                    if((i+1)<m && mat[i+1][j]==1) cnt++;
                    if((i+1)<m && (j+1)<n && mat[i+1][j+1]==1) cnt++;
                    if((j+1)<n && mat[i][j+1]==1) cnt++;
                    if(i>0 && (j+1)<n && mat[i-1][j+1]) cnt++;
                    if(i>0 && mat[i-1][j]==1) cnt++; 

                    if(cnt == 3) v[i][j] = 1; 
                }
            }
        }

        mat = v;
    }
};