class Solution {
public:
    int dp[105][105];
    bool solve(int idx, int c, string& s) {
        if (c < 0)
            return false;
        if (idx == s.size()) {
            if (c == 0)
                return true;
            return false;
        }
        if (dp[idx][c] != -1)
            return dp[idx][c];
        if (s[idx] == '(')
            return dp[idx][c] = solve(idx + 1, c + 1, s);
        if (s[idx] == ')')
            return dp[idx][c] = solve(idx + 1, c - 1, s);
        return dp[idx][c] = solve(idx + 1, c + 1, s) or
                            solve(idx + 1, c - 1, s) or solve(idx + 1, c, s);
    }
    bool checkValidString(string s) {
        int n = s.size();
        int c = 0;
        memset(dp, -1, sizeof(dp));
        return solve(0, c, s);
    }
};