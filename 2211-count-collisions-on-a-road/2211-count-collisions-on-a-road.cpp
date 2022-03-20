class Solution {
public:
    int countCollisions(string dir) {
        
        int cnt = 0, i=0, n = dir.size(), carsFromRight = 0;

        while(i < n && dir[i] == 'L') i++;

        for(; i<n; i++) {
            if(dir[i] == 'R') {
                carsFromRight++;
            }
            else{
                cnt += (dir[i] == 'S') ? carsFromRight : carsFromRight+1;
                carsFromRight = 0;
            }
        }
        return cnt;        
    }
};