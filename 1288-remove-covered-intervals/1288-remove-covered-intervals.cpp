class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        int n = v.size();
        
        if(n == 0) return 0;
        
        //Sorting Element In Desired Order
        sort(v.begin(), v.end(), [](vector<int> &v1, vector<int> &v2) {
            if(v1[0] == v2[0]) 
                return (v1[1] <= v2[1]);
            
            return (v1[0] <= v2[0]);
        });
        
        int cnt = n;
        pair<int, int> prev = {v[0][0], v[0][1]};  //Keeping values of biggest interval 
        int flg = 0;
        
        for(auto it : v) {
            if(!flg) flg=1;     //Not checking for the first element
            
            else{
                //If prev is covered by current, then we have to change values of prev
                if((prev.first >= it[0]) && (prev.second <= it[1])) {    
                    cnt--;
                    prev.first = it[0];
                    prev.second = it[1];
                }
                
                //If current is covered by prev, then no need to change values of prev
                else if((prev.first <= it[0]) && (prev.second >= it[1])) {
                    cnt--;
                }
                
                //If nothing is covered, we have to change values of prev (Already in sorted order)
                else {
                    prev.first = it[0];
                    prev.second = it[1];
                }
            }
        }
        return cnt;
    }
};