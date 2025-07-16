class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int o = 0, e = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1)
                o++;
            else
                e++;
        }
        int ans = max(o, e);
        map<int, int> m;
        vector<int> dp(n, 1);
        m[nums[0] % 2] = dp[0];
        for (int i = 1; i < n; i++) {
            if (m.find(1 - nums[i] % 2) != m.end()) {
                dp[i] += m[1 - nums[i] % 2];
                m[nums[i] % 2] = dp[i];
            } else {
                m[nums[i] % 2] = dp[i];
            }
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};