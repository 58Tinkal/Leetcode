class Solution {
public:
    using ll = long long;

    // DFS to count component size & detect a cycle
    bool dfs(int u, int parent,
             const vector<vector<int>>& G,
             vector<bool>& visited,
             int& compSize)
    {
        visited[u] = true;
        compSize++;
        for (int v : G[u]) {
            if (!visited[v]) {
                if (dfs(v, u, G, visited, compSize))
                    return true;
            }
            else if (v != parent) {
                // found a back‐edge → cycle
                return true;
            }
        }
        return false;
    }

    ll maxScore(int n, vector<vector<int>>& edges) {
        // 1) Build adjacency
        vector<vector<int>> G(n);
        for (auto &e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }

        // 2) Classify components
        vector<bool> visited(n, false);
        vector<int> acyclic, cyclic;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int sz = 0;
                bool isCycle = dfs(i, -1, G, visited, sz);
                (isCycle ? cyclic : acyclic).push_back(sz);
            }
        }

        // 3) Sort increasing: acyclic first, then cyclic
        sort(acyclic.begin(), acyclic.end());
        sort(cyclic.begin(), cyclic.end());

        ll total = 0;
        int nextLabel = 1;

        // Helper to assign one component of size sz,
        // compute its contribution; 'makeCycle' toggles wrap-around.
        auto processComp = [&](int sz, bool makeCycle) {
            vector<ll> a(sz);
            // assign labels nextLabel .. nextLabel+sz-1 symmetrically
            int low = nextLabel, high = nextLabel + sz - 1;
            for (int i = 0; i < sz/2; i++) {
                a[i]          = low++;
                a[sz-1-i]    = low++;
            }
            if (sz % 2) {
                a[sz/2] = low++;
            }
            // accumulate edge-products
            for (int i = 1; i < sz; i++) {
                total += a[i] * a[i-1];
            }
            if (makeCycle && sz > 1) {
                total += a[0] * a[sz-1];
            }
            nextLabel += sz;
        };

        // 4) Process all acyclic, then all cyclic
        for (int sz : acyclic)
            processComp(sz, /*makeCycle=*/false);
        for (int sz : cyclic)
            processComp(sz, /*makeCycle=*/true);

        return total;
    }
};
