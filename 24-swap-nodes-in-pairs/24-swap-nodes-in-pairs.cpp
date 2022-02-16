class Solution {
public:
    ListNode *reverseK(ListNode *&head, int k)
{
    if(!head) return nullptr;
    if(!head->next) return head;
        
    ListNode *prevptr = NULL;
    ListNode* currptr = head;
    ListNode *nextptr;
    int count = 0;

    while (currptr != NULL && count < k) {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr != NULL)
        head->next = reverseK(nextptr, k);

    return prevptr;
}
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        return reverseK(head, 2);
    }
};