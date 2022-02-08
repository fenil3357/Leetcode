class Bitset {
public:
    vector<int> v;
    int cnt, cntFlip;
    Bitset(int size) {
        v.resize(size, 0);
        cnt=0, cntFlip=0;
    }
    
    void fix(int idx) {
        if((v[idx] + cntFlip)%2 == 0){
            v[idx]++;
            cnt++;
        }
    }
    
    void unfix(int idx) {
        if((v[idx]+cntFlip)%2){
            v[idx]--;
            cnt--;
        }
    }
    
    void flip() {
        cnt = v.size()-cnt;
        cntFlip++;
    }
    
    bool all() {
        if(cnt == v.size()) return true;
        return false;
    }
    
    bool one() {
        if(cnt>=1) return true;
        return false;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string str;
        
        for(int i=0; i<v.size(); i++){
            if((v[i]+cntFlip)%2 == 0){
            str.push_back('0');
        }
        else{
            str.push_back('1');
        }
        }
        
        return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */