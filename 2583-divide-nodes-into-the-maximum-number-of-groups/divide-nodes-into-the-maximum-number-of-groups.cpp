class Solution {
public:
    bool check(vector<vector<int>>&adj,vector<int>&vis,int node){
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int nbr: adj[curr]){
                if(vis[nbr]==0){
                    vis[nbr] = (-1) * vis[curr];
                    q.push(nbr);
                }else if(vis[nbr]==vis[curr])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>&adj,int n){
        vector<int>vis(n+1);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(!check(adj,vis,i)){
                    return false;
                }
            }
        }
        return true;
    } 
    
    int dist_level(vector<vector<int>>&adj,int n,int node){
        queue<int>q;
        q.push(node);
        int level = 0;
        vector<bool>vis(n+1,false);
        vis[node] = true;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
               int curr = q.front();
                q.pop();
                for(auto it:adj[curr]){
                    if(!vis[it]){
                      q.push(it);
                      vis[it] = true;
                    }
                }
            }
            level++;
        }
        return level;
    }
    int count(vector<vector<int>>&adj,vector<int>&dist,vector<bool>&vis,int node){
        int res = INT_MIN;
        queue<int>q;
        q.push(node);
        vis[node] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res = max(res,dist[curr]);
            for(auto it:adj[curr]){
               if(!vis[it]){
                q.push(it);
                vis[it] = true;
               }
            }
        }
        return res;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
          if(!isBipartite(adj,n)){
            return -1;
          }
          vector<int>dist(n+1);
          for(int i=1;i<=n;i++){
            dist[i] = dist_level(adj,n,i);
          }
          vector<bool>vis(n+1,false);
          int ans = 0;
          for(int i=1;i<=n;i++){
            if(!vis[i]){
               ans += count(adj,dist,vis,i);
            }
          }
          return ans;
    }
};