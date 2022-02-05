class Solution {
public:
    int minimumSum(int n) {
        
        vector<int> v;
        
        while(n>0){
            int x = n%10;
            v.push_back(x);
            n /= 10;
        }
        
        sort(v.begin(), v.end());
        
        int x = v[0]*10 + v[2];
        int y = v[1]*10 + v[3];
        
        return (x+y);
    }
};