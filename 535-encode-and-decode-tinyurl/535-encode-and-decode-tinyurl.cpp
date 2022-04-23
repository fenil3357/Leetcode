class Solution {
public:
    map<string, string> mp;
    // Encodes a URL to a shortened URL.
    int cnt = 1;
    string encode(string longUrl) {
        string ans = "";
        ans = to_string(cnt);
        mp[ans] = longUrl;
        cnt++;
        return ans;
    }

    
    // Decodes a shortened URL to its original URL.
    
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));