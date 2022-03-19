class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        string res = text;
        
        res += pattern[1];
        
        long long ans1 = 0, ans2 = 0, num = 0;
        
        for(auto it : res) {
            if(it == pattern[1]) ans1 += num;
            if(it == pattern[0]) num++;
        }
        
        res = "";
        res += pattern[0];
        
        res += text;
        
        num = 0;
        
        for(auto it : res) {
            if(it == pattern[1]) ans2 += num;
            if(it == pattern[0]) num++;
        }
        return max(ans1, ans2);
    }
};