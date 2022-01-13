class Solution {
public:
    bool exist(vector<vector<char>>& mat, string t) {
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(dfs(mat, i, j, t)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &mat, int i, int j, string &t){

        if(!t.size()) return true;

        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j] != t[0]){
            return false;
        }
        char c = mat[i][j];
        mat[i][j] = '*';

        string s = t.substr(1);
        bool ret = (dfs(mat, i-1, j, s) || dfs(mat, i+1, j, s) || dfs(mat, i, j+1, s) || dfs(mat, i, j-1, s));

        mat[i][j] = c;
        return ret;
    }
};