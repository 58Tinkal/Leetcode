class Solution {
public:
    bool check(string& a, string& b) {
        int c = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                c++;
            }
        }
        if (c == 0 || c == 2)
            return true;
        return false;
    }
    void dfs(int idx, vector<string>& strs, vector<int>& vis) {
        vis[idx] = 1;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            if (check(strs[idx], strs[i])) {
                dfs(i, strs, vis);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            ans++;
            dfs(i, strs, vis);
        }
        return ans;
    }
};