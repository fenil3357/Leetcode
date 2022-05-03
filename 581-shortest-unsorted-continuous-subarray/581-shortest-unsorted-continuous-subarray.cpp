class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxL(n), minR(n);

        for(int i=0, mx=INT_MIN; i<n; i++) 
            maxL[i] = mx = max(mx, nums[i]);

        for(int i=n-1, mn=INT_MAX; i>=0; i--)
            minR[i] = mn = min(mn, nums[i]);

        int i = 0, j = n - 1;

        while(i<n && nums[i] <= minR[i]) i++;
        while(j>i && nums[j] >= maxL[j]) j--;

        return (j - i + 1);
    }
};