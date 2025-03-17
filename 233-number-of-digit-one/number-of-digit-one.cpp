class Solution {
public:
    int dp[10][2][11];
    int solve(int idx, int tight, int cnt, string& s) {
        if (idx >= s.size()) {
            return cnt;
        }
        if (dp[idx][tight][cnt] != -1)
            return dp[idx][tight][cnt];

        int ans = 0;
        int limit = tight ? s[idx] - '0' : 9;
        for (int d = 0; d <= limit; d++) {
            int newTight = tight & (d == limit);
            if (d == 1)
                ans += solve(idx + 1, newTight, cnt + d, s);
            else
                ans += solve(idx + 1, newTight, cnt, s);
        }
        return dp[idx][tight][cnt] = ans;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0, s);
    }
};