class Solution {
public:
    bool solve(int i, vector<string>& wordDict, vector<int>& dp, string& s) {
        if (i < 0) {
            return true;
        }
        if (dp[i] != -1) {
            return dp[i] == 1;
        }
        for (auto it : wordDict) {
            int sz = it.size();
            if (i - sz + 1 < 0) {
                continue;
            }
            if (s.substr(i - sz + 1, sz) == it &&
                solve(i - sz, wordDict, dp, s)) {
                dp[i] = 1;
                return true;
            }
        }
        dp[i] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solve(s.size() - 1, wordDict, dp, s);
    }
};