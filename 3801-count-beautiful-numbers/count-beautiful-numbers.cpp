#define ll long long int
class Solution {
public:
    unordered_map<string, int> dp;
    string get_state_string(int idx, int tight, int sum, int product) {
        return to_string(idx) + "." + to_string(tight) + "." + to_string(sum) +
               "." + to_string(product);
    }
    ll solve(ll idx, ll tight, ll sum, ll product, string& s) {
        if (idx >= s.size()) {
            return (sum > 0 && product % sum == 0) ? 1 : 0;
        }
        string state = get_state_string(idx, tight, sum, product);
        if (dp.contains(state))
            return dp[state];

        ll ans = 0;
        ll limit = tight ? (s[idx] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            ll newTight = tight & (d == limit);
            ll newProd = d * (sum ? product : 1);
            ans += solve(idx + 1, newTight, sum + d, newProd, s);
        }

        return dp[state] = ans;
    }

    ll fun(ll n) {
        if (n == 0)
            return 0;
        dp.clear();
        string s = to_string(n);
        return solve(0, 1, 0, 1, s);
    }

    int beautifulNumbers(int l, int r) { return fun(r) - fun(l - 1); }
};
