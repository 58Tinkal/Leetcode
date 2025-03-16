#define ll long long int
#define mod 1000000007
class Solution {
public:
    ll dp[23][2][211];
    ll solve(ll idx, ll tight, ll sum, int min_sum, int max_sum, string& s) {

        if (idx >= s.size()) {
            return sum >= min_sum && sum <= max_sum;
        }

        if (dp[idx][tight][sum] != -1)
            return dp[idx][tight][sum];

        ll ans = 0;
        ll limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            ll newTight = tight & (d == limit);
            ans =
                (ans + solve(idx + 1, newTight, sum + d, min_sum, max_sum, s)) %
                mod;
        }
        return dp[idx][tight][sum] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        ll x = solve(0, true, 0, min_sum, max_sum, num1);
        memset(dp, -1, sizeof(dp));
        ll y = solve(0, true, 0, min_sum, max_sum, num2);
        int a = 0;
        for (auto& d : num1)
            a += (d - '0');

        if (a >= min_sum && a <= max_sum)
            x--;

        return (((y - x) % mod) + mod) % mod;
    }
};