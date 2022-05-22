struct Trie{
    unordered_map<int, Trie*> ch;
    int cnt = 0;

    int insert(vector<int> &v, int i, int k, int p) {
        if(i == v.size() || k - ((v[i] % p) == 0) < 0)
            return 0;

        if(ch[v[i]] == nullptr)
            ch[v[i]] = new Trie();
            
        return (++ch[v[i]]->cnt == 1) + (ch[v[i]]->insert(v, i+1, k-((v[i]%p)==0), p));
    }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int res = 0;
        Trie t;

        for(int i=0; i<nums.size(); i++) {
            res += t.insert(nums, i, k, p);
        }
        return res;
    }
};