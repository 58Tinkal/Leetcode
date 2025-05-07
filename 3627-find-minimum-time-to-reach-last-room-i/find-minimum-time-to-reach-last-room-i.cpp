class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q; //{t,{r,c}}
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        q.push({0, {0, 0}});
        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int time = it.first;
            int r = it.second.first, c = it.second.second;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int d = max(time, moveTime[nr][nc]) + 1;
                    if (d < dist[nr][nc]) {
                        dist[nr][nc] = d;
                        q.push({d, {nr, nc}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};