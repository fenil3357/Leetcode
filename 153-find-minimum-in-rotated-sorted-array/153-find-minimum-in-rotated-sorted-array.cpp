class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]){
                mn = nums[i];
                break;
            }
        }
        return mn;
    }
};