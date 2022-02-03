class Solution {
public:
    int fourSumCount(vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4) {
        
        int cnt = 0;
        unordered_map<int, int> mp;
        
        for(auto x : v1){
            for(auto y : v2){
                mp[x+y]++;
            }
        }
        
        for(auto x : v3){
            for(auto y : v4){
                auto it = mp.find(0-x-y);
                if(it != mp.end()){
                    cnt += it->second;
                }
            }
        }
        return cnt;
    }
};