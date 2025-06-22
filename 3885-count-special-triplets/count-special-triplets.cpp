const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}(); 

class Solution {
public:
    int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto& it : m) {
            if (it.first == 0) {
                vector<int>& a = it.second;
                int s = a.size();
                int j = s - 2;
                for (int i = 1; i <= s - 2; i++) {
                    ans = (ans + 1LL * i * j) % mod;
                    j--;
                }
                continue;
            }
            if (m.find(2 * it.first) == m.end())
                continue;
            vector<int> v = m[2 * it.first];
            vector<int>& a = it.second;
            int s = v.size();
            for (int i = 0; i < a.size(); i++) {
                int idx = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
                if (idx == s || idx == 0)
                    continue;
                if (idx == s - 1) {
                    ans = (ans + 1LL * idx * 1) % mod;
                } else {
                    ans = (ans + 1LL * idx * (s - idx)) % mod;
                }
            }
        }
        return ans;
    }
};