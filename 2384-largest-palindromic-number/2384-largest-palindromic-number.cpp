class Solution {
public:
    string largestPalindromic(string num) {
        if(num.empty()) return num;

        string ans1, ans2;
        vector<int> cnt(10);
        for(auto &i : num) cnt[i - '0']++;

        for(int i=9; i>=0; i--) {
            if(i==0 && ans1.empty()) break;

            int tmp = cnt[i]/2;
            for(int j=0; j<tmp; j++) ans1.push_back(i + '0');
            cnt[i] -= 2*tmp;
        }

        ans2 = ans1;
        reverse(ans2.begin(), ans2.end());
        
        for(int i=9; i>=0; i--) {
            if(cnt[i]) {
                ans1.push_back(i + '0');
                break;
            }
        }

        return (ans1 + ans2);
    }
};