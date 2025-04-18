class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int fun(int idx, vector<int>& nums1, vector<int>& nums2, bool s) {
        if (idx == n)
            return 0;
        if (dp[idx][s] != -1)
            return dp[idx][s];

        int ans = INT_MAX;
        int p1 = nums1[idx - 1];
        int p2 = nums2[idx - 1];
        if (s)
            swap(p1, p2);

        if (nums1[idx] > p1 && nums2[idx] > p2) {
            ans = fun(idx + 1, nums1, nums2, 0);
        }

        if (nums1[idx] > p2 && nums2[idx] > p1) {
            ans = min(ans, 1 + fun(idx + 1, nums1, nums2, 1));
        }

        return dp[idx][s] = ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        n++;
        dp = vector<vector<int>>(n + 1, vector<int>(2, -1));
        return fun(1, nums1, nums2, 0);
    }
};
