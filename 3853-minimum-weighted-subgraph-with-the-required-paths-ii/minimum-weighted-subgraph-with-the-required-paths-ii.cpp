class Solution {
private:
    void binary_lifting(int node, int par, vector<vector<pair<int, int>>>& adj,
                        vector<vector<int>>& dp, vector<int>& level,
                        int l = 0) {
        // store immediate parent (if par == -1, keep -1)
        dp[node][0] = par;

        // precompute 2^i ancestors
        for (int i = 1; i <= 16; i++) {
            if (dp[node][i - 1] == -1) // ✅ fix: handle -1 parent
                dp[node][i] = -1;
            else
                dp[node][i] = dp[dp[node][i - 1]][i - 1];
        }

        level[node] = l;
        for (auto& it : adj[node]) {
            if (it.first == par)
                continue;
            binary_lifting(it.first, node, adj, dp, level, l + 1);
        }
    }

    int getKpar(int node, int k, vector<vector<int>>& dp) {
        for (int i = 16; i >= 0; i--) {
            if ((k >> i) & 1) {
                if (node == -1)
                    break; // ✅ fix: if node becomes -1
                node = dp[node][i];
            }
        }
        return node;
    }

    int lca(int u, int v, vector<vector<int>>& dp, vector<int>& level) {
        if (level[u] > level[v])
            swap(u, v);

        // bring v up to u’s level
        int k = level[v] - level[u];
        v = getKpar(v, k, dp);

        if (u == v)
            return u;

        for (int i = 16; i >= 0; i--) {
            // ✅ fix: check for -1 ancestors before indexing
            if (dp[u][i] != dp[v][i]) {
                u = dp[u][i];
                v = dp[v][i];
            }
        }

        return dp[u][0];
    }

    void dfsDist(int node, int par, vector<vector<pair<int, int>>>& adj,
                 vector<int>& dist, int l) {

        dist[node] = l;
        for (auto it : adj[node]) {
            if (it.first == par)
                continue;
            dfsDist(it.first, node, adj, dist, l + it.second);
        }
    }

    int findDist(int x, int y, vector<vector<int>>& dp, vector<int>& level,
                 vector<int>& dist) {
        int ans = 0;
        ans += dist[x] + dist[y];
        int ls = lca(x, y, dp, level);
        ans -= 2 * dist[ls];
        return ans;
    }

public:
    vector<int> minimumWeight(vector<vector<int>>& edges,
                              vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        vector<vector<pair<int, int>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> dist(n, 0);
        dfsDist(0, -1, adj, dist, 0);

        vector<int> level(n, 0);
     
        vector<vector<int>> dp(n, vector<int>(17, -1));
        binary_lifting(0, -1, adj, dp, level);

        vector<int> ans;
        for (auto it : queries) {
            int s1 = it[0];
            int s2 = it[1];
            int d = it[2];
            int res = (findDist(s1, s2, dp, level, dist) +
                       findDist(s1, d, dp, level, dist) +
                       findDist(d, s2, dp, level, dist)) /
                      2;
            ans.push_back(res);
        }
        return ans;
    }
};
