class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> mem(n+1, -1);
        mem[n] = 1;
        return s.empty() ? 0 : num(0, s, mem);
    }
    
    int num(int idx, string &s, vector<int> &mem){
        if(mem[idx] > -1) return mem[idx];
        
        if(s[idx] == '0') return mem[idx] = 0;
        
        int res = num(idx+1, s, mem);
        
        if(idx<s.size()-1 and (s[idx]=='1' || s[idx]=='2' and s[idx+1]<'7'))
            res += num(idx+2, s, mem);
        
        return mem[idx] = res;
    }
};