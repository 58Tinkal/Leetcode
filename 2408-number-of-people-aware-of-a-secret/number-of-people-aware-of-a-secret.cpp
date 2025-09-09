class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int days, int delay, int forget, vector<int>& dp) {
        if (days == 1) {
            return 1;
        }

        if (dp[days] != -1) {
            return dp[days];
        }

        int ans = 0;

        for (int i = days - forget + 1; i <= days - delay; i++) {
            if (i > 0) {
                ans = (ans + solve(i, delay, forget, dp)) % MOD;;
            }
        }
        return dp[days] = ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, -1);
        int ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i > 0) {
                ans = (ans + solve(i, delay, forget, dp)) % MOD;
            }
        }
        return ans;
    }
};