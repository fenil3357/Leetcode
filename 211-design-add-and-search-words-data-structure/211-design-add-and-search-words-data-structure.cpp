struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        if(links[ch - 'a'] != NULL) return true;
        return false;
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

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                node->put(word[i], new Node());
            
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool solve(string word, Node* node) {
        for(int i=0; i<word.size(); i++) {
            if(word[i] == '.') {
                for(char ch='a'; ch<='z'; ch++){
                    if(node->containsKey(ch) && solve(word.substr(i+1), node->get(ch))) return true;
                }
                return false;
            }
            else{
                if(!node->containsKey(word[i])) return false;
            }
            
            node = node->get(word[i]);
        }
        
        if(node->isEnd()) return true;
        return false;
    }
    
    bool search(string s) {
        return solve(s, root);
    }
};

