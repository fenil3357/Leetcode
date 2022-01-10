class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> vis;
        
        for(string x : startWords){
            int hash = 0;
            for(int i=0; i<x.size(); i++){
                hash += (1 << (x[i]-'a'));
            }
            vis.insert(hash);
        }
        
        int ans = 0;
        
        for(string s : targetWords){
            int hash = 0;
            for(int k=0; k<s.size(); k++){
                hash = 0;
                
                for(int i=0; i<s.size(); i++){
                    if(i == k) continue;
                    
                    hash += (1 << (s[i]-'a'));
                }
                if(vis.count(hash)){
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};