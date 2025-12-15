class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        int n = a.size();
        long long ans = 0;
        long long c = 1;
        for (int i = 1; i < n; i++) {
                ans += c;
            if (a[i] == a[i - 1] - 1) {
                c++;
            } else {
                c = 1;
            }
        }
            ans += c;
        return ans;
    }
};