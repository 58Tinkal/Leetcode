class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    ll C[1005][1005];

    void buildPascal() {
        for (int i = 0; i < 1005; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
    }

    ll solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        ll x = solve(left) % MOD;
        ll y = solve(right) % MOD;
        ll z = C[n - 1][left.size()];
        return ((x * y) % MOD * z) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        buildPascal();
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
