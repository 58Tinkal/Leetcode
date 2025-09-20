class Solution {
private:
    vector<int> dijkstra(int node, vector<vector<pair<int, int>>>& adj, int n) {
        vector<int> dist(n, 1e9);
        dist[node] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, node});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int u = top.second;
            int wt = top.first;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (wt + w < dist[v]) {
                    dist[v] = wt + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> start = dijkstra(0, adj, n);
        vector<int> end = dijkstra(n - 1, adj, n);

        int d = start[n - 1];
        int x = edges.size();
        vector<bool> ans(x, false);

        for (int i = 0; i < x; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if (start[u] + wt + end[v] == d || start[v] + wt + end[u] == d) {
                ans[i] = true;
            }
        }
        return ans;
    }
};