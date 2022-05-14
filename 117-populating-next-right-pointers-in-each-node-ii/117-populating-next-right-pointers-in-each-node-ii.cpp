class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        queue<Node*> q;
        q.push(root);


        while(!q.empty()) {
            Node* dummyNode = new Node(0);
            int n = q.size();

            while(n-- > 0) {
                Node* curr = q.front();
                q.pop();

                dummyNode->next = curr;
                dummyNode = dummyNode->next;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);           
            }
        }

        return root;
    }
};