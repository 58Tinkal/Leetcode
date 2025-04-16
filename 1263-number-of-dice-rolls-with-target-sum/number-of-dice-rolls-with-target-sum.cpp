class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int n;
    int t;
    int k;
    int solve(int idx, int s) {
        if (idx == 0 && s == 0)
            return 1;
        if (idx == 0 || s == 0)
            return 0;
        if (dp[idx][s] != -1)
            return dp[idx][s];
        int ways = 0;
        for (int i = 1; i <= k; i++) {
            if (s - i >= 0)
                ways = (ways + solve(idx - 1, s - i)) % mod;
        }
        dp[idx][s] = ways % mod;
        return dp[idx][s];
    }
    int numRollsToTarget(int n, int k, int target) {
        this->n = n;
        t = target;
        this->k = k;
        dp = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        return solve(n, target);
    }
};