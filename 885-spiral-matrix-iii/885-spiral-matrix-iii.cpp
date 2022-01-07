class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int r, int c, int rSt, int cSt) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        
        int len = 0, d = 0;
        
        ans.push_back({rSt, cSt});
        
        while(ans.size() < r*c){
            if(d==0 or d==2) len++;
            
            for(int i=0; i<len; i++){
                rSt += dir[d][0];
                cSt += dir[d][1];
                
                if(rSt>=0 and rSt<r and cSt>=0 and cSt<c){
                    ans.push_back({rSt, cSt});
                }
            }
            d = (d+1)%4;
        }
        return ans;
    }
};