class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> p(n), s(n);

        p[0] = true;
        for (int i = 1; i < n; i++)
            p[i] = p[i - 1] && (nums[i] > nums[i - 1]);

        s[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
            s[i] = s[i + 1] && (nums[i] > nums[i + 1]);

        vector<long long> a(n);
        a[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            a[i] = nums[i] + a[i + 1];

        long long ans = LLONG_MAX;
        long long sum = 0;

        for (int i = 0; i < n - 1; i++) {
            sum += nums[i];
            if (p[i] && s[i + 1]) {
                ans = min(ans, llabs(sum - a[i + 1]));
            }
        }

        return (ans == LLONG_MAX) ? -1 : ans;
    }
};
