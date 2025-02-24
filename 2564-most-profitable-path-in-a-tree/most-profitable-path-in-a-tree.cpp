class Solution {
public:
    int ans = 0;
    int score = INT_MIN;
    void findDistAndPar(int curr, int par, int d, vector<int>& parent,
                        vector<int>& dist, vector<vector<int>>& adj) {
        parent[curr] = par;
        dist[curr] = d;
        for (auto it : adj[curr]) {
            if (it != par) {
                findDistAndPar(it, curr, d + 1, parent, dist, adj);
            }
        }
    }
    void findScore(vector<vector<int>>& adj, int curr, vector<int>& amount,
                   vector<int>& vis) {
        if (vis[curr] == 1)
            return;
        vis[curr] = 1;
        ans += amount[curr];
        int t = 0;
        for (auto it : adj[curr]) {
            if (vis[it] != 1) {
                t++;
                findScore(adj, it, amount, vis);
            }
        }
        if (t == 0)
            score = max(ans, score);
        ans -= amount[curr];
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> parent(n, -1), dist(n, -1);
        findDistAndPar(0, 0, 0, parent, dist, adj);

        // Debugging outputs
        for (int i = 0; i < n; i++)
            cout << "Dist[" << i << "] = " << dist[i] << ' ';
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << "Parent[" << i << "] = " << parent[i] << ' ';
        cout << endl;

        int dBob = 0;
        int curr = bob;
        while (curr != 0) {
            if (dist[curr] > dBob) {
                amount[curr] = 0;
            } else if (dist[curr] == dBob) {
                amount[curr] = amount[curr] / 2;
            }
            dBob++;
            curr = parent[curr];
        }
        // Debuing output
        for (int i = 0; i < n; i++) {
            cout << amount[i] << ' ';
        }
        cout << endl;
        vector<int> vis(n, 0);
        findScore(adj, 0, amount, vis);

        return score;
    }
};
