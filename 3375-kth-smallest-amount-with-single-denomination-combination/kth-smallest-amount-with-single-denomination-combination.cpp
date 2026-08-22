class Solution {
public:
    long long countLeftSmallest(long long mid, vector<int>& c) {
        long long count = 0;
        int n = c.size();

        for (int mask = 1; mask < (1 << n); mask++) {
            int bit_cnt = 0;
            long long lcm = 1;

            int i = mask;
            int j = 0;

            while (i > 0) {
                if (i % 2 == 1) {
                    lcm = (lcm * c[j]) / __gcd(lcm, (long long)c[j]);
                    bit_cnt++;
                }

                i /= 2;
                j++;
            }

            if (bit_cnt % 2 == 0) {
                count -= mid / lcm;
            } else {
                count += mid / lcm;
            }
        }

        return count;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        if (coins[0] == 1)
            return k;
        vector<int> c;
        long long l = 1, h = coins[coins.size() - 1] * 1LL * k;
        for (int x : coins) {
            bool skip = false;

            for (int y : c) {
                if (x % y == 0) {
                    skip = true;
                    break;
                }
            }

            if (!skip) {
                c.push_back(x);
            }
        }
        for (auto it : c)
            cout << it << ' ';
        long long ans = -1;
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (countLeftSmallest(mid, c) >= k) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};