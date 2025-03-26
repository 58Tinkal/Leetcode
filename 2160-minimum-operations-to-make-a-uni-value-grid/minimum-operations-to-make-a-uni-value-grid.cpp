class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                a.push_back(grid[i][j]);
            }
        }
        sort(a.begin(), a.end());
        int y = a[0] % x;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] % x != y)
                return -1;
        }
        int n = a.size();
        y = a[n / 2];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != y) {
                ans += abs(y - a[i]) / x;
            }
        }
        return ans;
    }
};