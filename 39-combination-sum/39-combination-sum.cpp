class Solution {
public:
    
    void helper(int idx, int t,vector<int> &v, vector<int> &temp, vector<vector<int>> &ans){
        
        if(idx == v.size()){
            if(t == 0) ans.push_back(temp);
            return;
        }
        
        
        //Including the element
        if(v[idx] <= t){
            temp.push_back(v[idx]);
            helper(idx, t-v[idx], v, temp, ans);
            temp.pop_back();
        }
        
        //Not including the element
        helper(idx+1, t, v, temp, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, t, v, temp, ans);    
        return ans;
    }
};