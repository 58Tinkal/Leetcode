class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n, 0);
        int x = 1;
        s[n - 1] = x;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                x++;
            } else
                x = 1;
            s[i] = x;
        }
        x = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i > 0 && nums[i] > nums[i - 1]) {
                x++;
            } else {
                x = 1;
            }
            if (x >= k && s[i + 1] >= k) {
                return true;
            }
        }
        return false;
    }
};
// 2, 3, 4, 5
