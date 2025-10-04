class Solution {
public:
    const static int FULL = (1 << 30) - 1;  // 30-bit mask since nums[i] ≤ 1e9

    int build(vector<int>& nums, int mask) {
        vector<int> basis(31, 0);
        for (auto it : nums) {
            it &= mask; // restrict to allowed bits
            for (int i = 30; i >= 0; i--) {
                if ((it >> i) & 1) {
                    if (basis[i] == 0) {
                        basis[i] = it;
                        break;
                    }
                    it ^= basis[i];
                }
            }
        }

        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            if (((ans ^ basis[i]) & mask) > (ans & mask))
                ans ^= basis[i];
        }
        return ans;
    }

    long long maximizeXorAndXor(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;

        for (int mask = 0; mask < (1 << n); mask++) {
            int B = -1;
            int s = 0;
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (B == -1) B = nums[i];
                    else B &= nums[i];
                } else {
                    s ^= nums[i];
                    subset.push_back(nums[i]);
                }
            }

            if (B == -1) B = 0;
            int allXorInv = (~s) & FULL;

            // Corrected: basis is built under the restricted bit mask
            int x = build(subset, allXorInv);

            long long res = (long long)B + s + 2LL * (x & allXorInv);
            ans = max(ans, res);
        }
        return ans;
    }
};
