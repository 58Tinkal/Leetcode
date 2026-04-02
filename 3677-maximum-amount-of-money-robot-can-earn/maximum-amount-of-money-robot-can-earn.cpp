class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    vector<vector<vector<bool>>> vis;
    int solve(vector<vector<int>>& coin, int r, int c, int ct) {

        if (r >= n || c >= m)
            return INT_MIN;

        if (r == n - 1 && c == m - 1) {
            if (coin[r][c] < 0 && ct > 0)
                return 0;
            return coin[r][c];
        }
        if (vis[r][c][ct]) {
            return dp[r][c][ct];
        }
        int ans = INT_MIN;
        if (ct > 0) {
            if (coin[r][c] >= 0) {
                ans = coin[r][c] +
                      max(solve(coin, r, c + 1, ct), solve(coin, r + 1, c, ct));
            } else {
                ans = max(max(solve(coin, r, c + 1, ct - 1),
                              solve(coin, r + 1, c, ct - 1)),
                          coin[r][c] + max(solve(coin, r, c + 1, ct),
                                           solve(coin, r + 1, c, ct)));
            }
        } else {
            ans = coin[r][c] +
                  max(solve(coin, r, c + 1, ct), solve(coin, r + 1, c, ct));
        }
        vis[r][c][ct] = true;
        return dp[r][c][ct] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(3, 0)));
        vis.assign(n, vector<vector<bool>>(m, vector<bool>(3, false)));
        return solve(coins, 0, 0, 2);
    }
};