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
class FindElements {
public:
    TreeNode* recoveredRoot;
    unordered_set<int>s;
    FindElements(TreeNode* root) {
        recoveredRoot = root;
        if (root) {
            root->val = 0;
            solve(root);
        }
    }

    void solve(TreeNode* root) {
        if (!root)
            return;
            s.insert(root->val);
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            solve(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            solve(root->right);
        }
    }
    bool findE(TreeNode* root, int t) {
        if (root->val == t)
            return true;
        if (root == NULL)
            return false;
        bool f1 = false;
        bool f2 = false;
        if (root->left)
            f1 = findE(root->left, t);
        if (root->right)
            f2 = findE(root->right, t);
        return f1 || f2;
    }
    bool find(int target) {
        // if (findE(recoveredRoot, target))
        //     return true;
        // return false;
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */