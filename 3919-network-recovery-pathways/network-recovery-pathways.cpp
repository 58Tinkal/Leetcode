class Solution {
public:
    int n;
    
    bool isValid(int W, vector<vector<pair<int, int>>>& adj, vector<bool>& online, long long k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        
        
        dist[0] = 0;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            
            if (node == n - 1 && cost <= k) return true;
            if (cost > dist[node]) continue;
            
            for (auto& [nbr, wt] : adj[node]) {
                if (!online[nbr] || wt < W) continue; // skip invalid edge

                if (cost + wt < dist[nbr]) {
                    dist[nbr] = cost + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return false;
    }
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        vector<vector<pair<int,int>>> adj(n);
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
                l = mid + 1; // try for higher min edge
            } else {
                r = mid - 1;
            }
        }
        
        return res;
    }
};
