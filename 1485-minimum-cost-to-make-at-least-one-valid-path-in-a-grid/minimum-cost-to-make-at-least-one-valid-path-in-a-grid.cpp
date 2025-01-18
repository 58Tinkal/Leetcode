class Solution {
public:
    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int cost = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (vis[r][c] == true)
                continue;
            if (r == m - 1 && c == n - 1)
                return cost;
            vis[r][c] = true;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (isValid(nr, nc, m, n) && !vis[nr][nc]) {
                    int newCost = cost;
                    newCost += (i + 1) == grid[r][c] ? 0 : 1;
                    pq.push({newCost, {nr, nc}});
                }
            }
        }
        return 0;
    }
};