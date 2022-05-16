class Solution {
public:
    vector<int> x_points = {-1,-1,-1,0,0,1,1,1};
    vector<int> y_points = {-1,0,1,-1,1,-1,0,1};

    bool isValid(int x, int y, int n, int m) {
        return x>=0 && x<=n && y>=0 && y<=m;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size()-1;
        int m = grid[0].size()-1;

        if(grid[0][0] || grid[n][m]) return -1;

        queue<vector<int> > q;
        vector<int> v;

        q.push({0, 0});
        grid[0][0] = 1;

        while(!q.empty() && !grid[n][m]) {
            v = q.front();
            q.pop();

            for(int i=0; i<8; i++) {
                int x = v[0] + x_points[i];
                int y = v[1] + y_points[i];

                if(isValid(x, y, n, m) && grid[x][y] == 0) {
                    grid[x][y] = grid[v[0]][v[1]] + 1;
                    q.push({x, y});
                }
            }
        }
        return grid[n][m] ? grid[n][m] : -1;
    }
};