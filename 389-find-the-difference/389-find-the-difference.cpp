class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size() == 0) return t[0];
        
        unordered_map<char, int> mp;
        
        for(int i=0; i<s.size(); i++) mp[s[i]]++;
        
        for(int i=0; i<t.size(); i++){
            mp[t[i]]--;
        }
        
        for(auto it : mp){
            if(it.second != 0) return it.first;
        }
        return '*';
    }
};