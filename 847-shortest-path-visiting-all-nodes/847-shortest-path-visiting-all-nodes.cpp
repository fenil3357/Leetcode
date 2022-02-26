class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {

        int n = graph.size();
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> vis;
        int mask1 = (1 << n) - 1;
        for (int i = 0; i < n; i++)
        {
            int mask = 1 << i;
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }
        while (!q.empty())
        {
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            int node = p.first;
            int dis = p.second.first;
            int mask = p.second.second;
            if (mask == mask1)
                return dis;
            for (auto x : graph[node])
            {
                int newmask = mask | (1 << x);
                if (vis.count({x, newmask}))
                    continue;
                else
                {
                    q.push({x, {dis + 1, newmask}});
                    vis.insert({x, newmask});
                }
            }
        }
        return 0;
    }
};