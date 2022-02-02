class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        if(s.empty() || p.empty() || p.size()>s.size()) return ans;
        
        vector<int> temp(26, 0);
        
        for(int i=0; i<p.size(); i++)
            temp[p[i]-'a']++;
        
        int i=0;
        vector<int> temp1(26, 0);
        
        bool over = false;
        
        while(i <= (s.size()-p.size())){
            int k = i;
            int x = 0;
            while(k<s.size() && x<p.size()){
                temp1[s[k]-'a']++;
                k++;
                x++;
                
                if(x >= p.size()){
                    over = true;
                    break;
                }
            }    
                
            if(temp1 == temp){
                ans.push_back(i);
            }  
            temp1.clear();
            temp1.assign(26, 0);
            i++;
            
            // if(over) break;
        }
        
        return ans;
    }
};