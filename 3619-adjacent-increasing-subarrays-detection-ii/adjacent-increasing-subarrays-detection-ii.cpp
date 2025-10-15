class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n, 0);
        s[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                s[i] = s[i + 1] + 1;
            } else
                s[i] = 1;
        }
        int x = 1;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i > 0 && nums[i] > nums[i - 1]) {
                x++;
            } else {
                x = 1;
            }
            ans = max(ans, min(x, s[i + 1]));
        }
        return ans;
    }
};