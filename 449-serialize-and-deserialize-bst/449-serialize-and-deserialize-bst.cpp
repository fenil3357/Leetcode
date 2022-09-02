class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encode(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;

        TreeNode* root = nullptr;

        while(getline(ss, item, '-')) 
            root = insert(root, stoi(item));

        return root;
    }

private:

    string encode(TreeNode* root) {
        if(!root) return "";
        return to_string(root->val) + "-" + encode(root->left) + encode(root->right);
    }

    TreeNode* insert(TreeNode* root, int val) {
        if(!root) {
            TreeNode* head = new TreeNode(val);
            return head;
        }

        if(val <= root->val) 
            root->left = insert(root->left, val);

        else 
            root->right = insert(root->right, val);

        return root;
    }
};