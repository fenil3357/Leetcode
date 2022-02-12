class Solution {
public:
    int ladderLength(string s, string t, vector<string>& v) {
        unordered_set<string> st;
        bool isPresent = false;
        
        for(auto it : v){
            if(t.compare(it) == 0)
                isPresent = true;
            
            st.insert(it);
        }
        
        if(isPresent == false) return 0;
        
        queue<string> q;
        q.push(s);
        int depth = 0;
        
        while(!q.empty()){
            depth++;
            
            int size = q.size();
            while(size--) {
                string curr = q.front();
                q.pop();
                
                for(int i=0; i<curr.size(); i++){
                    string temp = curr;
                    
                    for(char c='a'; c<='z'; c++) {
                        temp[i] = c;
                        
                        if(curr.compare(temp) == 0)
                            continue;
                        
                        if(temp.compare(t) == 0) return depth+1;
                        
                        if(st.find(temp) != st.end()) {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};