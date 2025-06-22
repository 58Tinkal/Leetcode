class Solution {
    using ll = long long;
    const int LOG = 19;
    int n;
    vector<vector<pair<int, ll>>> adj;
    vector<vector<int>> up;
    vector<vector<ll>> distup;
    vector<int> depth;

void dfs(int x, int p) {
    up[x][0] = p;
    for(auto &[y, w] : adj[x]) {
        if(y == p) continue;
        depth[y] = depth[x] + 1;
        distup[y][0] = w;
        dfs(y, x);
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int k = 0; k < LOG; k++) {
        if(diff & (1<<k)) u = up[u][k];
    }
    if(u == v) return u;
    for(int k = LOG-1; k >= 0; k--) {
        if(up[u][k] != up[v][k]){
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

ll distt(int u, int v) {
    ll res = 0;
    int diff = depth[u] - depth[v];
    for(int k = 0; k < LOG; k++) {
        if(diff & (1<<k)) {
            res += distup[u][k];
            u = up[u][k];
        }
    }
    return res;
}
    
public:
    vector<int> findMedian(int N, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = N;
        adj.assign(n, {});
        for(auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        up.assign(n, vector<int>(LOG)); // up[i][j] => jth ansestor of ith node
        distup.assign(n, vector<ll>(LOG)); // distup[i][j] => distance btw ith node and its ith ansestor
        depth.assign(n, 0); // level of each node wrt root node

        dfs(0, 0);

        // bin lifting 
        // up[i][0] is filled as their imidate parent
        // distup[i][0] is filled by their edge connected to one level up
        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                int m = up[i][k-1];
                up[i][k] = up[m][k-1];
                distup[i][k] = distup[i][k-1] + distup[m][k-1];
            }
        }

        vector<int> ans;
        for(auto q : queries) { 
            int u = q[0], v = q[1];
            int l = lca(u, v);
            ll du = distt(u, l), dv = distt(v, l);
            ll half = (du+dv+1)/2;

            if(u == v) {
                ans.push_back(u); continue;
            }
            
            int node = u; ll rem = half;
            if(du < half) node = v;
            for(int k = LOG - 1; k >= 0; k--) {
                if(distup[node][k] < rem) {
                    rem -= distup[node][k];
                    node = up[node][k];
                }
            }

            if(du < half) {
                if(distt(up[node][0], l) + du < half) {
                    ans.push_back(node);
                    continue;
                }
            }
            
            ans.push_back(up[node][0]);
        }

        return ans;
    }
};