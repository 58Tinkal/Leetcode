#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<vector<pair<long long, long long>>> adj(n);
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dist(n, LONG_MAX), ways(n, 0);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>>
            pq; // node,time
        pq.push({0, 0});
        ways[0] = 1;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            for (auto& itt : adj[it.second]) {
                ll time = itt.second;
                ll adjNode = itt.first;
                if (it.first + time < dist[adjNode]) {
                    dist[adjNode] = it.first + time;
                    ways[adjNode] = ways[it.second];
                    pq.push({it.first + time, adjNode});
                } else if (it.first + time == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[it.second]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};