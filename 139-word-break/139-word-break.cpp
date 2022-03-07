struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }    
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    } 
    
    Node* get(char ch){
        return links[ch - 'a'];
    }   
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
        
};


class Trie {

private:
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                node->put(word[i], new Node());
            
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                return false;
            
            node = node->get(word[i]);
        }
        
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        
        for(int i=0; i<prefix.size(); i++){
            if(!node->containsKey(prefix[i]))
                return false;
            
            node = node->get(prefix[i]);
        }
        return true;
    }
};


class Solution {
public:
    int dp[305][305];
    bool solve(string &s, Trie root, int n, int st) {
        if(st == n) return true;
        if(dp[st][n] != -1) return dp[st][n];
        
        for(int i=st; i<n; i++) {
            string str = s.substr(st, i-st+1);
            if(root.search(str)) {
                if(solve(s, root, n, i+1)) return dp[st][n] = true;
            }
        }
        return dp[st][n] = false;
    }
    
    bool wordBreak(string s, vector<string>& wd) {
        Trie t;
        for(auto it : wd) t.insert(it);
        
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, t, n, 0);
    }
};