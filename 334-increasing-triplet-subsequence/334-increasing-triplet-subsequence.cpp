class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp;
        
        for(auto it : nums) {
            auto iter = lower_bound(dp.begin(), dp.end(), it);
            
            if(iter == dp.end())
                dp.push_back(it);
            
            else if(it < *iter) 
                *iter = it;
        }
        
        return (dp.size() >= 3);
    }
};