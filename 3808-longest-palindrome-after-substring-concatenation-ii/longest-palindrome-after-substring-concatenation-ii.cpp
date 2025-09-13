class Solution {
private:
    int dp[1001][1001];
    int dp2[1001][1001][2];
    vector<int> st, en;

private:
    vector<int> longestPalStartLengths(const string& s) {
        int n = (int)s.size();
        if (n == 0)
            return {};

        vector<int> lens(n, 1);

        for (int center = 0; center < n; ++center) {
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > lens[l])
                    lens[l] = len;
                --l;
                ++r;
            }

            l = center;
            r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > lens[l])
                    lens[l] = len;
                --l;
                ++r;
            }
        }

        return lens;
    }
    vector<int> longestPalEndLengths(const string& s) {
        int n = (int)s.size();
        if (n == 0)
            return {};

        vector<int> lens_end(n, 1);

        for (int center = 0; center < n; ++center) {
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > lens_end[r])
                    lens_end[r] = len;
                --l;
                ++r;
            }

            l = center;
            r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > lens_end[r])
                    lens_end[r] = len;
                --l;
                ++r;
            }
        }

        return lens_end;
    }

private:
    int solve(int i, int j, bool start, string& s, string& t) {

        if (i == s.size() && j < 0) {
            return 0;
        }

        if (j < 0) {
            return st[i];
        }

        if (i == s.size()) {
            return en[j];
        }
        if (dp2[i][j][start] != -1) {
            return dp2[i][j][start];
        }

        int ans = 0;
        if (start == 0) {
            ans = max(ans, solve(i + 1, j, start, s, t));
            ans = max(ans, solve(i, j - 1, start, s, t));
        }
        if (s[i] == t[j]) {
            ans = max(ans, 2 + solve(i + 1, j - 1, 1, s, t));
        }

        if (start == 1) {
            ans = max(ans, st[i]);
            ans = max(ans, en[j]);
        }
        return dp2[i][j][start] = ans;
    }

private:
    int lcs(string& s) {
        int ans = 1;
        string t = s;
        reverse(t.begin(), t.end());

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }

public:
    int longestPalindrome(string s, string t) {
        int end = t.size() - 1;
        memset(dp, 0, sizeof(dp));
        int ans = lcs(s);
        memset(dp, 0, sizeof(dp));
        ans = max(ans, lcs(t));
        st = longestPalStartLengths(s);
        en = longestPalEndLengths(t);
        memset(dp2, -1, sizeof(dp2));
        ans = max(ans, solve(0, end, 0, s, t));
        return ans;
    }
};