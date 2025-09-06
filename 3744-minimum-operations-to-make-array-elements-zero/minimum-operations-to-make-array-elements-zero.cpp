class Solution {
private:
    long long solve(long long l, long long r) {
        long long L = 1;
        long long S = 1;
        long long res = 0;
        while (L <= r) {
            long long R = 4 * L - 1;
            long long start = max(L, l);
            long long end = min(R, r);

            if (start <= end) {
                res += (end - start + 1) * S;
            }
            S++;
            L = L * 4;
        }
        return res;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& it : queries) {
            long long l = it[0];
            long long r = it[1];

            long long res = solve(l, r);

            ans += (res + 1) / 2;
        }
        return ans;
    }
};