class Solution {
public:
    int ans = INT_MAX;
    bool isValid(int m, vector<int>& j, int k, int idx, vector<int>& w) {
        if (idx == j.size())
            return true;
        for (int i = 0; i < k; i++) {
            if (w[i] + j[idx] <= m) {
                w[i] += j[idx];
                if (isValid(m, j, k, idx + 1, w))
                    return true;
                w[i] -= j[idx];
            }
            if (w[i] == 0)
                return false;
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& j, int k) {
        int l = *max_element(j.begin(), j.end());
        int h = accumulate(j.begin(), j.end(), 0);
        while (l <= h) {
            int m = l + (h - l) / 2;
            vector<int> w(k, 0);
            if (isValid(m, j, k, 0, w)) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};