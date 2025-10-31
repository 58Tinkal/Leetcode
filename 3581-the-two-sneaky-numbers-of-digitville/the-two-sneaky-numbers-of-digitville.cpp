class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& v) {
        int xr = 0;
        int m = v.size();
        int n = v.size() - 2;

        for (int i = 0; i < m; i++) {
            xr = xr ^ v[i];
        }

        for (int i = 0; i < n; i++) {
            xr = xr ^ i;
        }

        int right = xr & ~(xr - 1);

        int t1 = 0;
        int t2 = 0;

        for (int i = 0; i < m; i++) {
            if (v[i] & right) {
                t1 = t1 ^ v[i];
            } else {
                t2 = t2 ^ v[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (i & right) {
                t1 = t1 ^ i;
            } else
                t2 = t2 ^ i;
        }

        return {t1, t2};
    }
};