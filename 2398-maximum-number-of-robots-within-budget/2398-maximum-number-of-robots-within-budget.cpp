class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        long long i = 0, j, sum = 0, n = chargeTimes.size();
        multiset<int> s;

        for(j=0; j<n; j++) {
            sum += runningCosts[j];
            s.insert(chargeTimes[j]);

            if(*rbegin(s) + sum*(j-i+1) > budget) {
                sum -= runningCosts[i];
                s.erase(s.find(chargeTimes[i++]));
            }
        }

        return (n - i);
    }
};
