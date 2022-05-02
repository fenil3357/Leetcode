class Solution {
public:
    string removeDigit(string s, char digit) {
        for(int i=0; i<s.size()-1; i++) {
            if(s[i]==digit && s[i+1]>digit) {
                return s.substr(0, i) + s.substr(i+1);
            }
        }

        int last_d = s.rfind(digit);

        return s.substr(0, last_d) + s.substr(last_d+1);
    }
};