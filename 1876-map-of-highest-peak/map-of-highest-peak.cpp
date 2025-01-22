class Solution {
public:
    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> height(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        int level = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        while (!q.empty()) {
            int s = q.size();
            for (int j = 0; j < s; j++) {
                auto it = q.front();
                q.pop();
                int r = it.first, c = it.second;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (isValid(nr, nc, m, n) && !vis[nr][nc]) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                        height[nr][nc] = 1 + level;
                    }
                }
            }
            level++;
        }
        return height;
    }
};