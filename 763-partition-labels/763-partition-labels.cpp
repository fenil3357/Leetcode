class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        
        for(int i=0; i<s.size(); i++) {
            mp[s[i]] = i;
        }
        
        vector<int> ans;
        int mx = 0, prev = -1;
        
        for(int i=0; i<s.size(); i++) {
            mx = max(mx, mp[s[i]]);
            
            if(mx == i) {
                ans.push_back(mx - prev);
                prev = mx;
            }
        }
        return ans;
    }
};