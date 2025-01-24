class Solution {
public:
    int dfs(int node,int &ans,vector<vector<pair<int,int>>>&adj,vector<int>&vis){
        vis[node] = 1;
             for(auto it:adj[node]){
                ans = min(ans,it.second);
                if(vis[it.first] == 0){
                    vis[it.first] = 1;
                    dfs(it.first,ans,adj,vis);
                }
            }
            return ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // queue<int>q;
        // q.push(1);
         vector<int>vis(n+1,0);
        // vis[1] = 1;
        int ans = INT_MAX;
        // while(!q.empty()){
        //     auto node = q.front();
        //     q.pop();
        //     for(auto it:adj[node]){
        //         ans = min(ans,it.second);
        //         if(vis[it.first] == 0){
        //             vis[it.first] = 1;
        //             q.push(it.first);
        //         }
        //     }
        // }/
        dfs(1,ans,adj,vis);
        return ans;
    }
};