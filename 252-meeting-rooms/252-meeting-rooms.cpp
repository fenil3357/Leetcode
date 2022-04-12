class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& in) {
        sort(in.begin(), in.end());
        
        if(in.size() == 0) return true;

        for(int i=0; i<in.size()-1; i++) {
            if(in[i][1] > in[i+1][0]) return false;
        }
        return true;
    }
};