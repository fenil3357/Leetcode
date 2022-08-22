class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        for(long long int i=1; 1LL*i*i <= n; i++) {
            if(pow(4, i) == n) return true;
        }
        
        return false;
    }
};