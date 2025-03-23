class Solution {
public:
    vector<vector<int>>ans;
    vector<bool>vis;
    int n;
    void dfs(int node, vector<vector<int>>& graph, vector<int>temp){
       
        if(node == n-1){
            ans.push_back(temp);
            return;
        }
        vis[node] = true;
        for(auto &it:graph[node]){
            if(vis[it] == false){
                temp.push_back(it);
                dfs(it,graph,temp);
                temp.pop_back();
            }
        }
        vis[node] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        n = graph.size();
        vis.resize(n,false);
        temp.push_back(0);
        dfs(0,graph,temp);
        return ans;
    }
};