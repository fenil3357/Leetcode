class Encrypter {
public:
    unordered_map<char, string> mp;
    unordered_map<string, int> m;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dict) {
        for(int i=0; i<keys.size();i++) {
            mp[keys[i]] = values[i];
        }

        for(auto it : dict) m[encrypt(it)]++;
    }
    
    string encrypt(string word1) {
        string ans;

        for(int i=0; i<word1.size(); i++) {
            if(mp.find(word1[i]) == mp.end()) {
                ans += '#';
            }
            else
                ans += mp[word1[i]];
        }

        return ans;
    }
    
    int decrypt(string word2) {
        return m[word2];
    }
};