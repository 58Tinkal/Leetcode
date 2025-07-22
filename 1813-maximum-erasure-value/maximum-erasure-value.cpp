class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int s = 0, e = 0;
        int n = nums.size();
        map<int, int> m;
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i-1];
        }

        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (m.find(nums[i]) != m.end() && m[nums[i]] >= e) {
                int idx = m[nums[i]];
                s = idx;
                ans = max(ans, sum);
                sum -= (pre[idx + 1] - pre[e]);
                e = idx + 1;
                sum += nums[i];
                m[nums[i]] = i;
            } else {
                m[nums[i]] = i;
                sum += nums[i];
            }
        }
        ans = max(ans, sum);

        return ans;
    }
};