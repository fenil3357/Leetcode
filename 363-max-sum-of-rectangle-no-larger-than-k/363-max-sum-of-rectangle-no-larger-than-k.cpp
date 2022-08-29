class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return 0;

        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;

        for(int l=0; l<col; ++l) {
            vector<int> sum(row, 0);

            for(int r=l; r<col; ++r) {
                for(int i=0; i<row; i++)
                    sum[i] += matrix[i][r];

                // Finding the max saubarray with sum no more than K
                set<int> st;
                st.insert(0);

                int currSum = 0, curMx = INT_MIN;

                for(auto &s : sum) {
                    currSum += s;
                    set<int>::iterator it = st.lower_bound(currSum - k);

                    if(it != st.end()) 
                        curMx = max(curMx, currSum - *it);

                    st.insert(currSum);
                }    

                res = max(res, curMx);
            }
        }
        return res;
    }
};