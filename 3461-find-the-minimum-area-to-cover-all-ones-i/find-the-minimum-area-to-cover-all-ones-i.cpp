class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int h1 = -1, h2 = -1, b1 = -1, b2 = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1] == 1) {
                    if (h1 == -1) {
                        h1 = i;
                    }
                    h2 = i;
                }
            }
        }
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                if (grid[i - 1][j - 1] == 1) {
                    if (b1 == -1) {
                        b1 = j;
                    }
                    b2 = j;
                }
            }
        }
        int h = h2 - h1 + 1;
        int b = b2 - b1 + 1;
        return h * b;
    }
};