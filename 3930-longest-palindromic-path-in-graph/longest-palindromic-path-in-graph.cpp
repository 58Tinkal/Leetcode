class Solution {
public:
    int dp[15][15][1 << 15];
    int solve(int node1, int node2, int mask, vector<vector<int>>& adj,
              string& label) {
        int ans = 0;
        if (dp[node1][node2][mask] != -1) {
            return dp[node1][node2][mask];
        }
        for (auto it1 : adj[node1]) {
            if ((mask >> it1) & 1)
                continue;
            for (auto it2 : adj[node2]) {
                if ((mask >> it2) & 1 || it1 == it2)
                    continue;
                if (label[it1] == label[it2]) {
                    ans = max(ans, 2 + solve(it1, it2,
                                             mask | (1 << it1) | (1 << it2),
                                             adj, label));
                }
            }
        }
        return dp[node1][node2][mask] = ans;
    }
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        memset(dp, -1, sizeof(dp));
        int ans = 1;
        for (int i = 0; i < n; i++) {
            // odd length;
            ans = max(ans, 1 + solve(i, i, 0 | (1 << i), adj, label));
            // even length
            for (auto it : adj[i]) {
                if (label[it] == label[i]) {
                    ans = max(ans, 2 + solve(i, it, 0 | (1 << i) | (1 << it),
                                             adj, label));
                }
            }
        }
        return ans;
    }
};