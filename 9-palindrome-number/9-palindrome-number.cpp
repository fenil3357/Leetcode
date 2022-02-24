class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;
        int ans = 0;
        int y = x;
        while(x) {
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
            ans = ans*10 + x%10;
            x /= 10;
        }
        return (y == ans);
    }
};