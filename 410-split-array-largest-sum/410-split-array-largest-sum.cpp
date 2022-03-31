class Solution {
public:
    bool solve(const vector<int> &v, int cuts, long long mx) {
        int acc = 0;

        for(auto it : v) {
            if(it > mx) return false;

            else if(acc + it <= mx) acc += it;

            else{
                --cuts;
                acc = it;

                if(cuts < 0) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        long long l = 0, r = 0;

        for(auto it : nums) {
            l = max(l, (long long)it);
            r += it;
        }

        while(l < r) {
            long long mid = l + (r - l)/2;

            if(solve(nums, m-1, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};