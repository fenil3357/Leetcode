class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int> > st;      

        for(auto it : s) {
            if(!st.empty() && st.top().first==it) {
                st.push(make_pair(it, st.top().second+1));

                if(st.top().second == k) {
                    for(int i=1; i<=k; i++) {
                        if(!st.empty()) st.pop();
                    }
                }
            }
            else{
                st.push(make_pair(it, 1));
            }
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top().first;
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};