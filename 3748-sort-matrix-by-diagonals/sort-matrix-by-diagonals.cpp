class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

    for (int i = 0; i < n; i++) {
        vector<int> diagonal;
        int row = i, col = 0;
        while (row < n && col < n) {
            diagonal.push_back(grid[row][col]);
            row++;
            col++;
        }
        sort(diagonal.rbegin(), diagonal.rend()); 
        row = i, col = 0;
        int idx = 0;
        while (row < n && col < n) {
            grid[row][col] = diagonal[idx++];
            row++;
            col++;
        }
    }

  
    for (int j = 1; j < n; j++) {
        vector<int> diagonal;
        int row = 0, col = j;
        while (row < n && col < n) {
            diagonal.push_back(grid[row][col]);
            row++;
            col++;
        }
        sort(diagonal.begin(), diagonal.end()); 
        row = 0, col = j;
        int idx = 0;
        while (row < n && col < n) {
            grid[row][col] = diagonal[idx++];
            row++;
            col++;
        }
    }

    return grid;
    }
};