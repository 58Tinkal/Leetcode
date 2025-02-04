class Solution {
public:
    void bfs(vector<vector<int>>&adj,vector<int>&ans,int node){
        queue<int> q;
        q.push(node);
        ans[node] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            vector<int> col(4, 0);
            for (auto it : adj[node]) {
                if (ans[it] > 0) {
                    int c = ans[it];
                    col[c-1] = 1;
                }
            }
            for (int i = 0; i < 4; i++) {
                if (col[i] == 0) {
                    ans[node] = i + 1;
                    break;
                }
            }
            for (auto it : adj[node]) {
                if (ans[it] == 0) {
                    q.push(it);
                }
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n + 1);
        vector<vector<int>> adj(n + 1);
        for (auto it : paths) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
       for(int i=1;i<=n;i++){
        if(ans[i]==0){
            bfs(adj,ans,i);
        }
       }
        vector<int>res;
        for(int i=1;i<=n;i++){
            res.push_back(ans[i]);
        }
        return res;
    }
};