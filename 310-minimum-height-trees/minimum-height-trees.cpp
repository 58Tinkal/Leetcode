class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (edges.size() == 0) {
            for (int i = 0; i < n; i++)
                ans.push_back(i);

            return ans;
        }
        vector<int> in(n);
        vector<vector<int>> adj(n);
        for (auto& it : edges) {
            in[it[0]]++;
            in[it[1]]++;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            ans.clear();
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto it = q.front();
                ans.push_back(it);
                in[it]--;
                q.pop();
                for (auto itt : adj[it]) {
                    in[itt]--;
                    if (in[itt] == 1)
                        q.push(itt);
                }
            }
        }
        return ans;
    }
};