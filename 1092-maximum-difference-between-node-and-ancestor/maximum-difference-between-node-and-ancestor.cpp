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
    int ans = -1e9;
    void fun(TreeNode* root, int maxi, int mini) {
        ans = max(ans, max(abs(root->val - maxi), abs(mini - root->val)));
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        if (root->left)
            fun(root->left, maxi, mini);
        if (root->right)
            fun(root->right, maxi, mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi = root->val;
        int mini = root->val;
        if (root->left)
            fun(root->left, maxi, mini);
        if (root->right)
            fun(root->right, maxi, mini);
        return ans;
    }
};