class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            auto node = it.second;
            auto wt = it.first;
            for (auto itt : adj[node]) {
                int nextNode = itt.first;
                int edgeWeight = itt.second;
                if (dist[node] + edgeWeight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + edgeWeight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i < n + 1; i++) {
            if(dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};