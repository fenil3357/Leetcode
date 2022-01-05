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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head->next and n==1) return NULL;
        
        ListNode* temp = head;
        
        int cnt = 1;
        while(temp->next){
            temp = temp->next;
            cnt++;
        }
        
        temp = head;
        int tm = cnt-n;
        
        if(head->next and tm==0){
            ListNode* todelete = head;
            head = head->next;
            delete todelete;
            return head;
        }
        
        while(tm > 1){
            temp = temp->next;
            tm--;
        }
        
        ListNode* todelete = temp->next;
        temp->next = temp->next->next;
        todelete->next = NULL;
        delete todelete;
        
        return head;
    }
};