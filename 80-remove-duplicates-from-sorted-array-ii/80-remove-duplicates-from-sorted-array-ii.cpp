class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k=0;
        
        for(auto it : nums){
            if(k<2 || it > nums[k-2])
                nums[k++] = it;
        }
        return k;
    }
};