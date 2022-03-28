class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& v1, vector<int>& v2) {
        unordered_map<int, bool> mp1, mp2;

        for(auto it : v1) mp1[it] = true;

        for(auto it : v2)  {
            mp1[it] = false;
            mp2[it] = true;
        }
        for(auto it : v1) {
            mp2[it] = false;
        }

        vector<vector<int>> ans;

        vector<int> curr1;
        for(auto it : mp1) {
            if(it.second)
                curr1.push_back(it.first);
        }
        ans.push_back(curr1);

        vector<int> curr2;

        for(auto it : mp2) {
            if(it.second)
                curr2.push_back(it.first);
        }
        ans.push_back(curr2);
        return ans;
    }
};