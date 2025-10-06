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
    int solve(TreeNode* node) {

        if (node == NULL) {
            return 1;
        }

        int l = solve(node->left);
        int r = solve(node->right);

        if (l == 0 || r == 0) {
            count++;
            return 2; // camera
        }
        if (l == 2 || r == 2) {
            return 1; // beign watched but no camera
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if (solve(root) == 0) {
            count++;
        }
        
        return count;
    }
};