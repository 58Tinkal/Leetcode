class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int result = 0;
        int i, j, k;
        for (i = 0; i < (1 << n); i++) {
            vector<vector<int>> grid(n, vector<int>(n, 1e9));
            for (auto& it : roads) {
                int u = it[0], v = it[1], w = it[2];
                if (1 & (i >> u) && 1 & (i >> v)) {
                    grid[u][v] = min(grid[u][v], w);
                    grid[v][u] = min(grid[v][u], w);
                }
            }
            for (k = 0; k < n; k++)
                grid[k][k] = 0;
            for (int via = 0; via < n; via++) {
                for (k = 0; k < n; k++) {
                    for (j = 0; j < n; j++) {
                        grid[k][j] =
                            min(grid[k][j], grid[k][via] + grid[via][j]);
                    }
                }
            }
            bool ok = true;
            for (k = 0; k < n; k++) {
                for (j = 0; j < n; j++) {
                    if (k == j)
                        continue;
                    if (1 & (i >> k) && 1 & (i >> j)) {
                        if (grid[k][j] > maxDistance) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
            if (ok)
                result++;
        }
        return result;
    }
};