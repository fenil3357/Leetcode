class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);
        if(n == 0) return ans;
        
        vector<int> fromBeg(n), fromEnd(n);
        fromBeg[0] = 1;
        fromEnd[0] = 1;
        
        for(int i=1; i<n; i++){
            fromBeg[i] = fromBeg[i-1]*nums[i-1];
            fromEnd[i] = fromEnd[i-1]*nums[n-i];
        }
        
        for(int i=0; i<n; i++){
            ans[i] = fromBeg[i]*fromEnd[n-i-1];
        }
        
        return ans;
    }
};