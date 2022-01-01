class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int cnt = 0;
        unordered_map<int, int> mp;
        
        for(int a : nums){
            cnt += mp[a]++;
        }
        return cnt;
    }
};