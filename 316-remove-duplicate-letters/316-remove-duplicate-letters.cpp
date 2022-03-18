class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<int> st;
        unordered_map<int, bool> vis;
        string ans = "";
        int lastIdx[26];
        
        for(int i=1; i<=26; i++) vis[i] = false;
        
        for(int i=0; i<s.size(); i++) lastIdx[s[i] - 'a'] = i;
        
        for(int i=0; i<s.size(); i++) {
            int val = s[i] - 'a';
            
            if(vis[val]) continue;
            
            while(!st.empty() && st.top()>val && lastIdx[st.top()]>i) {
                vis[st.top()] = false;
                st.pop();
            } 
            st.push(val);
            vis[val] = true;
        }
        
        while(!st.empty()) {
            ans += st.top() + 'a';
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};