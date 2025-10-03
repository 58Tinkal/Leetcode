class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto it : invocations) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for (auto it : adj[node]) {
                if (vis[it] == 0)
                    q.push(it);
            }
        }
        while (!q.empty()) {
            q.pop();
        }
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0)
                q.push(i);
        }
        bool f = false;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (vis[node] == 1) {
                f = true;
            }
            a[node] = 1;
            for (auto it : adj[node]) {
                if (a[it] == 0) {
                    q.push(it);
                }
            }
        }
        vector<int> ans;
        if (f) {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (vis[i] == 0) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};