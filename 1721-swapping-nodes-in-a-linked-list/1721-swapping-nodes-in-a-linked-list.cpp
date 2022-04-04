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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        ListNode* temp = head;

        while(temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        swap(v[k-1], v[v.size()-k]);

        temp = head;
        
        for(auto it : v) {
            temp->val = it;
            temp = temp->next;
        }
        return head;
    }
};