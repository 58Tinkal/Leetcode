class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
             queue<pair<int, int>>& q) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (isValid(nr, nc, n, m) && !vis[nr][nc] &&
                    grid[nr][nc] >= grid[r][c]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            q.push({i, 0});
            pacific[i][0] = 1;
        }
        for (int j = 1; j < m; j++) {
            q.push({0, j});
            pacific[0][j] = 1;
        }
        bfs(mat, pacific, q);

        while (!q.empty()) q.pop();
        for (int i = 0; i < n; i++) {
            q.push({i, m - 1});
            atlantic[i][m - 1] = 1;
        }
        for (int j = 0; j < m; j++) {
            q.push({n - 1, j});
            atlantic[n - 1][j] = 1;
        }
        bfs(mat, atlantic, q);

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
