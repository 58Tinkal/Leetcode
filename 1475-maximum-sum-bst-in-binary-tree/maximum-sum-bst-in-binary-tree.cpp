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
    int ans = 0;
    // returns {min_val, max_val, sum}
    vector<int> solve(TreeNode* root) {
        if (root == NULL) {
            return {INT_MAX, INT_MIN, 0};
        }

        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);

        if (root->val > l[1] && root->val < r[0]) {
            int sum = root->val + l[2] + r[2];
            ans = max(ans, sum);
            return {min(root->val, l[0]), max(root->val, r[1]), sum};
        }

        return {INT_MIN, INT_MAX, max(l[2], r[2])}; // not BST
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};
