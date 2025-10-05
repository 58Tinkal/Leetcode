class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        int n = adj.size();
        int FULL = (1 << n) - 1;
        queue<pair<int, pair<int, int>>> q; // mask, node, dist;
        vector<vector<int>> vis(n, vector<int>(1 << n, 0));

        for (int i = 0; i < n; i++) {
            q.push({(1 << i), {i, 0}});
            vis[i][(1 << i)];
        }
        int ans = INT_MAX;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int mask = it.first;
            int node = it.second.first;
            int dist = it.second.second;

            if (mask == FULL) {
                return dist;
            }

            for (auto it : adj[node]) {
                int newMask = mask | (1 << it);
                if (!vis[it][newMask]) {
                    vis[it][newMask] = 1;
                    q.push({newMask, {it, dist + 1}});
                }
            }
        }
        return -1;
    }
};