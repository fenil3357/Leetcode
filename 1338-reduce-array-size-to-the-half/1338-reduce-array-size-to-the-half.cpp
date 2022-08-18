class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(auto &it : arr) mp[it]++;
        
        vector<int> freq;
        for (auto &it : mp) freq.push_back(it.second);
        sort(freq.begin(), freq.end(), greater<int> ());
        
        int n = arr.size();
        int tmp = n;
        int ans = 0;
        
        for(auto &it: freq) {
            if(tmp <= n/2) break;
            ans++;
            tmp -= it;
        }
        return ans;
    }
};