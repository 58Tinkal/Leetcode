class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &subtreeCount) {
        subtreeCount[node] = 1; 
        for (int it : adj[node]) {
            if (it != parent) { 
                dfs(it, node, adj, subtreeCount);
                subtreeCount[node] += subtreeCount[it]; 
            }
        }
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() ;
        if (n == 0) return 0;

        vector<vector<int>> adj(n+1);
        for (auto it : roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> subtreeCount(n+1, 0);
        dfs(0, -1, adj, subtreeCount);

        for (int i = 0; i < n+1; ++i) {
            cout << subtreeCount[i] << ' ';
        }
     long long ans = 0;
         for(int i=1;i<n+1;i++){
            ans += ceil((double)subtreeCount[i]/seats);
         }
        return ans; 
    }
};
