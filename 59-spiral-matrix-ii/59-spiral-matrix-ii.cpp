class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n, vector<int>(n));
        
        int row_st=0, row_end=n-1;
        int col_st=0, col_end=n-1;
        
        int cnt = 1;
        
        while(row_st<=row_end and col_st<=col_end){
            
            for(int col=col_st; col<=col_end; col++)
                ans[row_st][col] = cnt++;
            
            row_st++;
            
            for(int row=row_st; row<=row_end; row++)
                ans[row][col_end] = cnt++;
            
            col_end--;
            
            for(int col=col_end; col>=col_st; col--)
                ans[row_end][col] = cnt++;
            
            row_end--;
            
            for(int row=row_end; row>=row_st; row--)
                ans[row][col_st] = cnt++;
            
            col_st++;
        }
        return ans;
    }
};