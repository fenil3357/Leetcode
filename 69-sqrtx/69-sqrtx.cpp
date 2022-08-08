class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, e = x, ans, mid;
        
        while(l <= e) {
            mid = (l + e)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid < x) {
                ans = mid;
                l = mid + 1;
            }
            else e = mid - 1;
        } 
        return ans;
    }
};