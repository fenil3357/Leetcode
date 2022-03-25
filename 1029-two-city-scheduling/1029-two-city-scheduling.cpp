class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return ((v1[0]-v1[1]) < (v2[0]-v2[1]));
        });

        int cost = 0;

        for(int i=0; i<costs.size()/2; i++) {
            cost += costs[i][0];
        }

        for(int i=costs.size()/2; i<costs.size(); i++) {
            cost += costs[i][1];
        }
        return cost;
    }
};