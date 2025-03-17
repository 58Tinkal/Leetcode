class Solution {
public:
    // digit * tight * evenCnt * oddCnt * rem_When_div_by_K * validNum(for
    // leading zero)
    int dp[10][2][6][6][20][2];
    int solve(int idx, int tight, int evenCnt, int oddCnt, int rem, int valid,
              int k, string& s) {
        int n = s.size();
        if (idx >= n) {
            return (evenCnt == oddCnt) && (rem == 0);
        }
        if (oddCnt > 5 || evenCnt > 5)
            return 0;

        if (dp[idx][tight][evenCnt][oddCnt][rem][valid] != -1)
            return dp[idx][tight][evenCnt][oddCnt][rem][valid];

        int ans = 0;
        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            int newTight = tight & (d == limit);
            if (valid == false && d == 0) {
                ans +=
                    solve(idx + 1, newTight, evenCnt, oddCnt, rem, false, k, s);
            } else if (d % 2 == 0) {
                ans += solve(idx + 1, newTight, evenCnt + 1, oddCnt,
                             (rem * 10 + d) % k, true, k, s);
            } else {
                ans += solve(idx + 1, newTight, evenCnt, oddCnt + 1,
                             (rem * 10 + d) % k, true, k, s);
            }
        }

        return dp[idx][tight][evenCnt][oddCnt][rem][valid] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {

        memset(dp, -1, sizeof(dp));
        string l = to_string(low - 1);
        int x = solve(0, 1, 0, 0, 0, 0, k, l);
        memset(dp, -1, sizeof(dp));
        string h = to_string(high);
        int y = solve(0, 1, 0, 0, 0, 0, k, h);

        return y - x;
    }
};