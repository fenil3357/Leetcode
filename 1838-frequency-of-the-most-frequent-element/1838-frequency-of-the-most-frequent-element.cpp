class Solution {
public:
    int maxFrequency(vector<int>& v,long k) {
        sort(v.begin(), v.end());
        int i=0,j;

        for(j=0; j<v.size(); j++) {
            k += v[j];

            if(k < ((long)v[j] * (j-i+1)))  
                k -= v[i++];
        }
        return (j - i);
    }
};