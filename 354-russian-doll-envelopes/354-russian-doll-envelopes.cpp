class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(begin(env), end(env), [&](vector<int> &v1, vector<int> &v2) {
            if(v1[0] != v2[0]) 
                return (v1[0] <= v2[0]);
            else
                return (v1[1] >= v2[1]);
        });

        vector<int> dp;

        for(auto it : env) {
            auto iter = lower_bound(dp.begin(), dp.end(), it[1]);
        
            if(iter == dp.end()) 
                dp.push_back(it[1]);
            else if(it[1] < *iter) 
                *iter = it[1];
        }
        return dp.size();
    }
};