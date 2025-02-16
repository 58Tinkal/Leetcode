class Solution {
public:
    long long maxWeight(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        int x = n / 4;
        long long res = 0;
        int p = ceil(x / 2.0);

        for (int i = 0; i < p; i++) {
            res += a[i];
        }

        int m = x / 2;
        for (int i = p + 1; i < n && m > 0; i += 2) {
            res += a[i];
            m--;
        }

        return res;
    }
};
