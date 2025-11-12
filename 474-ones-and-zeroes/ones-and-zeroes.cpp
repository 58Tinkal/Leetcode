class Solution {
public:
    int ans = INT_MIN;
    int dp[605][105][105];
    int solve(int idx, vector<string>& strs, int m, int n) {
        if (idx >= strs.size()) {
            if (m >= 0 && n >= 0) {
                return 1;
            } else
                return 0;
        }
        if (dp[idx][m][n] != -1) {
            return dp[idx][m][n];
        }
        int z = 0;
        int o = 0;
        for (auto it : strs[idx]) {
            if (it == '0')
                z++;
            else
                o++;
        }

        int skip = solve(idx + 1, strs, m, n);
        int notSkip = INT_MIN;
        if (m - z >= 0 && n - o >= 0)
            notSkip = 1 + solve(idx + 1, strs, m - z, n - o);

        return dp[idx][m][n] = max(skip, notSkip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, strs, m, n) - 1;
    }
};