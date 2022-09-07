class Solution {
public:
    int longestNiceSubarray(vector<int>& v) {
        int usedBits = 0, j = 0, res = 0;

        for(int i=0; i<v.size(); i++) {
            while((usedBits & v[i]) != 0)    // add bits until it is following the condition
                usedBits ^= v[j++];

            usedBits |= v[i];              // Remove bits until it is not following the condition
            res = max(res, i - j + 1);
        }
        return res;
    }
};