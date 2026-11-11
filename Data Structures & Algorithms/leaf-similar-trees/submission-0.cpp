/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
auto leaves=[](TreeNode* root){vector<int> out;vector<TreeNode*> stack{root};while(!stack.empty()){auto node=stack.back();stack.pop_back();if(!node->left&&!node->right)out.push_back(node->val);if(node->right)stack.push_back(node->right);if(node->left)stack.push_back(node->left);}return out;};return leaves(root1)==leaves(root2);
}
};
