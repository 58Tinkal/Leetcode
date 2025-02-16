class Solution {
public:
    bool solve(int idx, int n, vector<int>& ans, vector<bool>& vis) {
        if (idx >= ans.size())
            return true;
        if (ans[idx] != -1)
            return solve(idx + 1, n, ans, vis);

        for (int i = n; i >= 1; i--) {
            if (vis[i])
                continue;
            vis[i] = true;
            ans[idx] = i;

            if (i == 1) {
                if (solve(idx + 1, n, ans, vis))
                    return true;
            } else if (idx + i < ans.size() && ans[idx + i] == -1) {
                ans[idx + i] = i;
                if (solve(idx + 1, n, ans, vis))
                    return true;
                ans[idx + i] = -1;
            }

            ans[idx] = -1;
            vis[i] = false;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, -1);
        vector<bool> vis(n + 1, false);
        solve(0, n, ans, vis);
        return ans;
    }
};
