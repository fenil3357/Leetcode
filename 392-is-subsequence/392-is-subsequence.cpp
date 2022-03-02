class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0 || s==t) return true;
        if(s.size() > t.size()) return false;
        
        int idx = 0;
        
        for(int i=0; i<t.size(); i++) {
            if(s[idx] == t[i]) idx++;
        }
        
        return idx==s.size();
    }
};