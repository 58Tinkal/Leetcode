class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<int>& flowerType, int startNode) {
        queue<int> q;
        q.push(startNode);
        flowerType[startNode] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            bool usedColors[5] = {};

            for (int neighbor : adj[node]) {
                if (flowerType[neighbor] > 0) {
                    usedColors[flowerType[neighbor]] = true;
                }
            }

            for (int i = 1; i <= 4; i++) {
                if (!usedColors[i]) {
                    flowerType[node] = i;
                    break;
                }
            }

            for (int neighbor : adj[node]) {
                if (flowerType[neighbor] == 0) {
                    flowerType[neighbor] = -1; 
                    q.push(neighbor);
                }
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        for (const auto& path : paths) {
            adj[path[0]].emplace_back(path[1]);
            adj[path[1]].emplace_back(path[0]);
        }

        vector<int> flowerType(n + 1, 0); 

        for (int i = 1; i <= n; i++) {
            if (flowerType[i] == 0) {
                bfs(adj, flowerType, i);
            }
        }

        return vector<int>(flowerType.begin() + 1, flowerType.end());
    }
};
