class Solution {
public:
    void solve(vector<int> &curr, vector<vector<int> > &res, unordered_map<int, int> &mp, int n) {
        if(curr.size() == n) {
            res.push_back(curr);
            return;
        }

        for(auto it : mp) {
            if(it.second == 0) continue;

            curr.push_back(it.first);
            mp[it.first]--;

            solve(curr, res, mp, n);

            curr.pop_back();
            mp[it.first]++;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> curr;
        int n = nums.size();
        unordered_map<int, int> mp;

        for(auto it : nums) mp[it]++;

        solve(curr, res, mp, n);
        return res;
    }
};