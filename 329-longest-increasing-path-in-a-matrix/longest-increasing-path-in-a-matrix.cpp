class Solution {
public:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {-1, 1, 0, 0};

    int solve(int r, int c, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {
        if (dp[r][c] != -1)
            return dp[r][c];

        int n = matrix.size(), m = matrix[0].size();
        int maxLength = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                matrix[nr][nc] > matrix[r][c]) {
                maxLength = max(maxLength, 1 + solve(nr, nc, matrix, dp));
            }
        }
        return dp[r][c] = maxLength;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, matrix, dp));
            }
        }
        return ans;
    }
};
