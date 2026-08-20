class Codec {
public:
    // Serialize the tree into a string
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "#";

        return to_string(root->val) + "," +
               serialize(root->left) + "," +
               serialize(root->right);
    }

    // Deserialize the string back into a tree
    TreeNode* deserialize(string data) {
        int index = 0;
        return build(data, index);
    }

private:
    TreeNode* build(const string& data, int& index) {
        // Find the next comma
        int comma = data.find(',', index);

        string token;

        if (comma == string::npos) {
            token = data.substr(index);
            index = data.size();
        } else {
            token = data.substr(index, comma - index);
            index = comma + 1;
        }

        // Null node
        if (token == "#")
            return nullptr;

        // Create node
        TreeNode* node = new TreeNode(stoi(token));

        // Preorder: root -> left -> right
        node->left = build(data, index);
        node->right = build(data, index);

        return node;
    }
};
