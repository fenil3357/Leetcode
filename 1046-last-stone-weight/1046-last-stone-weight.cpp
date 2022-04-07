class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;

        for(auto it : stones) pq.push(it);
        
        while(pq.size() != 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            if(x == y && pq.empty()) return 0;

            if(x != y) pq.push(abs(x-y));
        }

        return pq.top();
    }
};