class Solution {
public:
    void permutation(unordered_map<int, int> &mp, vector<int> &curr, vector<vector<int>> &res, int n) {
        if(curr.size() == n) {
            res.push_back(curr);
            return;
        }

        for(auto it : mp) {
            if(it.second == 0) continue;
            
            curr.push_back(it.first);
            mp[it.first]--;

            permutation(mp, curr, res, n);

            curr.pop_back();
            mp[it.first]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        unordered_map<int, int> mp;

        for(auto it : nums) mp[it]++;

        vector<int> curr;
        permutation(mp, curr, res, nums.size());
        return res;
    }
};