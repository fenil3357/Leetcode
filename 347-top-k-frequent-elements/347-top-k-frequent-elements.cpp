class Solution {
public:
        vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> umap;
        
        for(int i=0;i<nums.size();i++)
            umap[nums[i]]++;
        
        priority_queue<pair<int,int>> maxH;
        
        for(auto x:umap)
        {
            maxH.push({x.second,x.first});
        }
        
        vector<int>res;
        for(int i=0;i<k;i++)
        {
            res.push_back(maxH.top().second);
            maxH.pop();
        }
        return res;
    }
};