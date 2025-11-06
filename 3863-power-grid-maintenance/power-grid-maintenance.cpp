class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }
    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
class Solution {
public:
    vector<int> processQueries(int n, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<bool> online(n + 1, true);
        DSU dsu(n + 1);
        for (auto it : connections) {
            dsu.unite(it[0], it[1]);
        }
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
        for (int i = 1; i <= n; i++) {
            int p = dsu.find(i);
            m[p].push(i);
        }
        vector<int> ans;
        for (auto it : queries) {
            int type = it[0];
            int u = it[1];
            if (type == 2) {
                online[u] = false;
            } else {
                if (online[u]) {
                    ans.push_back(u);
                } else {
                    int root = dsu.find(u);
                    auto& heap = m[root];
                    while (!heap.empty() && !online[heap.top()]) {
                        heap.pop();
                    }
                    if (heap.empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(heap.top());
                    }
                }
            }
        }
        return ans;
    }
};