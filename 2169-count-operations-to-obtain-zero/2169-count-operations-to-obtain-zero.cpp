class Solution {
public:
    int countOperations(int n1, int n2) {
        if(n1 == 0 || n2 == 0) return 0;
        if(n1 == n2) return 1;
        
        if(n1 > n2) return countOperations(n1-n2, n2)+1;
        else return countOperations(n1, n2-n1)+1;
    }
};