class Solution {
public:
    ListNode *reverse(ListNode *root){
        if(!root) return NULL;
        ListNode *pre=NULL;
        ListNode *temp;
        while(root){
            temp=root->next;
            root->next=pre;
            pre=root;
            root=temp;
        }
        return pre;
        
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode *slow=head;
        ListNode *fast=head;
    
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);

        slow =slow->next;

        while(slow){
            if(head->val !=slow->val) return false;
            head=head->next;
            slow=slow->next;
        }
        
        return true;
        
    }
};