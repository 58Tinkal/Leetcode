class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dif = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == n - 1 && c == m - 1)
                return dif;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int newDif = max(abs(heights[nr][nc] - heights[r][c]), dif);
                    if (newDif < dist[nr][nc]) {
                        dist[nr][nc] = newDif;
                        pq.push({newDif, {nr, nc}});
                    }
                }
            }
        }
        return 1e9;
    }
};