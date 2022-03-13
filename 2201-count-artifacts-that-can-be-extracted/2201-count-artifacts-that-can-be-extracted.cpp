class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& arti, vector<vector<int>>& dig) {
        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));

        for(auto it : dig) {
            vis[it[0]][it[1]] = 1;
        }

        for(auto it : arti) {
            int r1 = it[0];
            int c1 = it[1];
            int r2 = it[2];
            int c2 = it[3];

            bool flg = true;

            for(int i=r1; i<=r2; i++) {
                for(int j=c1; j<=c2; j++) {
                    if(!vis[i][j]) {
                        flg = false;
                    }
                }
            }
            if(flg) cnt++;
        }
        return cnt;
    }
};