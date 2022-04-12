class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& in) {
        map<int, int> mp;

        for(auto it : in) {
            mp[it[0]]++;
            mp[it[1]]--;
        }

        int curr = 0, res = 0;

        for(auto &it : mp) {
            curr += it.second;
            res = max(res, curr);
        }
        return res;
    }
};