class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());

        long long mn = LLONG_MAX, sum = accumulate(beans.begin(), beans.end(), 0LL);
        long long n = beans.size();

        for(int i=0; i<n; i++) {
            mn = min(mn, sum - (n-i)*beans[i]);
        }
        return mn;
    }
};