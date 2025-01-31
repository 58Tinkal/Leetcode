class DisjointSet {
    
public:
 vector<int> rank, parent, size;
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
  bool isValid(int r,int c,int m,int n){
    return r>=0 && c>=0 && r<m && c<n;
  }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n+1);
        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(isValid(nr,nc,n,n) && grid[nr][nc] == 1){
                         ds.unionBySize(i*n+j,nr*n+nc);
                    }
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) continue;
                 unordered_set<int>s;
                 for(int k=0;k<4;k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(isValid(nr,nc,n,n) && grid[nr][nc] == 1){
                        s.insert(ds.findUPar(nr*n+nc));
                    }
                 }
                 int cnt = 0;
                 for(auto it:s){
                   cnt += ds.size[it];
                 }
                 ans = max(ans,cnt+1);
            }
        }
        for(int i=0;i<n*n;i++){
            ans = max(ans, ds.size[ds.findUPar(i)]);
        }
        return ans;
    }
};