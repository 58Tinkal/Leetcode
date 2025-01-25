static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

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

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
       int n = nums.size();
       DisjointSet ds(n);
       vector<pair<int,int>>a;
       for(int i=0;i<n;i++){
        a.push_back({nums[i],i});
       }
       sort(a.begin(),a.end());
       for(int i=0;i<n-1;i++){
        if(a[i+1].first - a[i].first <= limit) ds.unionBySize(a[i].second,a[i+1].second);
       }
       unordered_map<int,set<int>>m;
       for(int i=0;i<n;i++){
        int ult = ds.findUPar(i);
        m[ult].insert(i); 
       }
       for(auto [ult,idx]:m){
          vector<int>val;
          for(auto it:idx){
            val.push_back(nums[it]);
          }
          sort(val.begin(),val.end());
          int x=0;
          for(auto it:idx){
            nums[it] = val[x];
            x++;
          }
       }
       return nums;
    }
};