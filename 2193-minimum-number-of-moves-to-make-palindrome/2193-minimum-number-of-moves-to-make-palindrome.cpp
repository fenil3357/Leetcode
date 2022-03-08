class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        
        while(s.size()) {
            int n = s.size();
            char ch = s[n-1];
            int idx = s.find(ch);
            
            if(idx == n-1) {
                ans += n/2;
                s.pop_back();
            }
            else{
                ans += idx;
                s.erase(idx, 1);
                s.pop_back();
            }
        }
        return ans;
    }
};