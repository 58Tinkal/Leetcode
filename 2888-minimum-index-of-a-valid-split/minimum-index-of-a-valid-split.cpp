class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int x = nums[0];
        int f = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != x)
                f--;
            else
                f++;
            if (f == 0) {
                x = nums[i];
                f = 1;
            }
        }
        f = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                f++;
            }
        }
        int p = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == x) {
                p++;
                f--;
            }
            if (p > (i + 1) / 2 && f > (n - i - 1) / 2) {
                return i;
            }
        }
        return -1;
    }
};