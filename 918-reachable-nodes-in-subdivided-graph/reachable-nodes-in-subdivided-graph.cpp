class Solution {
public:
    vector<int> dijstra(vector<vector<pair<int, int>>>& adj, int n) {
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        dist[0] = 0;
        pq.push({0, 0}); // {distance, node}

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int node = it.second;

            if (d > dist[node])
                continue;

            for (auto& nbr : adj[node]) {
                int adjNode = nbr.first;
                int wt = nbr.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        if(edges.empty()){
            return 1;
        }
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2] + 1});
            adj[it[1]].push_back({it[0], it[2] + 1});
        }
        vector<int> dist = dijstra(adj, n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) {
                ans++;
            }
        }
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            int reachU = max(0, maxMoves - dist[u]);
            int reachV = max(0, maxMoves - dist[v]);
            ans += min(w, reachU + reachV);
        }
        return ans;
    }
};