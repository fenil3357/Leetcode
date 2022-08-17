class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string data[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        
        for(auto &it : words) {
            string curr = "";
            for(auto &i : it) {
                curr += data[i - 'a'];
            }
            s.insert(curr);
        }
        
        return s.size();
    }
};