class Solution {
public:
    //  idx * tight * prev;
    int dp[32][2][2];
    int solve(int idx, bool tight, int prev, int& n) {
        if (idx == 32)
            return 1;

        if (dp[idx][tight][prev] != -1)
            return dp[idx][tight][prev];

        int ans = 0;
        int limit = tight ? (n >> (31 - idx)) & 1 : 1;

        for (int i = 0; i <= limit; i++) {
            int newTight = tight & (i == limit);
            // for not consitive ones
            if ((i & prev) == 0) {
                ans += solve(idx + 1, newTight, i, n);
            }
        }
        return dp[idx][tight][prev] = ans;
    }
    int findIntegers(int n) {

        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0, n);
    }
};