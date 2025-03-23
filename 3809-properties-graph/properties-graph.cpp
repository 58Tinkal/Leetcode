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
    int intersectCount(const unordered_set<int>& a, const unordered_set<int>& b) {
        int c = 0;
        if(a.size() > b.size()) {
            return intersectCount(b, a);
        }
        
        for (auto  num : a) {
            if (b.find(num) != b.end())
                c++;
        }
        return c;
    }
    int numberOfComponents(vector<vector<int>>& p, int k) {
        int n = p.size();
        DisjointSet ds(n);

        vector<unordered_set<int>> sets(n);
        for (int i = 0; i < n; i++) {
            for (int num : p[i]) {
                sets[i].insert(num);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(i==j) continue;
               int x = intersectCount(sets[i],sets[j]);
               if(x>=k){
                  ds.unionBySize(i,j);
               }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i) == i){
                ans++;
            }
        }
        return ans;
    }
};