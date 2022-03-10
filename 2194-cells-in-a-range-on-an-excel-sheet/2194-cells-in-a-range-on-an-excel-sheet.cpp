class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        
        char st = s[0], end = s[3];
        int rowSt = (int)s[1];
        int rowEnd = (int)s[4];
        
        for(char c = st; c <= end; c++) {
            for(int i=rowSt; i<=rowEnd; i++){
                string temp = "";
                temp.push_back(c);
                temp.push_back(i);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};