class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
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

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
bool isValid(int r, int c, int n, int m){
    return r>=0 && r<n && c>=0 && c<m;
}
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        DisjointSet ds(n*n + 1);
        vector<int>edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                edges.push_back(i*n+j);
            }
        }
          sort(edges.begin(),edges.end(),[&](int a,int b){
                  return grid[a/n][a%n] < grid[b/n][b%n];
          });
          
          for(auto it:edges)  cout<<it<<' ';
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};
          for(auto it:edges){
                int r = it/n;
                int c = it%n;
                 for(int i=0;i<4;i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(isValid(nr,nc,n,n) && grid[nr][nc] <= grid[r][c]){
                         ds.unionBySize(it, nr*n + nc);
                    }
                 }

                 if(ds.findUPar(0) == ds.findUPar(n*n - 1)){
                    return grid[r][c];
                 }

          }
          return -1;
    }
};