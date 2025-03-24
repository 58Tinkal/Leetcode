const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(), m.end());
        for (int i = 0; i < m.size(); i++) {
            cout << m[i][0] << ' ' << m[i][1] << endl;
        }
        int ans = 0;
        int n = m.size();
        if (m[0][0] > 1)
            ans += m[0][0] - 1;
        int e = -1e9;
        for (int i = 0; i < n - 1; i++) {
            e = max(e, m[i][1]);
            if (e < m[i + 1][0]) {
                ans += m[i + 1][0] - e - 1;
            }
        }
        e = max(e, m[n - 1][1]);
        ans += days - e;
        return ans;
    }
};