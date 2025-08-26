class Solution {
public:
    void dfs(vector<vector<int>>& vis, vector<vector<int>>& heights, int r,
             int c) {
        vis[r][c] = 1;
        int n = heights.size(), m = heights[0].size();
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(vis, heights, nr, nc);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> visP(n, vector<int>(m, 0));
        vector<vector<int>> visA(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            if (!visP[0][i])
                dfs(visP, heights, 0, i);
        }
        for (int i = 0; i < n; i++) {
            if (!visP[i][0])
                dfs(visP, heights, i, 0);
        }
        for (int i = 0; i < m; i++) {
            if (!visA[n - 1][i])
                dfs(visA, heights, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            if (!visA[i][m - 1])
                dfs(visA, heights, i, m - 1);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visP[i][j] && visA[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};