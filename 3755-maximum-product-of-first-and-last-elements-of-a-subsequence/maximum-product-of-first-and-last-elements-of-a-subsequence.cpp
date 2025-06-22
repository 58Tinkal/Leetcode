class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        long long ans = -1e12;
        if (m == n) {
            ans = 1LL * nums[0] * nums[n - 1];
            return ans;
        }
        vector<int> maxi(n), mini(n);
        maxi[0] = nums[0];
        mini[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxi[i] = max(nums[i], maxi[i - 1]);
            mini[i] = min(nums[i], mini[i - 1]);
        }
        for (int i = n - 1; i >= m - 1; i--) {
            if (nums[i] < 0) {
                ans = max(ans, 1LL * nums[i] * mini[i - m + 1]);
            } else {
                ans = max(ans, 1LL * nums[i] * maxi[i - m + 1]);
            }
        }
        return ans;
    }
};