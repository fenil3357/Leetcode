class Solution {
public:
    bool isAnagram(string s, string t) {
        if(!s.size() and !t.size()) return true;
        if((!s.size() and t.size()) || (s.size() and !t.size())) return false;
        
        unordered_map<char, int> mp;
        
        for(int i=0; i<t.size(); i++) mp[t[i]]++;
        
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i]) == mp.end() || mp[s[i]] == 0) return false;
            
            else mp[s[i]]--;
        }
        
        mp.clear();
        for(int i=0; i<s.size(); i++) mp[s[i]]++;
        
        for(int i=0; i<t.size(); i++){
            if(mp.find(t[i]) == mp.end() || mp[t[i]] == 0) return false;
            
            else mp[t[i]]--;
        }
        return true;
    }
};