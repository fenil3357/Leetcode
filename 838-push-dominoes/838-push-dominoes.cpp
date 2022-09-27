class Solution {
public:
    string pushDominoes(string dom) {
        dom = 'L' + dom + 'R';
        string res = "";
        
        for(int i=0, j=1; j<dom.size(); j++) {
            if(dom[j] == '.') continue;
            int middle_part_length = j - i - 1;
            
            if(i > 0) 
                res += dom[i];
            
            if(dom[i] == dom[j])
                res += string(middle_part_length, dom[i]);
            else if(dom[i] == 'L' and dom[j] == 'R')
                res += string(middle_part_length, '.');
            else
                res += string(middle_part_length/2, 'R') + string(middle_part_length % 2, '.') + string(middle_part_length / 2, 'L');
            
            i = j;
        }
        return res;
    }
};