class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mx = 0, mn = 0, cur = 0;
        for (auto it : differences) {
            cur += it;
            mn = min(mn, cur);
            mx = max(mx, cur);
        }
        if ((upper - lower) < (mx - mn))
            return 0;
        return (upper - lower) - (mx - mn) + 1;
    }
};