class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.empty()) return "";

        stack<char> st;
        string ans = "";

        for(int i=0; i<s.size(); i++) {
            if(s[i]>='a' && s[i]<='z') {
                ans.push_back(s[i]);
                continue;
            }

            if(s[i] == '(') {
                ans.push_back('(');
                st.push('(');
            }

            else if(s[i] == ')') {
                if(!st.empty() && st.top() == '(') {
                    ans.push_back(')');
                    st.pop();
                }
            }
        }

        while(!st.empty()) st.pop();

        for(int i=ans.size()-1; i>=0; i--) {
            if(ans[i] == ')') st.push(')');
            else if(ans[i] == '(') {
                if(!st.empty() && st.top()==')') {
                    st.pop();
                }
                else ans.erase(i, 1);
            }
        }
        return ans;
    }
};