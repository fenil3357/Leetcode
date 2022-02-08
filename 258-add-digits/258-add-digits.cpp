class Solution {
public:
    int solve(int n){
        int ans = 0;
        while(n>0){
            int x = n%10;
            ans += x;
            n /= 10;
        }
        return ans;
    }
    int addDigits(int num) {
        if(num < 10) return num;
         
        while(num >= 10){
            num = solve(num);    
        }
        return num;
    }
};