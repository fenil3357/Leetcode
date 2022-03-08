class Solution {
public:
    struct cmp{
        bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
            if(a.first != b.first) return a.first > b.first;
            return a.second.second > b.second.second;
        }
    };
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
        
        for(int i=0; i<nums.size(); i++) {
            string temp = to_string(nums[i]);  // Original Number
            string newStr = "";                // Mapped Value
            
            for(int j=0; j<temp.size(); j++) {
                newStr += to_string(mapping[temp[j]-'0']);
            }
            pq.push({stoi(newStr), {nums[i], i}});
        }
        vector<int> ans;
        
        while(!pq.empty()) {
            ans.push_back(pq.top().second.first);
            pq.pop();
        }
        return ans;
    }
};
