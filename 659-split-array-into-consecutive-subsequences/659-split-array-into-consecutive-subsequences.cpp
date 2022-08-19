class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mp1, mp2;
        
        for(auto &i : nums) mp1[i]++;
        
        for(auto &i : nums) {
            if(mp1[i] == 0) continue;
            
            if(mp2[i] > 0) {
                mp2[i]--;
                mp1[i]--;
                mp2[i+1]++;
            }
            else if(mp1[i]>0 && mp1[i+1]>0 && mp1[i+2]>0) {
                mp1[i]--;
                mp1[i+1]--;
                mp1[i+2]--;
                mp2[i+3]++;
            }
            else return false;
        }
        return true;
    }
};