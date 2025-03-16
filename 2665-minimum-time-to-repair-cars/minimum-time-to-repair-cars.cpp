class Solution {
public:
    bool fun(vector<int>& ranks, int cars, long long m) {
        long long s = -1e9;
        int x = cars;
        for (int i = 0; i < ranks.size(); i++) {
            long long p = sqrt(m / ranks[i]);
            x -= p;
            s = max(s, p * p * ranks[i]);
            if (x <= 0 && s <= m)
                return true;
        }
        return (x <= 0 && s <= m);
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        sort(ranks.begin(), ranks.end());
        long long l = 1;
        long long h = (long long)cars * cars * ranks[n - 1];
        long long ans = h;
        while (l <= h) {
            long long m = l + (h - l) / 2;
            if (fun(ranks, cars, m)) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};