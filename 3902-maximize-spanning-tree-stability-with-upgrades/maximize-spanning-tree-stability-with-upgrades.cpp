class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
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
    int k, m;

    bool solve(vector<vector<int>>& edges, int mid) {
        DSU dsu(m);
        int upgrades = k;

        for (auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < mid)
                    return false;
                int pu = dsu.findPar(e[0]), pv = dsu.findPar(e[1]);
                if (pu == pv)
                    return false;
                dsu.union_by_size(pu, pv);
            }
        }

        for (auto& e : edges) {
            if (e[3] == 1)
                continue;
            if (e[2] >= mid) {
                int pu = dsu.findPar(e[0]), pv = dsu.findPar(e[1]);
                if (pu != pv)
                    dsu.union_by_size(pu, pv);
            }
        }

        vector<char> seen(m, 0);
        int comps = 0;
        for (int i = 0; i < m; ++i) {
            int p = dsu.findPar(i);
            if (!seen[p]) {
                seen[p] = 1;
                ++comps;
            }
        }
        if (comps == 1)
            return true;

        for (auto& e : edges) {
            if (e[3] == 1)
                continue;
            if (e[2] < mid && (long long)e[2] * 2 >= mid) {
                int pu = dsu.findPar(e[0]), pv = dsu.findPar(e[1]);
                if (pu != pv && upgrades > 0) {
                    dsu.union_by_size(pu, pv);
                    --upgrades;
                    --comps;
                    if (comps == 1)
                        return true;
                }
            }
        }

        return false;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        this->k = k;
        this->m = n;

        if (n == 1)
            return 0;
        if (edges.empty())
            return -1;

        int maxStrength = 0;
        for (auto& e : edges)
            maxStrength = max(maxStrength, e[2]);

        int l = 0, h = 2 * maxStrength, ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (solve(edges, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
