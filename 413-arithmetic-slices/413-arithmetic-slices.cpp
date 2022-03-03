class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) return 0;
        
        int prevDiff = nums[1] - nums[0];
        int res = 0;
        int cnt = 0;
        
        for(int i=1; i<n-1; i++) {
            if((nums[i+1]-nums[i]) == prevDiff){
                cnt++;
            }
            else{
                cnt = 0;
                prevDiff = nums[i+1]-nums[i];
            }
            res += cnt;
        }
        return res;
    }
};