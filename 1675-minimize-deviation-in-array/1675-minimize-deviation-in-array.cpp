class Solution {
public:
    int minimumDeviation(vector<int>& v) {
        
        int n = v.size();
        int mx = INT_MIN, mn = INT_MAX;
        priority_queue<int> pq;
        
        for(auto it : v) {
            if(it%2)
                it *= 2;
            
            mn = min(mn, it);
            mx = max(mx, it);
            
            pq.push(it);
        }
        
        int minDev = mx - mn;
        
        while(pq.top()%2 == 0) {
            int top = pq.top();
            pq.pop();
            
            minDev = min(minDev, top-mn);
            top /= 2;
            mn = min(mn, top);
            pq.push(top);
        }
        
        minDev = min(minDev, pq.top() - mn);
        return minDev;
    }
};