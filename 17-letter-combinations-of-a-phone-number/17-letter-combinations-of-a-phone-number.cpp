class Solution {
public:

    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> res;
        res.push_back("");

        for(auto it1 : digits) {
            vector<string> temp;

            for(auto it2 : pad[it1 - '0']) {
                for(auto s : res) {
                    temp.push_back(s + it2);
                }
            }
            res.swap(temp);
        }

        return res;
    }
};