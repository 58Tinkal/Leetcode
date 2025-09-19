class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void union_by_size(int u, int v) {
        int p_u = find(u);
        int p_v = find(v);
        if (p_u == p_v) {
            return;
        }
        if (size[p_u] < size[p_v]) {
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        } else {
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
};

class Solution {
public:
    int fun(vector<vector<int>>& edges, int n, int mid) {
        DSU dsu(n);
        for (auto& it : edges) {
            if (it[0] <= mid)
                continue;
            dsu.union_by_size(it[1], it[2]);
        }
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            int u = dsu.find(i);
            s.insert(u);
        }
        int x = s.size();
        return x;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {

        if (edges.empty())
            return 0;

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            it[0] = wt;
            it[1] = u;
            it[2] = v;
        }
        sort(edges.begin(), edges.end());
        int l = 0;
        int h = edges.back()[0];
        int ans = -1;
        while (l <= h) {
            int mid = (l + h) / 2;
            int x = fun(edges, n, mid);
            if (x < k) {
                l = mid + 1;
            } else {
                ans = mid;
                h = mid - 1;
            }
        }
        return ans;
    }
};