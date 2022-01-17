class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        
        int mx = 0;
        
        for(auto &x : s){
            if(s.count(x-1)) continue;
            
            int j = 1;
            while(s.count(x+j)) j++;
            mx = max(mx, j);
        }
        return mx;
    }
};