class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 0, r = 1e7;
        
        while(l < r) {
            auto mid = (l + r + 1)/2;
            
            auto sum = 0LL;
            
            for(auto it : candies) {
                sum += it/mid;
            } 
            
            if(sum >= k) {
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }
};