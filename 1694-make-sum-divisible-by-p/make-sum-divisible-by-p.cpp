class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int ans = 0;
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        unordered_map<long long, int> m;
        m[0] = 0;
        int target = sum % p;
        if (target == 0) {
            return ans;
        }
        ans = nums.size();
        long long prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int cur = prefix % p;
            int need = (cur - target + p) % p;
            if (m.find(need) != m.end()) {
                ans = min(ans, i + 1 - m[need]);
            }
            m[cur] = i + 1;
        }
        if (ans == nums.size()) {
            return -1;
        }
        return ans;
    }
};