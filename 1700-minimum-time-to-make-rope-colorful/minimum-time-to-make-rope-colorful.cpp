class Solution {
public:
    int minCost(string colors, vector<int>& a) {
        int n = colors.size();
        int ans = 0;
        int s = a[0], mx = a[0];
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                mx = max(mx, a[i]);
                s += a[i];
            } else {
                ans += s - mx;
                s = a[i];
                mx = a[i];
            }
        }
        ans += s - mx;
        return ans;
    }
};