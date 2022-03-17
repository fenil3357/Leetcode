class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int curr = 0;
        
        for(auto it : s) {
            if(it == '(') {
                st.push(curr);
                curr = 0;
            }
            else{
                curr = st.top() + max(curr*2, 1);
                st.pop();
            }
        }
        return curr;
    }
};