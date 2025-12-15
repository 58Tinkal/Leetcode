class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        int n = a.size();
        long long ans = n;
        long long c = 1;
        for (int i = 1; i < n; i++) {
            if (c != 1)
                ans += c - 1;
            if (a[i] == a[i - 1] - 1) {
                c++;
            } else {
                c = 1;
            }
        }
        if (c != 1)
            ans += c - 1;
        return ans;
    }
};