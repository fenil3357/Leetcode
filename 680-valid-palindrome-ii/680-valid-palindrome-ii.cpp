class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, h = s.size()-1;
        
        while(l < h) {
            if(s[l] != s[h]) {
                int l1 = l, h1 = h - 1;
                int l2 = l + 1, h2 = h;
                
                while(l1 < h1 && s[l1]==s[h1]) {l1++;h1--;}
                while(l2 < h2 && s[l2]==s[h2]) {l2++;h2--;}
                
                return l1 >= h1 || l2 >= h2;
            }
            
            l++;
            h--;
        }
        return true;
    }
};