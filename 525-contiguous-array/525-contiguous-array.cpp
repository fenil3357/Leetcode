class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> mp{{0, -1}};
        int sum = 0, mx=0;
        
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i]==1 ? 1 : -1);
            
            if(mp.count(sum)) mx = max(mx, i-mp[sum]);
            else mp[sum] = i;
        }
        return mx;
    }
};