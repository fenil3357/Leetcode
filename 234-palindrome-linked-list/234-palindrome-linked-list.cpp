/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool solve(vector<int> &v) {
        int n = v.size();
        if(n <= 1) return true;
        int i=0, j=n-1;
        
        while(i <= j) {
            if(v[i] != v[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        vector<int> v;
        ListNode* tmp = head;
        while(tmp) { v.push_back(tmp->val); tmp = tmp->next; }
        return solve(v);
    }
};