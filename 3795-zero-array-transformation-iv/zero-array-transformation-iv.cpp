class Solution {
public:
    bool fun(vector<int>& nums, vector<vector<int>>& q, int m) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            vector<bool> dp(v + 1, false);
            dp[0] = true;
            for (int j = 0; j < m; j++) {
                if (i < q[j][0] || i > q[j][1])
                    continue;
                for (int k = v; k >= q[j][2]; k--) {
                    dp[k] = dp[k] || dp[k - q[j][2]];
                }
            }
            if (!dp[v])
                return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int totalQueries = q.size();
        int l = 0, h = totalQueries, ans = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (fun(nums, q, m)) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
