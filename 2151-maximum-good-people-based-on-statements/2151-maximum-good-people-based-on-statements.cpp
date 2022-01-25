class Solution {
public:
    int maximumGood(vector<vector<int>>& s) {
        int n = s.size();
        int mxGood = 0;
        int combos = 1<<n;
        
        vector<int> roles(n);
        
        for(int i=1; i<combos; i++){
            int currGood = apply(roles, i);
            
            if(valid(s, roles)){
                mxGood = max(mxGood, currGood);
            }
        }
        return mxGood;
    }
    
    int apply(vector<int> &roles, int mask){
        int cnt = 0;
        int n = roles.size();
        
        for(int i=0; i<n; i++){
            cnt += roles[i] = mask&1;
            mask >>= 1;
        }
        return cnt;
    }
    
    bool valid(vector<vector<int>> &s, vector<int> &roles){
        int n = s.size();
        
        for(int i=0; i<n; i++){
            if(roles[i] == 0) continue;
            
            for(int j=0; j<n; j++){
                if(s[i][j] == 2) continue;
                
                if(s[i][j] != roles[j]) return false;
            }
        }
        return true;
    }
};