class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;

        while(curr) {
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }

        curr = head;

        while(curr) {
            curr->next->random = (curr->random) ? curr->random->next : NULL;
            curr = curr->next->next;
        }

        Node* newHead = new Node(0);
        Node* copyCurr = newHead;
        curr = head;

        while(curr) {
            copyCurr->next = curr->next;
            curr->next = copyCurr->next->next;
            curr = curr->next;
            copyCurr = copyCurr->next;
        }
        return newHead->next;
    }
};