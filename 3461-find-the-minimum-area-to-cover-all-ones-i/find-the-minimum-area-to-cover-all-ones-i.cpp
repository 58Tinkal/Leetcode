class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int h1 = n, h2 = -1, b1 = m, b2 = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1] == 1) {
                    h1 = min(h1, i);
                    h2 = max(h2, i);
                    b1 = min(b1, j);
                    b2 = max(b2, j);
                }
            }
        }
        return (h2 - h1 + 1) * (b2 - b1 + 1);
    }
};