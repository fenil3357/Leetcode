class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;

        for(auto &it: nums) if(it%2 == 0) sum += it;
        vector<int> ans;

        for(auto &it : queries) {
            int val = it[0], idx = it[1];

            if(nums[idx]%2 == 0) sum -= nums[idx];

            int curr = nums[idx] + val;
            nums[idx] = curr;

            if(curr%2 == 0) sum += curr;
            ans.push_back(sum);
        }
        return ans;
    }
};