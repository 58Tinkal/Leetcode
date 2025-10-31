class Solution {
public:
    int dp[155][155];
    int mod = 1e9 + 7;
    int solve(int r, int current_gcd, vector<vector<int>>& mat) {
        if (r == mat.size()) {
            if (current_gcd == 1)
                return 1;
            return 0;
        }
        if (dp[r][current_gcd] != -1) {
            return dp[r][current_gcd];
        }
        int x = 0;
        for (int i = 0; i < mat[r].size(); i++) {
            int y = __gcd(current_gcd, mat[r][i]);
            x = (x + solve(r + 1, y, mat)) % mod;
        }
        return dp[r][current_gcd] = x;
    }
    int countCoprime(vector<vector<int>>& mat) {
        int gcd = 0;
        memset(dp, -1, sizeof(dp));
        return solve(0, gcd, mat);
    }
};