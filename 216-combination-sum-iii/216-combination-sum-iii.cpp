class Solution {
public:
    
    void helper(int idx, int t,vector<int> &v, vector<int> &temp, vector<vector<int>> &ans, int k){
        
        if(idx == v.size()){
            if(t == 0 && k == 0) ans.push_back(temp);
            return;
        }
        
        
        //Including the element
        if(v[idx] <= t){
            temp.push_back(v[idx]);
            helper(idx + 1, t-v[idx], v, temp, ans, k-1);
            temp.pop_back();
        }
        
        //Not including the element
        helper(idx+1, t, v, temp, ans, k);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        
        if(k > n) return ans;
        
        vector<int> v;
        for(int i=1; i<=n; i++) {
            if(i <= 9) v.push_back(i);
            else break;
        }
        vector<int> temp;
        
        helper(0, n, v, temp, ans, k);
        return ans;
    }
};