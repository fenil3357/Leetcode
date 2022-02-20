class Solution {
public:
    bool cmp(vector<int> &v1, vector<int> &v2) {
        if(v1[0] == v2[0]) return (v1[1] <= v2[1]);
        
        return (v1[0] <= v2[0]);
    }
    
    int removeCoveredIntervals(vector<vector<int>>& v) {
        int n = v.size();
        
        if(n == 0) return 0;
        
        sort(v.begin(), v.end(), [](vector<int> &v1, vector<int> &v2) {if(v1[0] == v2[0])           return (v1[1] <= v2[1]);
        
        return (v1[0] <= v2[0]);});
        
        int cnt = n;
        pair<int, int> prev = {v[0][0], v[0][1]};
        int flg = 0;
        
        for(auto it : v) {
            if(!flg) flg=1;     //Not checking for the first element
            
            else{
                if((prev.first >= it[0]) && (prev.second <= it[1])) {
                    cnt--;
                    prev.first = it[0];
                    prev.second = it[1];
                }
                else if((prev.first <= it[0]) && (prev.second >= it[1])) {
                    cnt--;
                }
                else {
                    prev.first = it[0];
                    prev.second = it[1];
                }
            }
        }
        return cnt;
    }
};