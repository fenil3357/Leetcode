class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 1);
        
        int fromBeg = 1;
        int fromEnd = 1;
        
        for(int i=0; i<n; i++){
            ans[i] *= fromBeg;
            fromBeg *= nums[i];
            
            
            ans[n-i-1] *= fromEnd;
            fromEnd *= nums[n-i-1];
        }
        
        return ans;
    }
};