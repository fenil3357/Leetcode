class Encrypter {
public:

	// To map all the keys with their values
    unordered_map<char, string> key_value_map;
	
	// To keep counts of all encrypted values of strings from dict
    unordered_map<string, int> dict_map;
	
	
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dict) {
	
		// Mapping all keys to their values
        for(int i=0; i<keys.size();i++)  key_value_map[keys[i]] = values[i];

		// Counting the number of encrypted strings from dict
        for(auto it : dict) dict_map[encrypt(it)]++;
    }
    
    string encrypt(string word1) {
        string ans;

        for(int i=0; i<word1.size(); i++) {

            // If we found a character not present in key we will add '#' to ans
            if(key_value_map.find(word1[i]) == key_value_map.end()) {
                ans += '#';
            }
            else
                ans += key_value_map[word1[i]];
        }

        return ans;
    }
    
    int decrypt(string word2) {
        // Returning the count of encrypted string from dict matching with word2
        return dict_map[word2];
    }
};