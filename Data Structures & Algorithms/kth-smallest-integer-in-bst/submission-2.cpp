
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        dfs(root, arr);
        sort(arr.begin(), arr.end());
        return arr[k - 1];
    }

    void dfs(TreeNode* node, vector<int>& arr) {
        if (!node) return;
        arr.push_back(node->val);
        dfs(node->left, arr);
        dfs(node->right, arr);
    }
};