class Solution {
private:
    int minArea(int startRow, int endRow, int startCol, int endCol,
                vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int h1 = n, h2 = -1, b1 = m, b2 = -1;
        for (int i = startRow; i < endRow; i++) {
            for (int j = startCol; j < endCol; j++) {
                if (grid[i][j] == 1) {
                    h1 = min(h1, i);
                    h2 = max(h2, i);
                    b1 = min(b1, j);
                    b2 = max(b2, j);
                }
            }
        }
        return (h2 - h1 + 1) * (b2 - b1 + 1);
    }

private:
    int solve(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MAX;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                int top = minArea(0, i, 0, n, grid);
                int bottomLeft = minArea(i, m, 0, j, grid);
                int bottomRight = minArea(i, m, j, n, grid);
                ans = min(ans, top + bottomLeft + bottomRight);

                int topLeft = minArea(0, i, 0, j, grid);
                int topRight = minArea(0, i, j, n, grid);
                int bottom = minArea(i, m, 0, n, grid);
                ans = min(ans, topLeft + topRight + bottom);
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int top = minArea(0, i, 0, n, grid);
                int mid = minArea(i, j, 0, n, grid);
                int bottom = minArea(j, m, 0, n, grid);
                ans = min(ans, top + mid + bottom);
            }
        }
        return ans;
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        int ans = solve(grid);
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> gridRotate(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                gridRotate[j][m - i - 1] = grid[i][j];
            }
        }
        ans = min(ans, solve(gridRotate));
        return ans;
    }
};