class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        unordered_set<string>s;
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            s.insert(to_string(it[0]) + "#" + to_string(it[1]));
        }
        queue<int>q;
        q.push(0);
        int c = 0;
        vector<int>vis(n,0);
        vis[0] = 1;
        while(!q.empty()){
           int node = q.front();
           q.pop();
           for(auto it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
                if(s.count(to_string(node) + "#" + to_string(it))) c++;
            }
           }
        }
        return c;
    }
};