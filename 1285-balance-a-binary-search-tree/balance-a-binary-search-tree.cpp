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
    void fun(TreeNode* root, vector<int>& a) {
        if (root == NULL)
            return;
        if (root->left)
            fun(root->left, a);
        a.push_back(root->val);
        if (root->right)
            fun(root->right, a);
    }
    TreeNode* solve(int l, int r, vector<int>& a) {
        if (l > r)
            return NULL;

        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = solve(l, mid - 1, a);
        root->right = solve(mid + 1, r, a);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> a;
        fun(root, a);
        return solve(0, a.size() - 1, a);
    }
};