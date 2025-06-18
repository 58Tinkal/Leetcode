class Solution {
public:
    double dfs(string &s, string &e, unordered_map<string, vector<pair<string, double>>>& adj, unordered_map<string, bool> &vis) {
        if (s == e) return 1.0;
        vis[s] = true;

        for (auto &it : adj[s]) {
            if (!vis[it.first]) {
                double result = dfs(it.first, e, adj, vis);
                if (result != -1.0)
                    return result * it.second;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            string u = equations[i][0], v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;
        for (auto &query : queries) {
            string src = query[0], dest = query[1];
            if (adj.find(src) == adj.end() || adj.find(dest) == adj.end()) {
                ans.push_back(-1.0);
            } else {
                unordered_map<string, bool> vis;
                ans.push_back(dfs(src, dest, adj, vis));
            }
        }
        return ans;
    }
};
