class Solution {
public:
    string removeKdigits(string s, int k) {
        if(k == 0) return s;
        if(k >= s.size()) return "0";
        
        string ans = "";
        stack<char> st;
        
        st.push(s[0]);
        
        for(int i=1; i<s.size(); i++) {
            while(k>0 && !st.empty() && s[i]<st.top()) {
                --k;
                st.pop();
            }
            st.push(s[i]);
            
            if(st.size() == 1 && s[i]=='0') st.pop();
        }
        
        while(k && !st.empty()) {
            k--;
            st.pop();
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        if(ans.size() == 0) return "0";
        return ans;
    }
};