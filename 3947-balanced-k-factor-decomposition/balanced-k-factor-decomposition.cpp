class Solution {
private:
    vector<int> div;
    vector<int> ans;
    int val = 1e9;

private:
    void solve(int n, int k, int last, vector<int>& cur) {

        if (k == 0) {
            int x = cur[cur.size() - 1] - cur[0];
            if (x <= val) {
                x = val;
                ans = cur;
            }
            return;
        }

        if (k == 1) {
            if (n < last)
                return;
            cur.push_back(n);
            solve(1, 0, n, cur);
            cur.pop_back();
        }

        int idx = lower_bound(div.begin(), div.end(), last) - div.begin();
        for (int i = idx; i < div.size(); i++) {
            if (n % div[i] != 0)
                continue;
            cur.push_back(div[i]);
            solve(n / div[i], k - 1, div[i], cur);
            cur.pop_back();
        }
    }

public:
    vector<int> minDifference(int n, int k) {

        for (int i = 1; i * i <= n; i++) {
            if (i * i == n) {
                div.push_back(i);
                continue;
            }
            if (n % i == 0) {
                div.push_back(i);
                div.push_back(n / i);
            }
        }
        sort(div.begin(), div.end());
        vector<int> cur = {};
        solve(n, k, 0, cur);
        return ans;
    }
};