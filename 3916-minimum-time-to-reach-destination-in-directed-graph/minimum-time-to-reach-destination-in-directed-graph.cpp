class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, pair<int, int>>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], {it[2], it[3]}});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0}); // current_time, node
        vector<int> time(n, INT_MAX);
        time[0] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int node = it.second;

            for (auto it : adj[node]) {
                int neg = it.first;
                int st = it.second.first;
                int ed = it.second.second;
                int temp = t;
                if (temp > ed)
                    continue;
                if (temp < st)
                    temp = st;
                temp++;
                if (temp < time[neg]) {
                    time[neg] = temp;
                    pq.push({temp, neg});
                }
            }
        }
        if (time[n - 1] == INT_MAX) {
            return -1;
        }
        return time[n - 1];
    }
};