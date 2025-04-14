class Solution {
public:
    int dp[71][5000];
    int n, m;
    int fun(int idx, int sum, vector<vector<int>>& mat, int target) {
        if (idx >= n) {
            return abs(sum - target);
        }
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        int ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            ans = min(ans, fun(idx + 1, sum + mat[idx][i], mat, target));
        }
        return dp[idx][sum] = ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp, -1, sizeof(dp));
        n = mat.size();
        m = mat[0].size();
        return fun(0, 0, mat, target);
    }
};