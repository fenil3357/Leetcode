class Solution {
public:
    vector<vector<int> > ans;
    
    void solve(vector<int> &subset, int i, vector<int> &nums) {
        if(i == nums.size()) {
            ans.push_back(subset);
            return;
        }
        
        solve(subset, i+1, nums);
        subset.push_back(nums[i]);
        solve(subset, i+1, nums);
        subset.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        
        solve(subset, 0, nums);
        return ans;
    }
};