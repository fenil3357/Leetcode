class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2) return {};

        unordered_map<int, int> mp;
        sort(changed.begin(), changed.end());

        vector<int> original;
        
        for(auto &it : changed) mp[it]++;

        for(auto &it : changed) {
            if(mp[it] > 0) {
                if(mp[2*it] > 0)
                    original.push_back(it);
                else
                    return {};

                mp[it]--;
                mp[2*it]--;
            }
        }
        return original;
    }
};