int uf[26];
class Solution {
public:
    bool equationsPossible(vector<string>& eq) {
        for(int i=0; i<26; i++) uf[i] = i;
        
        for(string e : eq) {
            if(e[1] == '=')
                uf[find(e[0] - 'a')] = find(e[3] - 'a');
        }
        
        for(string e : eq) 
            if(e[1] == '!' and find(e[0] - 'a') == find(e[3] - 'a')) return false;
        
        return true;
    }
    
    int find(int x) {
        if(x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};