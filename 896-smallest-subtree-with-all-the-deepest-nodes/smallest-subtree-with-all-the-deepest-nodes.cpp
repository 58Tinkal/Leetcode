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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == root || q == root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        } else {
            return root;
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* first = nullptr;
        TreeNode* last = nullptr;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            vector<TreeNode*> v;
            for (int i = 0; i < s; i++) {
                auto it = q.front();
                q.pop();
                v.push_back(it);
                if (it->left)
                    q.push(it->left);
                if (it->right)
                    q.push(it->right);
            }
            s = v.size();
            first = v[0];
            last = v[s - 1];
        }
        return lowestCommonAncestor(root, first, last);
    }
};