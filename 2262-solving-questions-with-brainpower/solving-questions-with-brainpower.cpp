class Solution {
public:
    int n;
    long long solve(int idx, vector<long long>& dp, vector<vector<int>>& q) {
        int n = q.size();

        if (idx >= n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        long long take = q[idx][0] + solve(idx + q[idx][1] + 1, dp, q);
        long long notTake = solve(idx + 1, dp, q);
        return dp[idx] = max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& q) {
        n = q.size();
        vector<long long> dp(n + 1, -1);
        return solve(0, dp, q);
    }
};