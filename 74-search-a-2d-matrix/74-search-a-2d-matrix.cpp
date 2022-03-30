class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        
        int row = 0;
        int n = mat[0].size();

        if(t<mat[0][0] || t>mat[mat.size()-1][n-1]) return false;

        for(int i=0; i<mat.size(); i++) {
            if(t>=mat[i][0] && t<=mat[i][n-1]) {
                row = i;
                break;
            }
        }


        int l = 0, h = n-1;

        while(l <= h) {
            int mid = (l + h) >> 1;

            if(t == mat[row][mid]) return true;

            else if(t < mat[row][mid]) {
                h = mid - 1;
            } 
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};