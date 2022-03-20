class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        
        vector<int> cntA(7), cntB(7), same(7);

        int n = t.size();

        for(int i=0; i<n; i++) {
            cntA[t[i]]++;
            cntB[b[i]]++;
            if(t[i] == b[i]) same[t[i]]++;
        }

        for(int i=0; i<7; i++) {
            if(cntA[i]+cntB[i]-same[i] == n) {
                return n - max(cntA[i], cntB[i]);
            }
        } 
        return -1;
    }
};