#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }

    vector<int> hitBricks(vector<vector<int>>& grid,
                          vector<vector<int>>& hits) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        vector<vector<int>> g = grid;

        for (auto &h : hits) {
            int r = h[0], c = h[1];
            if (g[r][c] == 1) {
                g[r][c] = 0;
            }
        }

        int totalNodes = n * m;
        DSU dsu(totalNodes);
        int roof = totalNodes; 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 0) continue;
                int id = i * m + j;
                if (i == 0) {
                    dsu.unionBySize(id, roof);
                }
                for (int k = 0; k < 4; ++k) {
                    int nr = i + dirs[k][0];
                    int nc = j + dirs[k][1];
                    if (!isValid(nr, nc, n, m)) continue;
                    if (g[nr][nc] == 1) {
                        int nid = nr * m + nc;
                        dsu.unionBySize(id, nid);
                    }
                }
            }
        }

        int H = hits.size();
        vector<int> ans(H, 0);

        for (int k = H - 1; k >= 0; --k) {
            int r = hits[k][0], c = hits[k][1];

            if (grid[r][c] == 0) {
                ans[k] = 0;
                continue;
            }

            int before = dsu.size[dsu.findUPar(roof)];

            g[r][c] = 1;
            int id = r * m + c;

            if (r == 0) {
                dsu.unionBySize(id, roof);
            }

            for (int t = 0; t < 4; ++t) {
                int nr = r + dirs[t][0];
                int nc = c + dirs[t][1];
                if (!isValid(nr, nc, n, m)) continue;
                if (g[nr][nc] == 1) {
                    int nid = nr * m + nc;
                    dsu.unionBySize(id, nid);
                }
            }

            int after = dsu.size[dsu.findUPar(roof)];

            int fallen = after - before - 1;
            if (fallen < 0) fallen = 0;
            ans[k] = fallen;
        }

        return ans;
    }
};
