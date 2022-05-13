class Solution {
public:

    void permutation(vector<int> v, vector<vector<int> > &res, int idx) {
        if(idx == v.size()) {
            res.push_back(v);
        }

        for(int i=idx; i<v.size(); i++) {
            if(i != idx && v[i]==v[idx]) continue;
            swap(v[i], v[idx]);
            permutation(v, res, idx+1);
        }
    }
     
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        sort(begin(nums), end(nums));
        permutation(nums, res, 0);
        return res;
    }
};