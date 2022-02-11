class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        if(s1 == s2) return true;
        
        vector<int> a(26, 0), b(26, 0);
        int n1 = s1.size(), n2 = s2.size();
        
        for(auto it : s1) a[it-'a']++;
        
        for(int i=0; i<n2; i++){
            b[s2[i]-'a']++;
            
            if(i>=n1) b[s2[i-n1]-'a']--;
            if(a == b) return true;
        }
        
        return false;
    }
};