class Solution {
public:
    int numberOfArrays(vector<int>& diff, int l, int u) {
        
        long a=0, mx=0, mn=0;
        
        for(auto d : diff){
            a += d;
            mx = max(mx, a);
            mn = min(mn, a);
        }
        
        return max(0L, (u-l)-(mx-mn)+1);
    }
};