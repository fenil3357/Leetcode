class Solution {
public:
    int threeSumMulti(vector<int>& v, int t) {
        unordered_map<int, int> mp;
        int cnt = 0;
        int mod = 1e9 + 7;
        
        for(int i=0; i<v.size(); i++) {
            cnt = (cnt + mp[t-v[i]])%mod;
            
            for(int j=0; j<i; j++) {
                mp[v[i] + v[j]]++;
            }
        }
        return cnt;
    }
};