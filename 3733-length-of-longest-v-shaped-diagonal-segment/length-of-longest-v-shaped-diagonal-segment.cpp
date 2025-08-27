class Solution {
private:
    vector<pair<int, int>> direction = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int dp[501][501][4][2];

private:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

private:
    int solve(int r, int c, int d, bool canTurn, vector<vector<int>>& grid,
              int val) {
        int n = grid.size();
        int m = grid[0].size();
        int nr = r + direction[d].first;
        int nc = c + direction[d].second;

        if (dp[r][c][d][canTurn] != -1)
            return dp[r][c][d][canTurn];

        if (!isValid(nr, nc, n, m) || grid[nr][nc] != val) {
            return 0;
        }
        int result = 0;
        int keepMoving = 1 + solve(nr, nc, d, canTurn, grid, val == 2 ? 0 : 2);
        result = max(result, keepMoving);

        if (canTurn == true) {
            int turn =
                1 + solve(nr, nc, (d + 1) % 4, false, grid, val == 2 ? 0 : 2);
            result = max(result, turn);
        }
        return dp[r][c][d][canTurn] = result;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        ans = max(ans, 1 + solve(i, j, d, true, grid, 2));
                    }
                }
            }
        }
        return ans;
    }
};