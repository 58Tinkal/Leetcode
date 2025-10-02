class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findPar(parent[u]);
    }

    void union_by_size(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> cand1, cand2;
        int skip = -1;

        for (int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                cand1 = {parent[v], v};
                cand2 = {u, v};
                skip = i;
            }
        }

        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            if (i == skip)
                continue;
            int u = edges[i][0], v = edges[i][1];
            int pu = dsu.findPar(u), pv = dsu.findPar(v);
            if (pu == pv) {
                if (!cand1.empty())
                    return cand1;
                return edges[i];
            }
            dsu.union_by_size(u, v);
        }

        return cand2;
    }
};
