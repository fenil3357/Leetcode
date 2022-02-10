class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int cnt = 0;
        unordered_map<int, int> mp;
        int prefSum = 0;
        
        mp[0] = 1;

        for(int i=0; i<nums.size(); i++){
            prefSum += nums[i];
            
            if(mp.find(prefSum-k) != mp.end())
                cnt += mp[prefSum-k];
            
            mp[prefSum]++;
        }
        return cnt;
    }
};