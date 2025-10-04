class DSU {
    vector<int> parent;
    vector<int>size;

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
        if(pu == pv) return;
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
    vector<bool> areConnected(int n, int threshold,
                              vector<vector<int>>& queries) {
        DSU dsu(n);
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = 2 * i; j <= n; j += i) {
                dsu.unite(i, j);
            }
        }
        vector<bool> ans;
        for (auto it : queries) {
            if (dsu.find(it[0]) == dsu.find(it[1])) {
                ans.push_back(true);
            } else
                ans.push_back(false);
        }
        return ans;
    }
};