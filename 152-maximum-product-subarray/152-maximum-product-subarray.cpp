class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans, mx, mn;
        ans = mx = mn = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < 0) swap(mx, mn);
            
            mx = max(mx*nums[i], nums[i]);
            mn = min(mn*nums[i], nums[i]);
            
            ans = max(ans, mx);
        }
        return ans;
    }
};