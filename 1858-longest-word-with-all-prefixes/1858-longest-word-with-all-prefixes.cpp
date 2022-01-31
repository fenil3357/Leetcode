struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    Node* root;
    
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string &s){
        Node* node = root;
        
        for(int i=0; i<s.size(); i++){
            if(!node->containsKey(s[i]))
                node->put(s[i], new Node());
                
            node = node->get(s[i]);
        }
        node->setEnd();
    }
    
    bool solve(string s){
        Node* node = root;
        bool flg = true;
        for(int i=0; i<s.size(); i++){
            if(node->containsKey(s[i])){
                node = node->get(s[i]);
                flg = flg && node->isEnd();
            }
            else return false;
        }
        return flg;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        
        Trie t;
        for(auto it : words){
            t.insert(it);
        }
        
        string longest = "";
        
        for(auto it : words){
            if(t.solve(it)){
                if(it.size() > longest.size())
                    longest = it;
                
                else if((it.size() == longest.size()) and (it < longest))
                    longest = it;
            }    
        }
        return longest;
    }
};