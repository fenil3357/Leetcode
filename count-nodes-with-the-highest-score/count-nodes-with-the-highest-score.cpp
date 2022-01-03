class Solution {
public:

    long dfs(vector<vector<int>> &G, long &u, long &N, long &mxSc, long &ans){
        long score = 1, cnt = 1;

        for(long v : G[u]){
            long c = dfs(G, v, N, mxSc, ans);
            cnt += c;
            score *= c;
        }

        long other = N - cnt;
        if(other) score*=other;

        if(score > mxSc){
            mxSc = score;
            ans = 0;
        }

        if(score == mxSc) ans++;
        return cnt;
    }
    int countHighestScoreNodes(vector<int>& p) {
        long N = p.size(), ans = 0, mxSc = 0;

        vector<vector<int>> G(N);
        for(int i=1; i<N; ++i) G[p[i]].push_back(i);
        long  u = 0;
        dfs(G, u, N, mxSc, ans);
        return ans;
    }
};