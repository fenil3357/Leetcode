class Solution {
public:
    int findPairs(vector<int>& v, int k) {
        
        if(v.size() == 0) return 0;
        
        
        int cnt = 0;
        unordered_map<int, int> mp;
        
        for(auto it : v) mp[it]++;
        
        for(auto it : mp){
            if(k == 0){
                if(it.second > 1) cnt++;
            }
            else
                if(mp.find(it.first-k)!=mp.end()) cnt++;
        }
        
        return cnt;
    }
};