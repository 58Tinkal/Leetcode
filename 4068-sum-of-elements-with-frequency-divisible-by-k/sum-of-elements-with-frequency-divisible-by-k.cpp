class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(101, 0);
        for (auto it : nums) {
            f[it]++;
        }
        int ans = 0;
        for (int i = 1; i < 101; i++) {
            if (f[i] % k == 0) {
                ans += i * f[i];
            }
        }
        return ans;
    }
};