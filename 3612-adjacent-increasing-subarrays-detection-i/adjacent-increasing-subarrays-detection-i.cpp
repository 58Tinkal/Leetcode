class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p(n, 0), s(n, 0);
        p[0] = 1;
        int x = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                x++;
            } else {
                x = 1;
            }
            p[i] = x;
        }
        x = 1;
        s[n - 1] = x;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                x++;
            } else
                x = 1;
            s[i] = x;
        }
        for (int i = 0; i < n; i++) {
            cout << p[i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << s[i] << ' ';
        }
        for (int i = 0; i < n - 1; i++) {
            if (p[i] >= k && s[i + 1] >= k) {
                return true;
            }
        }
        return false;
    }
};
// 2, 3, 4, 5
