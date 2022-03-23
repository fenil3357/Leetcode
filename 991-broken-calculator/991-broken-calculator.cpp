class Solution {
public:
    int brokenCalc(int stVal, int t) {
        int ans = 0;
        
        while(stVal != t) {
            if(t%2==0 && t>stVal) t /= 2;
            
            else if(t > stVal) t++;
            
            else{
                ans += abs(stVal-t) - 1;
                t = stVal;
            }
            ans++;
        }
        return ans;
    }
};