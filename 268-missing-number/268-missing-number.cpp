class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arrXor=0, idxXor=0;
        
        for(int i=0; i<nums.size(); i++){
            arrXor ^= nums[i];
            idxXor ^= (i+1);
        }
        return (arrXor ^ idxXor);
    }
};