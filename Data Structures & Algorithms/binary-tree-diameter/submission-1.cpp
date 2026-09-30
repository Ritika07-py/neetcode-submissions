

class Solution {
public:
    int dOfBT(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = maxHeight(root->left);
        int rightHeight = maxHeight(root->right);
        int diameter = leftHeight + rightHeight;
        int sub = max(dOfBT(root->left),
                      dOfBT(root->right));
        return max(diameter, sub);
    }

    int maxHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }
};