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
    ListNode *reverseK(ListNode *&head, int k) {
        
        if(!head || !head->next) return head;
        
        ListNode *prevptr = NULL, *currptr = head, *nextptr;
        int count = 0;

        while (currptr != NULL && count < k) {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count++;
        }

        if (nextptr != NULL) {
            head->next = reverseK(nextptr, k);
        }

        return prevptr;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        return reverseK(head, 2);
    }
};