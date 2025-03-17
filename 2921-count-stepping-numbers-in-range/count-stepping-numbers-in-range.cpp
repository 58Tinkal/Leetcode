#define mod 1000000007
class Solution {
public:
    // no of digit * tight * adjcent digit * valid(forleading zero)
    int dp[101][2][10][2];

    int solve(int idx, bool tight, int prev, bool valid, string& s) {

        if (idx >= s.size()) {
            if (valid)
                return true;
            return 0;
        }

        if (dp[idx][tight][prev][valid] != -1)
            return dp[idx][tight][prev][valid];

        int ans = 0;
        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            int newTight = tight & (d == limit);
            if (valid == false && d == 0) {
                ans = (ans + solve(idx + 1, newTight, prev, false, s)) % mod;
            } else if (valid == false && d > 0) {
                ans = (ans + solve(idx + 1, newTight, d, true, s)) % mod;
            } else if (abs(prev - d) == 1) {
                ans = (ans + solve(idx + 1, newTight, d, true, s)) % mod;
            }
        }
        return dp[idx][tight][prev][valid] = ans;
    }
    int countSteppingNumbers(string low, string high) {

        memset(dp, -1, sizeof(dp));
        int x = solve(0, 1, 0, 0, low);

        int i = 1;
        for (; i < low.size(); i++) {
            if (abs((low[i] - '0') - (low[i - 1] - '0')) != 1) {
                break;
            }
        }
        if (i == low.size())
            x--;

        memset(dp, -1, sizeof(dp));
        int y = solve(0, 1, 0, 0, high);

        return (y - x + mod)%mod;
    }
};