class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans;
        if(nums.size() == 0) return ans;
        int prod = 1;
        
        for(int i=0; i<nums.size(); i++)
            prod *= nums[i];
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                ans.push_back(prod/nums[i]);
            }
            else{
                int temp = 1;
                for(int j=0; j<nums.size(); j++)
                    if(j!=i) temp *= nums[j];
                ans.push_back(temp);
            }
        }
            
        
        return ans;
    }
};