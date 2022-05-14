class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        Node* head = root;

        while(head) {
            Node* dummyNode = new Node(0);
            Node* tmp = dummyNode;

            while(head) {
                if(head->left) {
                    tmp->next = head->left;
                    tmp = tmp->next;
                }
                if(head->right) {
                    tmp->next = head->right;
                    tmp = tmp->next;
                }
                head = head->next;
            }

            head = dummyNode->next;
        }

        return root;
    }
};
