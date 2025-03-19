class Solution {
public:
    // digit * tight * repaeat * bitmask(max => 111111111)
    int dp[10][2][2][1024];
    int fun(int idx, bool tight, bool repeat, int mask, string& s) {
        if (idx >= s.size()) {
            if ((repeat && mask))
                return 1;
            return 0;
        }
        if (dp[idx][tight][repeat][mask] != -1)
            return dp[idx][tight][repeat][mask];

        int ans = 0;
        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            int newTight = tight & (d == limit);
            if ((mask == 0) && (d == 0)) { // leading zeros
                ans += fun(idx + 1, false, repeat, mask, s);
            } else if (mask & (1 << d)) { // repeated
                ans += fun(idx + 1, newTight, true, mask, s);
            } else {
                ans += fun(idx + 1, newTight, repeat, mask | (1 << d), s);
            }
        }
        return dp[idx][tight][repeat][mask] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return fun(0, 1, 0, 0, s);
    }
};