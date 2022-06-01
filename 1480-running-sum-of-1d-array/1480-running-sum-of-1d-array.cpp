class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> pref;
        
        pref.push_back(0);
        for(auto &it : nums) {
            pref.push_back(pref.back() + it);
        }
        
        pref.erase(pref.begin());
        return pref;
    }
};