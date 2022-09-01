class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);

        int st = 0, mxCnt = 0, n = s.size(), res = 0;

        for(int end = 0; end < n; end++) {
            count[s[end] - 'A']++;

            if(mxCnt < count[s[end] - 'A']) 
                mxCnt = count[s[end] - 'A'];

            while((end-st-mxCnt+1) > k) {
                count[s[st] - 'A']--;
                st++;

                for(int i=0; i<26; i++) {
                    if(mxCnt < count[i])
                        mxCnt = count[i];
                }
            }
            res = max(res, end-st+1);
        }
        return res;
    }
};