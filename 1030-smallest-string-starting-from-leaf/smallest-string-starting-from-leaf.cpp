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
    void solve(TreeNode* root, string& s, string& temp) {
        if (!root)
            return;
        temp += 'a' + root->val;
        if (!root->left && !root->right) {
            reverse(temp.begin(), temp.end());
            if (s == "" || s > temp) {
                s = temp;
            }
            reverse(temp.begin(), temp.end());
        }
        if (root->left)
            solve(root->left, s, temp);
        if (root->right)
            solve(root->right, s, temp);
        temp.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string s;
        string temp = "";
        solve(root, s, temp);
        return s;
    }
};