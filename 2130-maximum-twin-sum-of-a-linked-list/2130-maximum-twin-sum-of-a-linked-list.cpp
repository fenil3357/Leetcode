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
    int pairSum(ListNode* head) {
        ListNode *fast=head, *slow=head, *curr=head;

        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverse(slow);

        int mx = INT_MIN;

        while(slow){
            int sum = slow->val + curr->val;
            if(mx < sum) mx = sum;

            slow = slow->next;
            curr = curr->next;
        }
        return mx;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* next = head, *curr = head;

        while(curr){
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};