class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        
        int n = m[0].size();
        
        //First transpose the matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(m[i][j], m[j][i]);
            }
        }
        
        
        for(int i=0; i<n; i++){
            int st = 0, end = n-1;
            
            while(st < end){
                swap(m[i][st], m[i][end]);
                st++;
                end--;
            }
        }
    }
};