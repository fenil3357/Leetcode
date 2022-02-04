class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int k) {
        
        int n = v.size();
        if(n < 4) return {};
        
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(v.begin(), v.end());
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int temp = k - v[i] - v[j];
                int l=j+1, r=n-1;
                
                while(l < r){
                    if((v[l] + v[r]) == temp){
                        st.insert({v[i], v[j], v[l], v[r]});
                        l++; r--;
                    }
                    else if((v[l] + v[r]) < temp) l++;
                    else r--;
                }
            }
        }
        ans.assign(st.begin(), st.end());
        return ans;
    }
};