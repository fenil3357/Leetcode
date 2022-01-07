class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& nIn) {
        vector<vector<int>> ans;
        in.push_back({nIn[0], nIn[1]});
        sort(in.begin(), in.end());
        
        pair<int, int> prev = {in[0][0], in[0][1]};
        int n = in.size();
        
        for(int i=1; i<n; i++){
            if(in[i][0] > prev.second){
                ans.push_back({prev.first, prev.second});
                prev = {in[i][0], in[i][1]};
            }
            else{
                prev.second = max(prev.second, in[i][1]);
            }
        }
        ans.push_back({prev.first, prev.second});
        
        return ans;
    }
};