class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &comp) {
        vis[node] = true;
        comp.push_back(node);
        for (auto &it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, comp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, vis, comp);

                bool isComplete = true;
                for (auto &it : comp) {
                    if (adj[it].size() != comp.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }
                if (isComplete) ans++;
            }
        }

        return ans;
    }
};
