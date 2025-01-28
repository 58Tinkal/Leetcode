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
    bool isValid(int r, int c, int m, int n){
        return r>=0 && c>=0 && r<m && c<n;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m*n + 1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int k=0;k<4;k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(isValid(nr,nc,m,n)  && grid[nr][nc] >0){
                        int node = i*n + j;
                        int newNode = nr*n + nc;
                        if(ds.findUPar(node) != ds.findUPar(newNode)){
                            ds.unionBySize(node,newNode);
                        }
                    }
                }
            }
        }

        int ans = INT_MIN;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n*m;i++){
           int leader = ds.findUPar(i);
           mp[leader].push_back(i);
        }
        for(auto [leader,vec]:mp){
            int res = 0;
            for(int i=0;i<vec.size();i++){
              int r = vec[i]/n;
              int c = vec[i]%n;
             res+=grid[r][c]; 
            }
            ans = max(ans,res);
        }
         return ans;
    }
};