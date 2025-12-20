class Solution {
public:
    int ans = 0;

    void solve(int pos, int n, int mask) {
        if (pos > n) {
            ans++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!(mask & (1 << i)) && (i % pos == 0 || pos % i == 0)) {

                solve(pos + 1, n, mask | (1 << i));
            }
        }
    }

    int countArrangement(int n) {
        solve(1, n, 0);
        return ans;
    }
};
