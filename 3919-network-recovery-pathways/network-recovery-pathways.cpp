class Solution {
public:
    int n;

    bool isValid(int W, vector<vector<pair<int, int>>>& adj, vector<bool>& online, long long k) {
        vector<long long> dist(n, LLONG_MAX);
        vector<int> indegree(n, 0);
        vector<vector<pair<int, int>>> newAdj(n);

        // Filter the graph based on weight W and online status
        for (int u = 0; u < n; ++u) {
            if (!online[u] && u != 0 && u != n - 1) continue; // skip offline nodes (except 0 and n-1)

            for (auto& [v, wt] : adj[u]) {
                if ((!online[v] && v != n - 1) || wt < W) continue; // skip offline or invalid edges
                newAdj[u].emplace_back(v, wt);
                indegree[v]++;
            }
        }

        dist[0] = 0;
        queue<int> q;

        // Topo sort initialization
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0 && (online[i] || i == 0 || i == n - 1)) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& [v, wt] : newAdj[u]) {
                if (dist[u] != LLONG_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int minWt = INT_MAX, maxWt = INT_MIN;

        for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            minWt = min(minWt, e[2]);
            maxWt = max(maxWt, e[2]);
        }

        int l = minWt, r = maxWt, res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isValid(mid, adj, online, k)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
