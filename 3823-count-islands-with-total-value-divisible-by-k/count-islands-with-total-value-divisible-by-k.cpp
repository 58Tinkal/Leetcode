class Solution {
private:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis,
             int& s, int k) {
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int n = grid.size();
        int m = grid[0].size();
        s = (s+grid[r][c])%k;
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (isValid(nr, nc, n, m) && !vis[nr][nc] && grid[nr][nc] > 0) {
                dfs(nr, nc, grid, vis, s, k);
            }
        }
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    int s = 0;
                    dfs(i, j, grid, vis, s, k);
                    if (s % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};