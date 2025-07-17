class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = INT_MIN;
        vector<vector<int>> dp(k, vector<int>(k));
        for (int i = 0; i < n; i++) {
            int cur = nums[i] % k;
            for (int prev = 0; prev < k; prev++) {
                dp[cur][prev] = dp[prev][cur] + 1;
                ans = max(ans, dp[cur][prev]);
            }
        }
        return ans;
    }
};