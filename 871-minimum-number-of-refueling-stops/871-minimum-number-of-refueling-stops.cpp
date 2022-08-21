class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(), stations.end());
        int ans = 0, curr = startFuel, flg = 0;
        int n = stations.size();
        
        priority_queue<int, vector<int>> pq;
        
        for(int i=0; i<n; i++) {
            if(curr >= target) break;
            
            while(curr < stations[i][0]) {
                if(pq.empty()) { // Out of fuel in somewhere middle 
                    flg = 1;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop();
            }
            
            if(flg) break;
            pq.push(stations[i][1]);
        }
        
        if(flg) return -1;
        
        while(!pq.empty() && curr<target) {
            curr += pq.top();
            ans++;
            pq.pop();
        }
        
        if(curr < target) return -1; // couldn't reach target 
        
        return ans;
    }
};