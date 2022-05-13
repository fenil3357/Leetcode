class Solution {
public:

    void permutation(vector<int> &v) {
        if(v.size() <= 1) return;

        int pos = 0;

        for(int i=v.size()-2; i>=0; i--) {
            if(v[i] < v[i+1]) {
                pos = i;
                break;
            }
        }

        for(int i=v.size()-1; i>=pos; i--) {
            if(v[pos] < v[i]) {
                swap(v[i], v[pos]);
                pos++;
                break;
            }
        }

        reverse(begin(v) + pos, end(v));
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> initial(nums);
        do {
            res.push_back(nums);
            permutation(nums);
        }while(nums != initial);

        return res;
    }
};