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
    int len(ListNode* &head) {
        int cnt = 0;
        ListNode* temp = head;
        
        while(temp) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        
        int n = len(head);
        
        k = k%n;
        
        while(k--) {
            ListNode* temp = head;
            
            while(temp->next->next) {
                temp = temp->next;
            }
            
            ListNode* newHead = temp->next;
            temp->next = NULL;
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};
