class Solution {
public:
    const int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;  

        for (int i = 2; i <= n; i++) {
            int start = max(1, i - forget + 1);
            int end = i - delay;
            for (int j = start; j <= end; j++) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};
