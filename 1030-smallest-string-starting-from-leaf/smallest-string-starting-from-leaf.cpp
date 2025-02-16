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
    string s;
    void solve(TreeNode* root, string str) {

        if (!root)
            return;
        str = char(root->val + 'a') + str;

        if (root->left == NULL && root->right == NULL) {
            if (s == "" || s > str) {
                s = str;
            }
        }

        if (root->left)
            solve(root->left, str);
        if (root->right)
            solve(root->right, str);
    }

    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        return s;
    }
};