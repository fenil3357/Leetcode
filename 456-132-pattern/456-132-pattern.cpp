class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int thrdEle = INT_MIN;

        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i] < thrdEle) return true;
            while(!st.empty() && st.top()<nums[i]) {
                thrdEle = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};