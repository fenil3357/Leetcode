class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0) return "";
        vector<int> rem(128, 0);
        int req = t.size();

        for(int i=0; i<req; i++) rem[t[i]]++;

        int mn = INT_MAX, st=0, left=0, end=0;

        while(end <= s.size() and st < s.size()){
            if(req){
                if(end == s.size()) break;
                rem[s[end]]--;
                if(rem[s[end]] >= 0) req--;
                end++;
            }
            else{
                if(end - st < mn){
                    mn = end-st;
                    left = st;
                }
                rem[s[st]]++;
                if(rem[s[st]] > 0) req++;
                st++;
            }
        }

        return mn == INT_MAX ? "" : s.substr(left, mn);
    }
};