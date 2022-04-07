class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        sort(stones.begin(), stones.end());
        
        while(stones.size()>1)
        {
            int x = stones[stones.size()-2];
            int y = stones[stones.size()-1];
            
            stones.pop_back();
            stones.pop_back();
            
            if(x!=y)
            {
                stones.push_back(y-x);
            }
            
            sort(stones.begin(), stones.end());
        }
        
        return stones.size()==0 ? 0 : stones[0];
    }
};
   