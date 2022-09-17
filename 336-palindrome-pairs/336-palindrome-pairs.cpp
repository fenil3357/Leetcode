struct TrieNode {
    TrieNode *next[26] = {};
    int idx = -1;
    vector<int> palinIdx;
};

class Solution {
public:
    TrieNode root;

    void add(string &s, int i) {
        auto node = &root;

        for(int j=s.size()-1; j>=0; --j) {
            if(isPal(s, 0, j))
                node->palinIdx.push_back(i);

            int c = s[j] - 'a';
            if(!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }

        node->idx = i;
        node->palinIdx.push_back(i);
    }

    bool isPal(string &s, int i, int j) {
        while(i<j && s[i]==s[j]) ++i, --j;
        return (i >= j);
    }

    vector<vector<int>> palindromePairs(vector<string>& w) {
        int n = w.size();
        for(int i=0; i<n; i++) add(w[i], i);
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            auto s = w[i];
            auto node = &root;

            for(int j=0; j<s.size() && node; ++j) {
                if(node->idx != -1 && node->idx != i && isPal(s, j,s.size()-1)) ans.push_back({i, node->idx});
                // w[i]'s prefix matches this word and w[i]'s suffix forms a palindrome
                node = node->next[s[j] - 'a']; 
            }   

            if(!node) continue;

            for(int j : node->palinIdx) {
                // w[i] is exhausted in the matching above
                // If a word whose prefix is palindrome after matching its suffix with w[i]
                // then this is also a valid pair
                if(i != j) ans.push_back({i, j});
            }
        }
        return ans;
    }
};