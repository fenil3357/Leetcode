class Solution {
public:
    bool validateStackSequences(vector<int>& v1, vector<int>& v2) {
        int i=0, j=0;

        for(auto it : v1) {
            v1[i++] = it;

            while(i>0 && v1[i-1]==v2[j]){
                i--; j++;
            }
        }
        return (i == 0);
    }
};