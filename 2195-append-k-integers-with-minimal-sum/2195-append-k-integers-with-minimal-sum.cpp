class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long res = (long long)k * (k+1)/2;
        
        for(auto it : set<int>(begin(nums), end(nums))) {
            if(it <= k)
                res += (++k)-it;
        }
        return res;
    }
};