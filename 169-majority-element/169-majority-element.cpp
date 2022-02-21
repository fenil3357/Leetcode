class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 1;
        int mxIdx = 0;
        
        for(int i=1; i<nums.size();i++){
            if(nums[mxIdx] == nums[i]) cnt++;
            else cnt--;
            
            if(cnt == 0){
                mxIdx = i;
                cnt = 1;
            }
        }
        
        return nums[mxIdx];
    }
};