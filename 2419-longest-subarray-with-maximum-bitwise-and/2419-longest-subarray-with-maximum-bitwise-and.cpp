class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mxLen = 0;
        int curr = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == mx) {
                curr++;
            }
            else curr = 0;

            mxLen = max(mxLen, curr);
        }

        return mxLen;
    }
};