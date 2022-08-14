class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> count;
        
        for(auto &it : words) count[it]++;
        
        int n = s.size(), num = words.size();
        
        if(n==0 || num==0) return ans;
        
        int len = words[0].size();
        
        for(int i=0; i<n-num*len+1; i++) {
            unordered_map<string, int> seen;
            int j=0;
            
            while(j<num) {
                string word = s.substr(i+j*len, len);
                if(count.find(word) != count.end()) {
                    seen[word]++;
                    if(seen[word] > count[word]) break;
                }
                else break;
                j++;
            }
            
            if(j == num) ans.push_back(i);
        }
        return ans;
    }
};