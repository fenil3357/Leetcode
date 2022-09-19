class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> Files;
        vector<vector<string>> ans;

        for(auto &p : paths) {
            int i=0,j;
            
            // Getting the directory name
            while(p[i] != ' ') i++;
            string dir = p.substr(0, i);
            string file, content;

            while(i++ < p.size()) {
                j = i;

                while(p[i] != '(') i++;
                file = p.substr(j, i-j);
                j = i;

                while(p[i++] != ')');
                content = p.substr(j, i-j);

                Files[content].emplace_back(dir + '/' + file);
            }
        }

        for(auto &content : Files) {
            if(content.second.size() > 1) {
                ans.push_back(content.second);
            }
        }

        return ans;
    }
};