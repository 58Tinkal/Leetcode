class Solution {
public:
    int ans = 0;
    vector<bool> vis;

    void solve(int pos, int n) {
        if (pos > n) {
            ans++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i] && (i % pos == 0 || pos % i == 0)) {

                vis[i] = true;
                solve(pos + 1, n);
                vis[i] = false;
            }
        }
    }

    int countArrangement(int n) {
        vis.assign(n + 1, false);
        solve(1, n);
        return ans;
    }
};
