class Solution {
private:
    vector<int> dijkstra(int V, vector<int> adj[], int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto v : adj[node]) {
                int w = 1;
                if (dis + w < distTo[v]) {
                    distTo[v] = dis + w;
                    pq.push({dis + w, v});
                }
            }
        }
        return distTo;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> adj[n];
        vector<int> ans;


        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        for (int i = 0; i < queries.size(); i++) {
            adj[queries[i][0]].push_back(queries[i][1]);

            vector<int> dist = dijkstra(n, adj, 0);

            if (dist[n - 1] == INT_MAX)
                ans.push_back(-1);
            else
                ans.push_back(dist[n - 1]);
        }
        return ans;
    }
};