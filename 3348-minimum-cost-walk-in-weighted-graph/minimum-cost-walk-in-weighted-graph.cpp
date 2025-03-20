class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, int id, int node,
             vector<int>& vis) {
        vis[node] = id;
        for (auto& it : adj[node]) {
            if (vis[it.first] == -1) { 
                dfs(adj, id, it.first, vis);
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        vector<int> vis(n, -1);
        vector<vector<pair<int, int>>> adjList(n);

        for (auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                dfs(adjList, i, i, vis);
            }
        }
        vector<unsigned int> cost(n, -1);
        for (auto& it : edges) {
            int u = it[0];
            int root = vis[u];
            cost[root] &= it[2];
        }
        vector<int> ans;
        for (auto& it : query) {
            if (vis[it[0]] != vis[it[1]]) {
                ans.push_back(-1);

            } else {
                ans.push_back(cost[vis[it[0]]]);
            }
        }
        return ans;
    }
};
