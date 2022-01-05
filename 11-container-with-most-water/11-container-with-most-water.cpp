class Solution {
public:
    int maxArea(vector<int>& hg) {
        int water = 0, i=0, j=hg.size()-1;
        
        while(i<j){
            int h = min(hg[i], hg[j]);
            water = max(water, (j-i)*h);
            
            while(hg[i] <= h and i<j) i++;
            while(hg[j] <= h and i<j) j--;
        }
        return water;
    }
};