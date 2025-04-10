class Solution {
public:
    int mod = 1e9 + 7;
    int m, n, k;
    vector<vector<vector<int>>> dp;

    int dfs(int i, int j, int rem, vector<vector<int>>& grid) {
        if (i >= m || j >= n) return 0;
        
        rem = (rem + grid[i][j]) % k;

        // Base case: if we're at the bottom-right corner
        if (i == m - 1 && j == n - 1) {
            return rem == 0 ? 1 : 0;
        }

        if (dp[i][j][rem] != -1) return dp[i][j][rem];

        int right = dfs(i, j + 1, rem, grid);
        int down = dfs(i + 1, j, rem, grid);

        return dp[i][j][rem] = (right + down) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        this->k = k;
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return dfs(0, 0, 0, grid);
    }
};
