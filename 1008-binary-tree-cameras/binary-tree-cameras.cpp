/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    void solve(TreeNode* node, unordered_set<TreeNode*>& s, TreeNode* parent) {
        if (node == nullptr)
            return;
        solve(node->left, s, node);
        solve(node->right, s, node);
        if (parent == nullptr && s.find(node) == s.end() ||
            s.find(node->left) == s.end() || s.find(node->right) == s.end()) {
            count++;
            s.insert(node);
            s.insert(parent);
            s.insert(node->left);
            s.insert(node->right);
        }
    }
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*> s;
        s.insert(nullptr);
        solve(root, s, nullptr);
        return count;
    }
};